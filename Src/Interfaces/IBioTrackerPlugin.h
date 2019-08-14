#pragma once

#include "QObject"

#include "Interfaces/IController/IController.h"
#include "Interfaces/IModel/IModelDataExporter.h"
#include "Interfaces/IModel/IModelAreaDescriptor.h"
#include "Interfaces/IModel/IModelTrackedComponentFactory.h"
#include "opencv2/core/core.hpp"
#include "memory"
#include <Interfaces/API.h>


class BT_INTERFACES_API IBioTrackerPlugin : public QObject
{
    Q_OBJECT
public:
    ~IBioTrackerPlugin() {}

    virtual void createPlugin() = 0;

	/**
	* Hook for the tracker options to add to the GUI
	*/
    virtual IView *getTrackerParameterWidget();
	/**
	* Hook for the tracking data visualization of the tracker
	*/
    virtual IView *getTrackerElementsWidget();
	/**
	* Hook for the tracking data to visualize and export in the core app
	*/
    virtual IModel *getTrackerComponentModel();
	/**
	* Hook for the core permissions
	*/
    virtual void sendCorePermissions();
	/**
	* Hook for the component factory to deserialize in the core app
	*/
    virtual IModelTrackedComponentFactory *getComponentFactory();

private:
    virtual void connectInterfaces();

Q_SIGNALS:
    void emitCvMat(std::shared_ptr<cv::Mat> mat, QString name);
    /**
    * Will be sent when tracking is doen to multiple components of the core app
    * An example is the visualisation which is then updated
    */
    void emitTrackingDone(uint framenumber);
    void emitChangeDisplayImage(QString str);
    void emitCorePermission(std::pair<ENUMS::COREPERMISSIONS, bool>);

public Q_SLOTS:
    virtual void receiveCurrentFrameFromMainApp(std::shared_ptr<cv::Mat> mat, uint frameNumber) = 0;
	/**
	* Recieves area descriptor data for rectification (px to cm) and for tracking arena boundary
	*/
	virtual void receiveAreaDescriptor(IModelAreaDescriptor *areaDescr);

//private Q_SLOTS:
//    virtual void receiveCvMatFromController(std::shared_ptr<cv::Mat> mat, QString name) = 0;
};

#define IBioTrackerPlugin_iid "de.fu-berlin.mi.biorobotics.IBioTrackerPlugin"

Q_DECLARE_INTERFACE(IBioTrackerPlugin, IBioTrackerPlugin_iid)
