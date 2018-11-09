#pragma once

#include <iostream>
#include <memory>
#include "FoveTypes.h"
#include "IFVRHeadset.h"

namespace cinder { namespace fove { namespace mock {
  class IFVRHeadsetMock : public Fove::IFVRHeadset {

    //~IFVRHeadset() override {}
    // ~IFVRHeadsetMock() {}
  public:
    void operator delete(void * p) // or delete(void *, std::size_t)
    {
      std::free((IFVRHeadsetMock*)p);
    }

    Fove::EFVR_ErrorCode Initialise(Fove::EFVR_ClientCapabilities capabilities) override;
    Fove::EFVR_ErrorCode IsHardwareConnected(bool* outHardwareConnected) override;
    Fove::EFVR_ErrorCode IsHardwareReady(bool* outIsReady) override;
    Fove::EFVR_ErrorCode CheckSoftwareVersions() override;
    Fove::EFVR_ErrorCode GetSoftwareVersions(Fove::SFVR_Versions* outSoftwareVersions) override;
    Fove::EFVR_ErrorCode GetGazeVector(Fove::EFVR_Eye eye, Fove::SFVR_GazeVector* outGazeVector) override;
    Fove::EFVR_ErrorCode GetGazeVectors(Fove::SFVR_GazeVector* outLeft, Fove::SFVR_GazeVector* outRight) override;
    Fove::EFVR_ErrorCode GetGazeConvergence(Fove::SFVR_GazeConvergenceData* outConvergenceData) override;
    Fove::EFVR_ErrorCode GetGazeVectors2D(Fove::SFVR_Vec2* outLeft, Fove::SFVR_Vec2* outRight) override;
    Fove::EFVR_ErrorCode CheckEyesClosed(Fove::EFVR_Eye* outEye) override;
    Fove::EFVR_ErrorCode CheckEyesTracked(Fove::EFVR_Eye* outEye) override;
    Fove::EFVR_ErrorCode IsEyeTrackingEnabled(bool* outEyeTrackingEnabled) override;
    Fove::EFVR_ErrorCode IsEyeTrackingCalibrated(bool* outEyeTrackingCalibrated) override;
    Fove::EFVR_ErrorCode IsEyeTrackingCalibrating(bool* outEyeTrackingCalibrating) override;
    Fove::EFVR_ErrorCode IsEyeTrackingReady(bool* outEyeTrackingReady) override;
    Fove::EFVR_ErrorCode IsMotionReady(bool* outMotionReady) override;
    Fove::EFVR_ErrorCode TareOrientationSensor() override;
    Fove::EFVR_ErrorCode IsPositionReady(bool* outPositionReady) override;
    Fove::EFVR_ErrorCode TarePositionSensors() override;
    Fove::EFVR_ErrorCode GetHMDPose(Fove::SFVR_Pose* outPose) override;
    Fove::EFVR_ErrorCode GetPoseByIndex(int id, Fove::SFVR_Pose* outPose) override;
    Fove::EFVR_ErrorCode GetProjectionMatricesLH(float zNear, float zFar, Fove::SFVR_Matrix44* outLeftMat, Fove::SFVR_Matrix44* outRightMat) override;
    Fove::EFVR_ErrorCode GetProjectionMatricesRH(float zNear, float zFar, Fove::SFVR_Matrix44* outLeftMat, Fove::SFVR_Matrix44* outRightMat) override;
    Fove::EFVR_ErrorCode GetRawProjectionValues(Fove::SFVR_ProjectionParams* outLeft, Fove::SFVR_ProjectionParams* outRight) override;
    Fove::EFVR_ErrorCode GetEyeToHeadMatrices(Fove::SFVR_Matrix44 *outLeft, Fove::SFVR_Matrix44 *outRight) override;
    Fove::EFVR_ErrorCode TriggerOnePointCalibration() override;
    Fove::EFVR_ErrorCode ManualDriftCorrection3D(Fove::SFVR_Vec3 position) override;
    Fove::EFVR_ErrorCode GetIOD(float* outIOD) override;
    Fove::EFVR_ErrorCode GetSystemHealth(Fove::SFVR_SystemHealth* outStatus, bool runTest) override;
    Fove::EFVR_ErrorCode EnsureEyeTrackingCalibration() override;


