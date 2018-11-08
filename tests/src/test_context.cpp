#include "catch.hpp"

#include "ciFove/interface.h"

using namespace cinder;

TEST_CASE("cinder::fove::Context", ""){

  SECTION("createContext_without_customs_opts"){
    auto ctx = fove::createContextRef();
    REQUIRE(ctx->getHeadset() != nullptr);
  }

  SECTION("createContext_with_client_capabilities"){
    auto ctx = fove::createContextRef(
      fove::FoveOpts()
      .clientCapabilities(Fove::EFVR_ClientCapabilities::Orientation | Fove::EFVR_ClientCapabilities::Position)
    );

    REQUIRE(ctx->getHeadset() != nullptr);
  }
}
