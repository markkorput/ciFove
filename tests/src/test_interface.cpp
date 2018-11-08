#include "catch.hpp"

#include "ciFove/interface.h"
//
using namespace cinder;

TEST_CASE("cinder::fove::Interface", ""){

  SECTION("setup_without_customs_opts"){
    fove::Interface interface;
    REQUIRE(interface.getHeadset() == nullptr);
    interface.setup();
    REQUIRE(interface.getHeadset() != nullptr);
  }
}
