#include <chrono>
#include <thread>
#include "ciFove/Context.h"

using namespace cinder::fove;

cinder::fove::Context* Context::create(FoveOpts opts) {
  auto ctx = new Context();

  // headset
  auto pHeadset = Fove::GetFVRHeadset();

  if (CheckError(pHeadset->Initialise(opts.clientCapabilities()), "Initialise")) {
    // return NULL;
  }

  ctx->headsetRef = std::shared_ptr<Fove::IFVRHeadset>(pHeadset);


  // Connect to compositor
  auto pCompositor = Fove::GetFVRCompositor();

  if (pCompositor) {
    ctx->compositorRef = std::shared_ptr<Fove::IFVRCompositor>(pCompositor);
  } else {
    std::cerr << "[ciFove] Could not get compositor" << std::endl;
  }

  return ctx;
}

void Context::renderMono(std::function<void(Fove::SFVR_Pose&)> drawFunc) {
  if (!compositorRef) return;
  if (!compositorLayerRef) compositorLayerRef = createCompositorLayerRef();
  if (!compositorLayerRef) return;
  // TODO; fbo

  // Wait for the compositor to tell us to render
  // This allows the compositor to limit our frame rate to what's appropriate for the HMD display
  // We move directly on to rendering after this, the update phase happens before hand
  // This is to ensure the quickest possible turnaround time from being signaled to presenting a frame,
  // such that we reduce the risk of missing a frame due to time spent during update
  Fove::SFVR_Pose pose;

  // max 3 failures
  for (int i=0; i<3; i++) {
    // wait for wait for render pos (this lets the HMD determine the framerate)
    if (!CheckError(compositorRef->WaitForRenderPose(&pose), "WaitForRenderPose")) {
      drawFunc(pose);
      return;
    }

    // If there was an error waiting, it's possible that WaitForRenderPose returned immediately
    // Sleep a little bit to prevent us from rendering at maximum framerate and eating massive resources/battery

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}


void Context::renderMono(std::function<GLuint(Fove::SFVR_Pose&)> drawFunc) {
  if (!compositorRef) return;
  if (!compositorLayerRef) compositorLayerRef = createCompositorLayerRef();
  if (!compositorLayerRef) return;
  // TODO; fbo

  // Wait for the compositor to tell us to render
  // This allows the compositor to limit our frame rate to what's appropriate for the HMD display
  // We move directly on to rendering after this, the update phase happens before hand
  // This is to ensure the quickest possible turnaround time from being signaled to presenting a frame,
  // such that we reduce the risk of missing a frame due to time spent during update
  Fove::SFVR_Pose pose;

  // max 3 failures
  for (int i=0; i<3; i++) {
    // wait for wait for render pos (this lets the HMD determine the framerate)
    if (!CheckError(compositorRef->WaitForRenderPose(&pose), "WaitForRenderPose")) {
      auto texId = drawFunc(pose);

      Context::submitFrame(
        *this->compositorRef,
        texId,
        this->compositorLayerRef->layerId,
        pose,
        this->boundsMono
      );

      return;
    }

    // If there was an error waiting, it's possible that WaitForRenderPose returned immediately
    // Sleep a little bit to prevent us from rendering at maximum framerate and eating massive resources/battery

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

void Context::renderStereo(std::function<void(Fove::EFVR_Eye, Fove::SFVR_Pose&)> drawFunc) {
  if (!compositorRef) return;
  if (!compositorLayerRef) compositorLayerRef = createCompositorLayerRef();
  if (!compositorLayerRef) return;
  // TODO; fbo

  // Wait for the compositor to tell us to render
  // This allows the compositor to limit our frame rate to what's appropriate for the HMD display
  // We move directly on to rendering after this, the update phase happens before hand
  // This is to ensure the quickest possible turnaround time from being signaled to presenting a frame,
  // such that we reduce the risk of missing a frame due to time spent during update
  Fove::SFVR_Pose pose;

  // max 3 failures
  for (int i=0; i<3; i++) {
    // wait for wait for render pos (this lets the HMD determine the framerate)
    if (!CheckError(compositorRef->WaitForRenderPose(&pose), "WaitForRenderPose")) {

      drawFunc(Fove::EFVR_Eye::Left, pose);
      drawFunc(Fove::EFVR_Eye::Right, pose);
      return;
    }

    // If there was an error waiting, it's possible that WaitForRenderPose returned immediately
    // Sleep a little bit to prevent us from rendering at maximum framerate and eating massive resources/battery

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

/// Draw the given texture to both eyes
void Context::submitFrameMono(GLuint texId) {
  if (!this->compositorRef) return;
  if (!compositorLayerRef) compositorLayerRef = createCompositorLayerRef();
  if (!compositorLayerRef) return;

  // Wait for the compositor to tell us to render
  // This allows the compositor to limit our frame rate to what's appropriate for the HMD display
  // We move directly on to rendering after this, the update phase happens before hand
  // This is to ensure the quickest possible turnaround time from being signaled to presenting a frame,
  // such that we reduce the risk of missing a frame due to time spent during update
  Fove::SFVR_Pose pose;
  if (CheckError(compositorRef->WaitForRenderPose(&pose), "WaitForRenderPose")) {
    // If there was an error waiting, it's possible that WaitForRenderPose returned immediately
    // Sleep a little bit to prevent us from rendering at maximum framerate and eating massive resources/battery

    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return;
  }

  Context::submitFrame(
    *this->compositorRef,
    texId,
    this->compositorLayerRef->layerId,
    pose,
    this->boundsMono
  );
}

/// Draw left half of the texture to the left eye and the right half to the right eye
void Context::submitFrameStereoLeftRight(GLuint texId) {
  if (!this->compositorRef) return;
  if (!compositorLayerRef) compositorLayerRef = createCompositorLayerRef();
  if (!compositorLayerRef) return;

  // Wait for the compositor to tell us to render
  // This allows the compositor to limit our frame rate to what's appropriate for the HMD display
  // We move directly on to rendering after this, the update phase happens before hand
  // This is to ensure the quickest possible turnaround time from being signaled to presenting a frame,
  // such that we reduce the risk of missing a frame due to time spent during update
  Fove::SFVR_Pose pose;
  if (CheckError(compositorRef->WaitForRenderPose(&pose), "WaitForRenderPose")) {
    // If there was an error waiting, it's possible that WaitForRenderPose returned immediately
    // Sleep a little bit to prevent us from rendering at maximum framerate and eating massive resources/battery

    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return;
  }

  Context::submitFrame(
    *this->compositorRef,
    texId,
    this->compositorLayerRef->layerId,
    pose,
    this->boundsLeftRight
  );
}

/// Draw the the top half of the texture to the left eye and the bottom half to the right eye
void Context::submitFrameStereoTopBottom(GLuint texId) {
  if (!this->compositorRef) return;
  if (!compositorLayerRef) compositorLayerRef = createCompositorLayerRef();
  if (!compositorLayerRef) return;

  // Wait for the compositor to tell us to render
  // This allows the compositor to limit our frame rate to what's appropriate for the HMD display
  // We move directly on to rendering after this, the update phase happens before hand
  // This is to ensure the quickest possible turnaround time from being signaled to presenting a frame,
  // such that we reduce the risk of missing a frame due to time spent during update
  Fove::SFVR_Pose pose;
  if (CheckError(compositorRef->WaitForRenderPose(&pose), "WaitForRenderPose")) {
    // If there was an error waiting, it's possible that WaitForRenderPose returned immediately
    // Sleep a little bit to prevent us from rendering at maximum framerate and eating massive resources/battery

    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return;
  }

  Context::submitFrame(
    *this->compositorRef,
    texId,
    this->compositorLayerRef->layerId,
    pose,
    this->boundsTopBottom
  );
}

std::shared_ptr<Fove::SFVR_CompositorLayer> Context::createCompositorLayerRef() const {
  if (!compositorRef) return nullptr;

  auto layerRef = std::make_shared<Fove::SFVR_CompositorLayer>();

  // TODO; implement support for custom SFVR_CompositorLayerCreateInfo options using FoveOpts
  if (CheckError(compositorRef->CreateLayer(Fove::SFVR_CompositorLayerCreateInfo(), layerRef.get()), "CreateLayer")) {
    return nullptr;
  }

  return layerRef;
}
