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

  SECTION("render"){
    auto ctx = fove::Context::create();

    ctx->renderStereo([](){
      // draw scene here
      // this lambda will be executed twice; once for each eye
    });
  }

  SECTION("getEyeResolution") {
    auto ctx = fove::Context::create();
    // REQUIRE(ctx->getEyeResolution() == ci::ivec2(0,0));

    // just checking it doesn't throw any errors
    ctx->getEyeResolution();
  }
}
