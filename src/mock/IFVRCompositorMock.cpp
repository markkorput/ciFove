#include "IFVRCompositor.h"
#include "ciFove/mock/IFVRCompositorMock.h"
// #include <iostream> // std::cout, std::endl

// Use std namespace for convenience
using namespace std;
using namespace Fove;
using namespace cinder::fove::mock;

IFVRCompositor* Fove::GetFVRCompositor() {
	return (IFVRCompositor*) new IFVRCompositorMock();
}


EFVR_ErrorCode IFVRCompositorMock::CreateLayer(const SFVR_CompositorLayerCreateInfo& layerInfo, SFVR_CompositorLayer* outLayer) {
	return EFVR_ErrorCode::Connect_NotConnected;
}

EFVR_ErrorCode IFVRCompositorMock::SubmitGroup(const SFVR_CompositorLayerSubmitInfo* submitInfo, std::size_t layerCount) {
	return EFVR_ErrorCode::Connect_NotConnected;
}

EFVR_ErrorCode IFVRCompositorMock::WaitForRenderPose(SFVR_Pose* outPose) {
	return EFVR_ErrorCode::Connect_NotConnected;
}

EFVR_ErrorCode IFVRCompositorMock::GetLastRenderPose(SFVR_Pose* outPose) const {
	return EFVR_ErrorCode::Connect_NotConnected;
}

EFVR_ErrorCode IFVRCompositorMock::IsReady(bool* out) const {
	return EFVR_ErrorCode::Connect_NotConnected;
}

EFVR_ErrorCode IFVRCompositorMock::GetAdapterId(SFVR_AdapterId* out) {
	return EFVR_ErrorCode::Connect_NotConnected;
}
