//
// Created by Alpha BAO on 10/21/20.
//

#ifndef INFINITAM_INFINITAMAPP_H
#define INFINITAM_INFINITAMAPP_H

#include <stdlib.h>
#include "InputSource/IMUSourceEngine.h"
#include "InputSource/ImageSourceEngine.h"
#include "ITMLib/Core/ITMMainEngine.h"
#include "ORUtils/NVTimer.h"

class InfiniTAMApp {
public:
    static InfiniTAMApp* Instance(void)
    {
        if (globalInstance==NULL) globalInstance = new InfiniTAMApp();
        return globalInstance;
    }

    InfiniTAMApp(void);
    ~InfiniTAMApp(void);

    void InitGL();
    void ResizeGL(int newWidth, int newHeight);
    void RenderGL(void);

    void StartProcessing(int useLiveCamera);
    bool ProcessFrame(void);
    void StopProcessing(void);

    bool IsInitialized(void) const
    { return mIsInitialized; }

    void toggleRecordingMode(void);

    float getAverageTime(void);

private:
    static InfiniTAMApp *globalInstance;

    InputSource::ImageSourceEngine *mImageSource;
    InputSource::IMUSourceEngine *mImuSource;
    ITMLib::ITMLibSettings *mInternalSettings;
    ITMLib::ITMMainEngine *mMainEngine;

    ORUChar4Image *inputRGBImage; ORShortImage *inputRawDepthImage;
    ITMLib::ITMIMUMeasurement *inputIMUMeasurement;

    StopWatchInterface *timer_instant;
    StopWatchInterface *timer_average;

    static const int NUM_WIN = 3;
    Vector4f winPos[NUM_WIN];
    uint textureId[NUM_WIN];
    ITMLib::ITMMainEngine::GetImageType winImageType[NUM_WIN];
    ORUChar4Image *outImage[NUM_WIN];

    Vector2i mNewWindowSize;
    bool mIsInitialized;
    bool mRecordingMode;
};


#endif //INFINITAM_INFINITAMAPP_H
