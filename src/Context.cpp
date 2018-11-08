#include "IFVRHeadset.h"
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
