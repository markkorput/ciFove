#include <memory> // for unique_ptr in non-windows
// #include "FoveTypes.h"
#include "IFVRHeadset.h"

namespace cinder { namespace fove {
  class Interface {

  public:
    Interface();
    void setup();

    const std::shared_ptr<Fove::IFVRHeadset> getHeadset() { return headsetRef; }

  private:
    std::shared_ptr<Fove::IFVRHeadset> headsetRef;
  };
}}
