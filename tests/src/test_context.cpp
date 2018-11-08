#include "catch.hpp"

#include "ciFove/Context.h"

using namespace cinder;

TEST_CASE("cinder::fove::Context", ""){

  SECTION("create_without_customs_opts"){
    auto ctx = fove::Context::create();
    REQUIRE(ctx->getHeadset() != nullptr);
  }

  SECTION("createContext_with_client_capabilities"){
    auto ctx = fove::Context::create(
      fove::FoveOpts()
      .clientCapabilities(Fove::EFVR_ClientCapabilities::Orientation | Fove::EFVR_ClientCapabilities::Position)
    );

    REQUIRE(ctx->getHeadset() != nullptr);
  }
}
