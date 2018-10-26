##############################################################
#### Biotracker: Interfaces
##############################################################

target_include_directories(${TN} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets OpenGL Xml Network)
target_link_libraries(${TN}  Qt5::Core Qt5::Gui Qt5::Xml Qt5::Network Qt5::Widgets)

find_package(OpenCV 3 REQUIRED)
target_link_libraries(${TN} ${OpenCV_LIBS})

set_target_properties(${TN} PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(${TN} PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON)
set_target_properties(${TN} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_compile_definitions(${TN} PRIVATE BT_INTERFACES_EXPORT)

target_sources(${TN}
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/ENUMS.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IBioTrackerContext.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IBioTrackerPlugin.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IController/IController.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModel.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelAreaDescriptor.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelDataExporter.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackedComponent.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackedComponentFactory.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackedTrajectory.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackingAlgorithm.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IObject.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/Serializable.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IView.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewGraphicsPixmapItem.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewGraphicsScene.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewGraphicsView.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewMainWindow.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewOpenGLWidget.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewTrackedComponent.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewWidget.cpp"
)

set(${TN}_PUBLIC_HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/API.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/ENUMS.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IBioTrackerContext.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IBioTrackerPlugin.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IController/IController.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModel.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelAreaDescriptor.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelDataExporter.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackedComponent.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackedComponentFactory.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackedTrajectory.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IModelTrackingAlgorithm.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/IObject.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IModel/Serializable.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IView.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewGraphicsPixmapItem.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewGraphicsScene.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewGraphicsView.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewMainWindow.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewOpenGLWidget.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewTrackedComponent.h"
    "${CMAKE_CURRENT_LIST_DIR}/Interfaces/IView/IViewWidget.h"
)
