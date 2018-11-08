#include <memory> // for unique_ptr in non-windows
// #include "FoveTypes.h"
#include "IFVRHeadset.h"

namespace cinder { namespace fove {
  class Interface {
  public:
    Interface();

    const Fove::IFVRHeadset* getHeadset() {
      return headsetRef.get();
    }

  private:
    const std::unique_ptr<Fove::IFVRHeadset> headsetRef;
  };
}}
