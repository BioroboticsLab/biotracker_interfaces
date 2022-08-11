#pragma once

#include "IModel.h"
#include "opencv2/core/core.hpp"

class BT_INTERFACES_API IModelTrackingAlgorithm : public IModel
{
    Q_OBJECT
public:
    IModelTrackingAlgorithm(QObject* parent = 0);

    virtual void doTracking(cv::Mat image, uint frameNumber) = 0;

signals:
    void emitTrackingDone();
};
