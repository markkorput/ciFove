#include "IFVRHeadset.h"
#include "IFVRCompositor.h"
#include "ciFove/mock/IFVRHeadsetMock.h"
// #include <iostream> // std::cout, std::endl

// Use std namespace for convenience
using namespace std;
using namespace Fove;
using namespace cinder::fove::mock;

IFVRHeadset* Fove::GetFVRHeadset() {
	return (IFVRHeadset*) new IFVRHeadsetMock();
}

IFVRCompositor* Fove::GetFVRCompositor() {
	return NULL;
}

EFVR_ErrorCode IFVRHeadsetMock::Initialise(EFVR_ClientCapabilities capabilities){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsHardwareConnected(bool* outHardwareConnected){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsHardwareReady(bool* outIsReady){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::CheckSoftwareVersions(){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetSoftwareVersions(SFVR_Versions* outSoftwareVersions){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetGazeVector(EFVR_Eye eye, SFVR_GazeVector* outGazeVector){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetGazeVectors(SFVR_GazeVector* outLeft, SFVR_GazeVector* outRight){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetGazeConvergence(SFVR_GazeConvergenceData* outConvergenceData){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetGazeVectors2D(SFVR_Vec2* outLeft, SFVR_Vec2* outRight){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::CheckEyesClosed(EFVR_Eye* outEye){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::CheckEyesTracked(EFVR_Eye* outEye){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsEyeTrackingEnabled(bool* outEyeTrackingEnabled){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsEyeTrackingCalibrated(bool* outEyeTrackingCalibrated){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsEyeTrackingCalibrating(bool* outEyeTrackingCalibrating){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsEyeTrackingReady(bool* outEyeTrackingReady){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsMotionReady(bool* outMotionReady){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::TareOrientationSensor(){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::IsPositionReady(bool* outPositionReady){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::TarePositionSensors(){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetHMDPose(SFVR_Pose* outPose){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetPoseByIndex(int id, SFVR_Pose* outPose){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetProjectionMatricesLH(float zNear, float zFar, SFVR_Matrix44* outLeftMat, SFVR_Matrix44* outRightMat){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetProjectionMatricesRH(float zNear, float zFar, SFVR_Matrix44* outLeftMat, SFVR_Matrix44* outRightMat){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetRawProjectionValues(SFVR_ProjectionParams* outLeft, SFVR_ProjectionParams* outRight){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetEyeToHeadMatrices(SFVR_Matrix44 *outLeft, SFVR_Matrix44 *outRight){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::TriggerOnePointCalibration(){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::ManualDriftCorrection3D(SFVR_Vec3 position){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetIOD(float* outIOD){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::GetSystemHealth(SFVR_SystemHealth* outStatus, bool runTest){
	return EFVR_ErrorCode::Connect_NotConnected;
}
EFVR_ErrorCode IFVRHeadsetMock::EnsureEyeTrackingCalibration(){
	return EFVR_ErrorCode::Connect_NotConnected;
}