    // virtual EFVR_ErrorCode Initialise(EFVR_ClientCapabilities capabilities) = 0;
    // virtual EFVR_ErrorCode IsHardwareConnected(bool* outHardwareConnected) = 0;
    // virtual EFVR_ErrorCode IsHardwareReady(bool* outIsReady) = 0;
    // virtual EFVR_ErrorCode CheckSoftwareVersions() = 0;
    // virtual EFVR_ErrorCode GetSoftwareVersions(SFVR_Versions* outSoftwareVersions) = 0;
    // virtual EFVR_ErrorCode GetGazeVector(EFVR_Eye eye, SFVR_GazeVector* outGazeVector) = 0;
    // virtual EFVR_ErrorCode GetGazeVectors(SFVR_GazeVector* outLeft, SFVR_GazeVector* outRight) = 0;
    // virtual EFVR_ErrorCode GetGazeConvergence(SFVR_GazeConvergenceData* outConvergenceData) = 0;
    // virtual EFVR_ErrorCode GetGazeVectors2D(SFVR_Vec2* outLeft, SFVR_Vec2* outRight) = 0;
    // virtual EFVR_ErrorCode CheckEyesClosed(EFVR_Eye* outEye) = 0;
    // virtual EFVR_ErrorCode CheckEyesTracked(EFVR_Eye* outEye) = 0;
    // virtual EFVR_ErrorCode IsEyeTrackingEnabled(bool* outEyeTrackingEnabled) = 0;
    // virtual EFVR_ErrorCode IsEyeTrackingCalibrated(bool* outEyeTrackingCalibrated) = 0;
    // virtual EFVR_ErrorCode IsEyeTrackingCalibrating(bool* outEyeTrackingCalibrating) = 0;
    // virtual EFVR_ErrorCode IsEyeTrackingReady(bool* outEyeTrackingReady) = 0;
    // virtual EFVR_ErrorCode IsMotionReady(bool* outMotionReady) = 0;
    // virtual EFVR_ErrorCode TareOrientationSensor() = 0;
    // virtual EFVR_ErrorCode IsPositionReady(bool* outPositionReady) = 0;
    // virtual EFVR_ErrorCode TarePositionSensors() = 0;
    // virtual EFVR_ErrorCode GetHMDPose(SFVR_Pose* outPose) = 0;
    // virtual EFVR_ErrorCode GetPoseByIndex(int id, SFVR_Pose* outPose) = 0;
    // virtual EFVR_ErrorCode GetProjectionMatricesLH(float zNear, float zFar, SFVR_Matrix44* outLeftMat, SFVR_Matrix44* outRi...
    // virtual EFVR_ErrorCode GetProjectionMatricesRH(float zNear, float zFar, SFVR_Matrix44* outLeftMat, SFVR_Matrix44* outRi...
    // virtual EFVR_ErrorCode GetRawProjectionValues(SFVR_ProjectionParams* outLeft, SFVR_ProjectionParams* outRight) = 0;
    // virtual EFVR_ErrorCode GetEyeToHeadMatrices(SFVR_Matrix44 *outLeft, SFVR_Matrix44 *outRight) = 0;
    // virtual EFVR_ErrorCode TriggerOnePointCalibration() = 0;
    // virtual EFVR_ErrorCode ManualDriftCorrection3D(SFVR_Vec3 position) = 0;
    // virtual EFVR_ErrorCode GetIOD(float* outIOD) = 0;
    // virtual EFVR_ErrorCode GetSystemHealth(SFVR_SystemHealth* outStatus, bool runTest) = 0;
    // virtual EFVR_ErrorCode EnsureEyeTrackingCalibration() = 0;

  };
}}}
