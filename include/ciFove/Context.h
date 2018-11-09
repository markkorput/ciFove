#include <memory>

#include "cinder/gl/gl.h"

#include "FoveTypes.h"
#include "IFVRHeadset.h"
#include "IFVRCompositor.h"

#include "FoveOpts.h"
#include "utils.h"

namespace cinder { namespace fove {

  class Context {

  public: // static factory methods

    static Context* create(FoveOpts opts = FoveOpts());

    inline static std::shared_ptr<Context> createRef(FoveOpts opts = FoveOpts()) {
      return std::shared_ptr<Context>(create(opts));
    }

  protected: // constructor is protected; use static factory method (above)
    Context(){}

  public:
    inline const std::shared_ptr<Fove::IFVRHeadset> getHeadset() { return headsetRef; }

    inline ci::ivec2 getEyeResolution() const {
      // get layer
      auto layerRef = this->compositorLayerRef
        ? this->compositorLayerRef
        : (this->compositorRef ? createCompositorLayerRef(*compositorRef) : nullptr);

      // get res
      auto res = layerRef ? layerRef->idealResolutionPerEye : Fove::SFVR_Vec2i(0,0);
      // convert
      return ci::ivec2(res.x, res.y);
    }

    /// Draw the given texture to both eyes
    void renderMono(ci::gl::Fbo& fbo);

    void renderStereo(std::function<void()> drawFunc);

  protected: // static Fove-interfacing methods

    static inline Fove::EFVR_ErrorCode submitFrameStereoLeftRight(
      Fove::IFVRCompositor compositor,
      GLuint texture,
      int layerId,
      const Fove::SFVR_Pose& pose);

    static inline Fove::EFVR_ErrorCode submitFrameMono(
      Fove::IFVRCompositor& compositor,
      GLuint texture,
      int layerId,
      const Fove::SFVR_Pose& pose);

    static std::shared_ptr<Fove::SFVR_CompositorLayer> createCompositorLayerRef(Fove::IFVRCompositor& compositor);

  private:
    std::shared_ptr<Fove::IFVRHeadset> headsetRef = nullptr;
    std::shared_ptr<Fove::IFVRCompositor> compositorRef = nullptr;
    std::shared_ptr<Fove::SFVR_CompositorLayer> compositorLayerRef = nullptr;
    ci::gl::FboRef fboRef = nullptr;
  };

}}
