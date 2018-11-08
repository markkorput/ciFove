#include "catch.hpp"

#include "ciFove/interface.h"
//
using namespace cinder;

TEST_CASE("cinder::fove::Interface", ""){

  SECTION("ctor"){
    fove::Interface interface;
    REQUIRE(interface.getHeadset() == NULL);
  }
}
