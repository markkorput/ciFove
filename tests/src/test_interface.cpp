#include "catch.hpp"

#include "ciFove/interface.h"
//
using namespace cinder;

TEST_CASE("cinder::fove::Interface", ""){

  SECTION("ctor"){
    fove::Interface interface;
    REQUIRE(interface.getHeadset() == nullptr);
  }

  SECTION("setup_without_customs_opts"){
    fove::Interface interface;
    interface.setup();

    //#ifdef CINDER_MSW // windows supported
    REQUIRE(interface.getHeadset() != nullptr);
  }
}
