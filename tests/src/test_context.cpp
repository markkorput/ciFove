#include "catch.hpp"

#include "ciFove/Context.h"

using namespace cinder;

TEST_CASE("cinder::fove::Context", ""){

  SECTION("create_without_customs_opts"){
    auto ctx = fove::Context::create();
    REQUIRE(ctx->getHeadset() != nullptr);
  }

  SECTION("create_with_client_capabilities"){
    auto ctx = fove::Context::create(
      fove::FoveOpts()
      .clientCapabilities(Fove::EFVR_ClientCapabilities::Orientation | Fove::EFVR_ClientCapabilities::Position)
    );

    REQUIRE(ctx->getHeadset() != nullptr);
  }

  SECTION("renderStereo"){
    auto ctx = fove::Context::create();

    ctx->renderStereo([](Fove::EFVR_Eye eye, Fove::SFVR_Pose& pose){
      // draw scene here
      // this lambda will be executed twice; once for each eye
    });
  }

  SECTION("renderMono_with_fbo"){
    fove::Context* ctx = NULL;

    // Th following block will never execute, which is good because this is
    // is a console application and we cannot allocate a fbo.
    // This code is here only to test compilability and for demo-purposes
    if (ctx) {
      auto fboRef = gl::Fbo::create( 1024, 1024, gl::Fbo::Format().depthTexture() );
      ctx->submitFrameMono(*fboRef);
    }
  }

  SECTION("getEyeResolution") {
    auto ctx = fove::Context::create();
    // REQUIRE(ctx->getEyeResolution() == ci::ivec2(0,0));
    // just checking it doesn't throw any errors
    ctx->getEyeResolution();
  }
}
