#pragma once

#include <memory> // for unique_ptr in non-windows
// #include "FoveTypes.h"
#include "IFVRHeadset.h"
#include "FoveTypes.h"

namespace cinder { namespace fove {

  class FoveOpts {
    public:
      FoveOpts(){}

      Fove::EFVR_ClientCapabilities clientCapabilities() const { return clientCapabs; }

      FoveOpts& clientCapabilities(Fove::EFVR_ClientCapabilities capabilities) {
        this->clientCapabs = capabilities;
        return *this;
      }

      // TODO add SFVR_CompositorLayerCreateInfo options

    private:
      Fove::EFVR_ClientCapabilities clientCapabs = Fove::EFVR_ClientCapabilities::Orientation | Fove::EFVR_ClientCapabilities::Position | Fove::EFVR_ClientCapabilities::Gaze;
  };
}}
