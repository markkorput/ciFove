#pragma once

#include <memory>

#include "cinder/gl/gl.h"

#include "FoveTypes.h"
#include "IFVRHeadset.h"
#include "IFVRCompositor.h"

#include "FoveOpts.h"
#include "utils.h"

namespace cinder { namespace fove {

  class Context;
  typedef std::shared_ptr<Context> ContextRef;

  class Context {

  public: // static factory methods

    static Context* create(FoveOpts opts = FoveOpts());

    inline static std::shared_ptr<Context> createRef(FoveOpts opts = FoveOpts()) {
      return std::shared_ptr<Context>(create(opts));
    }

  protected: // constructor is protected; use static factory method (above)
    Context() {}

  public:
    inline const std::shared_ptr<Fove::IFVRHeadset> getHeadset() { return headsetRef; }

    inline ci::ivec2 getEyeResolution() const {
      // get layer
      auto layerRef = this->compositorLayerRef
        ? this->compositorLayerRef
        : createCompositorLayerRef();

      // get res
      auto res = layerRef ? layerRef->idealResolutionPerEye : Fove::SFVR_Vec2i(0,0);
      // convert
      return ci::ivec2(res.x, res.y);
    }

    /// Draw the given texture to both eyes
    inline void submitFrameMono(ci::gl::Fbo& fbo) { this->submitFrameMono(fbo.getId()); }
    void submitFrameMono(GLuint texId);

    /// Draw the given texture to both eyes
    inline void submitFrameStereoLeftRight(ci::gl::Fbo& fbo) { this->submitFrameStereoLeftRight(fbo.getId()); }
    void submitFrameStereoLeftRight(GLuint texId);

    /// Draw the given texture to both eyes
    inline void submitFrameStereoTopBottom(ci::gl::Fbo& fbo) { this->submitFrameStereoTopBottom(fbo.getId()); }
    void submitFrameStereoTopBottom(GLuint texId);

    /// This method can be used to render a mono scene, it will run the drawFunc once.
    /// Afterwards, the caller is responsible for sending the final render results
    /// to the hmd (for eexample using the submitFrameMono method)
    void renderMono(std::function<void(Fove::SFVR_Pose&)> drawFunc);

    /// This method can be used to render a mono scene, it will run the drawFunc once,
    /// and the returned value should be the texture ID of the framebuffer containning
    /// the render results, which be used to immediately submit the frame to the HMD
    void renderMono(std::function<GLuint(Fove::SFVR_Pose&)> drawFunc);

    /// This method can be used to render a stereoscopic 3d scene;
    /// it will run the drawFunc twice; once for each eye.
    /// Afterwards, the caller is responsible for sending the final render results
    /// to the hmd (using the submitFrameMono/submitFrameStereo* methods)
    void renderStereo(std::function<void(Fove::EFVR_Eye eye, Fove::SFVR_Pose&)> drawFunc);

    // /// Convenience method that calls the other renderStereo method,
    // // if the caller doesn't care about the pose
    // inline void renderStereo(std::function<void()> drawFunc) {
    //   this->renderStereo([drawFunc](Fove::EFVR_Eye eye, Fove::SFVR_Pose& pose){
    //     drawFunc();
    //   });
    // }

  protected: // static Fove-interfacing methods

    static inline Fove::EFVR_ErrorCode submitFrame(
      Fove::IFVRCompositor& compositor,
      GLuint texture,
      int layerId,
      const Fove::SFVR_Pose& pose,
      const Fove::SFVR_TextureBounds bounds[]) {

        const Fove::SFVR_GLTexture tex{ texture };

        Fove::SFVR_CompositorLayerSubmitInfo submitInfo;
        submitInfo.layerId = layerId;
        submitInfo.pose = pose;
        submitInfo.left.texInfo = &tex;
        submitInfo.right.texInfo = &tex;
        submitInfo.left.bounds = bounds[0];
        submitInfo.right.bounds = bounds[1];

        // Error ignored, just continue rendering to the window when we're disconnected
        return compositor.Submit(submitInfo);
      }


    std::shared_ptr<Fove::SFVR_CompositorLayer> createCompositorLayerRef() const ;

  private:
    std::shared_ptr<Fove::IFVRHeadset> headsetRef = nullptr;
    std::shared_ptr<Fove::IFVRCompositor> compositorRef = nullptr;
    std::shared_ptr<Fove::SFVR_CompositorLayer> compositorLayerRef = nullptr;

    const Fove::SFVR_TextureBounds boundsMono[2] = {
      Fove::SFVR_TextureBounds{ 0,0,1,1 },
      Fove::SFVR_TextureBounds{ 0,0,1,1 }
    };

    const Fove::SFVR_TextureBounds boundsLeftRight[2] = {
      Fove::SFVR_TextureBounds{ 0,0,0.5f,1 },
      Fove::SFVR_TextureBounds{ 0.5f,0,1,1 }
    };

    const Fove::SFVR_TextureBounds boundsTopBottom[2] = {
      Fove::SFVR_TextureBounds{ 0,0,1,0.5f },
      Fove::SFVR_TextureBounds{ 0,0.5f,1,1 }
    };
  };

}}
