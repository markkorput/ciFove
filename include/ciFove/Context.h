#include <memory>
#include <iostream>

#include "cinder/gl/gl.h"

#include "FoveTypes.h"
#include "IFVRHeadset.h"
#include "IFVRCompositor.h"

#include "FoveOpts.h"

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

    void render(std::function<void()> drawFunc);

  protected:

    void submitFrame();

    static inline Fove::EFVR_ErrorCode submitFrame(
      Fove::IFVRCompositor compositor,
      GLuint texture,
      int layerId,
      const Fove::SFVR_Pose& pose);

    std::shared_ptr<Fove::SFVR_CompositorLayer> createCompositorLayer();

  private:
    std::shared_ptr<Fove::IFVRHeadset> headsetRef = nullptr;
    std::shared_ptr<Fove::IFVRCompositor> compositorRef = nullptr;
    std::shared_ptr<Fove::SFVR_CompositorLayer> compositorLayerRef = nullptr;
    ci::gl::FboRef fboRef = nullptr;
  };

  // Helper function to throw an exception if the passed error code is not None
  inline bool CheckError(const Fove::EFVR_ErrorCode code, const char* const data)
  {
    if (code == Fove::EFVR_ErrorCode::None) return false;
    // throw std::runtime_error("Unable to get " + std::string(data) + ": " + std::to_string(static_cast<int>(code)));
    std::cerr
      << "[ciFove] Unable to get " << data
      << ": " << static_cast<int>(code)
      << std::endl;
    return true;
  }

  // // Helper function, which will throw if the result of a Fove call returns error
  // // Use like this: const auto MyObject = CheckError(Fove->GetSomeObject(...));
  // // This works on any function that returns an error via a .error field in the return object
  // template <typename Type>
  // Type&& CheckError(Type&& object, const char* const data)
  // {
  // 	CheckError(object.error, data);
  // 	return std::move(object);
  // }
}}
