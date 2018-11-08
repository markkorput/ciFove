#include <memory>
#include <iostream>
// #include "FoveTypes.h"
#include "IFVRHeadset.h"

#include "FoveOpts.h"

namespace cinder { namespace fove {

  class Context {

  public:
    Context(Fove::IFVRHeadset* headset) {
      headsetRef = headset ? std::shared_ptr<Fove::IFVRHeadset>(headset) : nullptr; };

    const std::shared_ptr<Fove::IFVRHeadset> getHeadset() { return headsetRef; }

  private:
    std::shared_ptr<Fove::IFVRHeadset> headsetRef;
  };
}}
