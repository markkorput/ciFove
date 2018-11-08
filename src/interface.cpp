#include "ciFove/interface.h"

using namespace cinder::fove;

Interface::Interface() : headsetRef(nullptr) {
}

void Interface::setup() {
  headsetRef = std::shared_ptr<Fove::IFVRHeadset>(Fove::GetFVRHeadset());
}
