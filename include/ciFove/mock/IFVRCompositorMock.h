#pragma once

#include <iostream>
#include <memory>
#include "FoveTypes.h"
#include "IFVRHeadset.h"

namespace cinder { namespace fove { namespace mock {
  class IFVRCompositorMock : public Fove::IFVRCompositor {

    public:

      void operator delete(void * p) // or delete(void *, std::size_t)
      {
        std::free((IFVRCompositorMock*)p);
      }

      Fove::EFVR_ErrorCode CreateLayer(const Fove::SFVR_CompositorLayerCreateInfo& layerInfo, Fove::SFVR_CompositorLayer* outLayer) override;
      Fove::EFVR_ErrorCode SubmitGroup(const Fove::SFVR_CompositorLayerSubmitInfo* submitInfo, std::size_t layerCount) override;
      Fove::EFVR_ErrorCode WaitForRenderPose(Fove::SFVR_Pose* outPose) override;
      Fove::EFVR_ErrorCode GetLastRenderPose(Fove::SFVR_Pose* outPose) const override;
      Fove::EFVR_ErrorCode IsReady(bool* out) const override;
      Fove::EFVR_ErrorCode GetAdapterId(Fove::SFVR_AdapterId* out) override;
  };
}}}
