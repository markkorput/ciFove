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

void Context::render(std::function<void()> drawFunc) {
  if (!compositorRef) return;
  if (!compositorLayerRef) compositorLayerRef = createCompositorLayer();
  if (!compositorLayerRef) return;
  // TODO; fbo

  // Wait for the compositor to tell us to render
  // This allows the compositor to limit our frame rate to what's appropriate for the HMD display
  // We move directly on to rendering after this, the update phase happens before hand
  // This is to ensure the quickest possible turnaround time from being signaled to presenting a frame,
  // such that we reduce the risk of missing a frame due to time spent during update
  Fove::SFVR_Pose pose;
  if (CheckError(compositorRef->WaitForRenderPose(&pose), "WaitForRenderPose")) {
    // If there was an error waiting, it's possible that WaitForRenderPose returned immediately
    // Sleep a little bit to prevent us from rendering at maximum framerate and eating massive resources/battery
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  // LEFT
  // TODO: set viewport, set eye camera
  drawFunc();

  // RIGHT
  // TODO: set viewport, set eye camera
  drawFunc();

  // Context::submitFrame(*this->compositorRef,
  //   fboRef->getId(),
  //   this->compositorLayerRef->layerId,
  //   pose);
}

void Context::submitFrame() {
  if (!this->compositorRef) return;

  // Context::submitFrame(*this->compositorRef,
  //   // tex
  //   // layerId
  //   // SFVR_Pose
  // );
}

Fove::EFVR_ErrorCode Context::submitFrame(
  Fove::IFVRCompositor compositor,
  GLuint texture,
  int layerId,
  const Fove::SFVR_Pose& pose) {
  const Fove::SFVR_GLTexture tex{ texture };

  Fove::SFVR_CompositorLayerSubmitInfo submitInfo;
  submitInfo.layerId = layerId;
  submitInfo.pose = pose;
  submitInfo.left.texInfo = &tex;
  submitInfo.right.texInfo = &tex;

  Fove::SFVR_TextureBounds bounds;
  bounds.top = 0;
  bounds.bottom = 1;
  bounds.left = 0;
  bounds.right = 0.5f;
  submitInfo.left.bounds = bounds;
  bounds.left = 0.5f;
  bounds.right = 1;
  submitInfo.right.bounds = bounds;

  // Error ignored, just continue rendering to the window when we're disconnected
  return compositor.Submit(submitInfo);
}

std::shared_ptr<Fove::SFVR_CompositorLayer> Context::createCompositorLayer() {
  return nullptr; //TODO
}
