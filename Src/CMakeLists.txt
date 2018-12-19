##############################################################
#### Biotracker: Interfaces
##############################################################

set(target ${PROJECT_NAME})
add_library(${target} SHARED)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_target_properties(${target} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS true)
endif()

install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}Targets
    RUNTIME DESTINATION "${INSTALL_BINDIR}"
    LIBRARY DESTINATION "${INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${INSTALL_LIBDIR}"
)

target_include_directories(${target} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets OpenGL)
target_link_libraries(${target}  Qt5::Core Qt5::Gui Qt5::Widgets)

find_package(OpenCV 3 REQUIRED)
target_link_libraries(${target} ${OpenCV_LIBS})

set_target_properties(${target} PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON)
set_target_properties(${target} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_compile_definitions(${target} PRIVATE BT_INTERFACES_EXPORT)

target_sources(${target}
    PRIVATE
    "Interfaces/ENUMS.cpp"
    "Interfaces/IBioTrackerContext.cpp"
    "Interfaces/IBioTrackerPlugin.cpp"
    "Interfaces/IController/IController.cpp"
    "Interfaces/IModel/IModel.cpp"
    "Interfaces/IModel/IModelAreaDescriptor.h"
    "Interfaces/IModel/IModelDataExporter.cpp"
    "Interfaces/IModel/IModelTrackedComponent.cpp"
    "Interfaces/IModel/IModelTrackedComponentFactory.cpp"
    "Interfaces/IModel/IModelTrackedTrajectory.cpp"
    "Interfaces/IModel/IModelTrackingAlgorithm.cpp"
    "Interfaces/IModel/IObject.cpp"
    "Interfaces/IModel/Serializable.cpp"
    "Interfaces/IView/IView.cpp"
    "Interfaces/IView/IViewGraphicsPixmapItem.cpp"
    "Interfaces/IView/IViewGraphicsScene.cpp"
    "Interfaces/IView/IViewGraphicsView.cpp"
    "Interfaces/IView/IViewMainWindow.cpp"
    "Interfaces/IView/IViewOpenGLWidget.cpp"
    "Interfaces/IView/IViewTrackedComponent.cpp"
    "Interfaces/IView/IViewWidget.cpp"
)

install_headers(
    HEADERS
    "Interfaces/API.h"
    "Interfaces/ENUMS.h"
    "Interfaces/IBioTrackerContext.h"
    "Interfaces/IBioTrackerPlugin.h"
    "Interfaces/IController/IController.h"
    "Interfaces/IModel/IModel.h"
    "Interfaces/IModel/IModelAreaDescriptor.h"
    "Interfaces/IModel/IModelDataExporter.h"
    "Interfaces/IModel/IModelTrackedComponent.h"
    "Interfaces/IModel/IModelTrackedComponentFactory.h"
    "Interfaces/IModel/IModelTrackedTrajectory.h"
    "Interfaces/IModel/IModelTrackingAlgorithm.h"
    "Interfaces/IModel/IObject.h"
    "Interfaces/IModel/Serializable.h"
    "Interfaces/IView/IView.h"
    "Interfaces/IView/IViewGraphicsPixmapItem.h"
    "Interfaces/IView/IViewGraphicsScene.h"
    "Interfaces/IView/IViewGraphicsView.h"
    "Interfaces/IView/IViewMainWindow.h"
    "Interfaces/IView/IViewOpenGLWidget.h"
    "Interfaces/IView/IViewTrackedComponent.h"
    "Interfaces/IView/IViewWidget.h"
    DESTINATION "${INSTALL_INCLUDEDIR}"
)

