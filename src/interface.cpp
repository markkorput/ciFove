#include "IFVRHeadset.h"
#include "ciFove/interface.h"

cinder::fove::Context* cinder::fove::createContext(FoveOpts opts) {
  auto pHeadset = Fove::GetFVRHeadset();

  if (CheckError(pHeadset->Initialise(opts.clientCapabilities()), "Initialise")) {
    // return NULL;
  }

  return new Context(pHeadset);
}
