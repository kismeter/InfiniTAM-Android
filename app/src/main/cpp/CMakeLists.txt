# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("infinitam")

#set(CMAKE_CXX11_EXTENSION_COMPILE_OPTION "-std=c++17")

find_library(android-lib android)
find_library(GLESv2-lib GLESv1_CM)
find_library(EGL-lib EGL)
find_library(log-lib log)

include_directories(.)

# FernRelocLib Sources
file(GLOB fernreloc_srcs "FernRelocLib/*.cpp")
# ORUtils Source
file(GLOB orutils_srcs "ORUtils/*.cpp")
# MiniSlamGraph Source
file(GLOB minislamgraph_srcs "MiniSlamGraphLib/*.cpp")
# InputSource Source
file(GLOB inputsource_srcs "InputSource/*.cpp")
# ITMLib Source
#############################
# Specify the project files #
#############################

##
SET(ITMLIB_TOPLEVEL_CPU_SOURCES
        ITMLib/CPUInstantiations.cpp
        )

SET(ITMLIB_TOPLEVEL_CUDA_SOURCES
        ITMLib/CUDAInstantiations.cu
        )

SET(ITMLIB_TOPLEVEL_HEADERS
        ITMLib/ITMLibDefines.h
        )

##
SET(ITMLIB_CORE_SOURCES
        ITMLib/Core/ITMBasicEngine.tpp
        ITMLib/Core/ITMBasicSurfelEngine.tpp
        ITMLib/Core/ITMDenseMapper.tpp
        ITMLib/Core/ITMDenseSurfelMapper.tpp
        ITMLib/Core/ITMMultiEngine.tpp
        )

SET(ITMLIB_CORE_HEADERS
        ITMLib/Core/ITMBasicEngine.h
        ITMLib/Core/ITMBasicSurfelEngine.h
        ITMLib/Core/ITMDenseMapper.h
        ITMLib/Core/ITMDenseSurfelMapper.h
        ITMLib/Core/ITMMainEngine.h
        ITMLib/Core/ITMMultiEngine.h
        ITMLib/Core/ITMTrackingController.h
        )

##
SET(ITMLIB_ENGINES_LOWLEVEL_SOURCES
        ITMLib/Engines/LowLevel/ITMLowLevelEngineFactory.cpp
        )

SET(ITMLIB_ENGINES_LOWLEVEL_HEADERS
        ITMLib/Engines/LowLevel/ITMLowLevelEngineFactory.h
        )

##
SET(ITMLIB_ENGINES_LOWLEVEL_CPU_SOURCES
        ITMLib/Engines/LowLevel/CPU/ITMLowLevelEngine_CPU.cpp
        )

SET(ITMLIB_ENGINES_LOWLEVEL_CPU_HEADERS
        ITMLib/Engines/LowLevel/CPU/ITMLowLevelEngine_CPU.h
        )

##
SET(ITMLIB_ENGINES_LOWLEVEL_CUDA_SOURCES
        ITMLib/Engines/LowLevel/CUDA/ITMLowLevelEngine_CUDA.cu
        )

SET(ITMLIB_ENGINES_LOWLEVEL_CUDA_HEADERS
        ITMLib/Engines/LowLevel/CUDA/ITMLowLevelEngine_CUDA.h
        )

##
SET(ITMLIB_ENGINES_LOWLEVEL_INTERFACE_HEADERS
        ITMLib/Engines/LowLevel/Interface/ITMLowLevelEngine.h
        )

##
SET(ITMLIB_ENGINES_LOWLEVEL_SHARED_HEADERS
        ITMLib/Engines/LowLevel/Shared/ITMLowLevelEngine_Shared.h
        )

##
SET(ITMLIB_ENGINES_MESHING_HEADERS
        ITMLib/Engines/Meshing/ITMMeshingEngineFactory.h
        ITMLib/Engines/Meshing/ITMMultiMeshingEngineFactory.h
        )

##
SET(ITMLIB_ENGINES_MESHING_CPU_SOURCES
        ITMLib/Engines/Meshing/CPU/ITMMeshingEngine_CPU.tpp
        ITMLib/Engines/Meshing/CPU/ITMMultiMeshingEngine_CPU.tpp
        )

SET(ITMLIB_ENGINES_MESHING_CPU_HEADERS
        ITMLib/Engines/Meshing/CPU/ITMMeshingEngine_CPU.h
        ITMLib/Engines/Meshing/CPU/ITMMultiMeshingEngine_CPU.h
        )

##
SET(ITMLIB_ENGINES_MESHING_CUDA_SOURCES
        ITMLib/Engines/Meshing/CUDA/ITMMeshingEngine_CUDA.tcu
        ITMLib/Engines/Meshing/CUDA/ITMMultiMeshingEngine_CUDA.tcu
        )

SET(ITMLIB_ENGINES_MESHING_CUDA_HEADERS
        ITMLib/Engines/Meshing/CUDA/ITMMeshingEngine_CUDA.h
        ITMLib/Engines/Meshing/CUDA/ITMMultiMeshingEngine_CUDA.h
        )

##
SET(ITMLIB_ENGINES_MESHING_INTERFACE_HEADERS
        ITMLib/Engines/Meshing/Interface/ITMMeshingEngine.h
        ITMLib/Engines/Meshing/Interface/ITMMultiMeshingEngine.h
        )

##
SET(ITMLIB_ENGINES_MESHING_SHARED_HEADERS
        ITMLib/Engines/Meshing/Shared/ITMMeshingEngine_Shared.h
        ITMLib/Engines/Meshing/Shared/ITMMultiMeshingEngine_Shared.h
        )

##
SET(ITMLIB_ENGINES_MULTISCENE_SOURCES
        ITMLib/Engines/MultiScene/ITMActiveMapManager.cpp
        ITMLib/Engines/MultiScene/ITMGlobalAdjustmentEngine.cpp
        ITMLib/Engines/MultiScene/ITMMapGraphManager.tpp
        )

SET(ITMLIB_ENGINES_MULTISCENE_HEADERS
        ITMLib/Engines/MultiScene/ITMActiveMapManager.h
        ITMLib/Engines/MultiScene/ITMGlobalAdjustmentEngine.h
        ITMLib/Engines/MultiScene/ITMMapGraphManager.h
        )

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_SOURCES
        ITMLib/Engines/Reconstruction/ITMSurfelSceneReconstructionEngineFactory.tpp
        )

SET(ITMLIB_ENGINES_RECONSTRUCTION_HEADERS
        ITMLib/Engines/Reconstruction/ITMSceneReconstructionEngineFactory.h
        ITMLib/Engines/Reconstruction/ITMSurfelSceneReconstructionEngineFactory.h
        )

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_CPU_SOURCES
        ITMLib/Engines/Reconstruction/CPU/ITMSceneReconstructionEngine_CPU.tpp
        ITMLib/Engines/Reconstruction/CPU/ITMSurfelSceneReconstructionEngine_CPU.tpp
        )

SET(ITMLIB_ENGINES_RECONSTRUCTION_CPU_HEADERS
        ITMLib/Engines/Reconstruction/CPU/ITMSceneReconstructionEngine_CPU.h
        ITMLib/Engines/Reconstruction/CPU/ITMSurfelSceneReconstructionEngine_CPU.h
        )

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_CUDA_SOURCES
        ITMLib/Engines/Reconstruction/CUDA/ITMSceneReconstructionEngine_CUDA.tcu
        ITMLib/Engines/Reconstruction/CUDA/ITMSurfelSceneReconstructionEngine_CUDA.tcu
        )

SET(ITMLIB_ENGINES_RECONSTRUCTION_CUDA_HEADERS
        ITMLib/Engines/Reconstruction/CUDA/ITMSceneReconstructionEngine_CUDA.h
        ITMLib/Engines/Reconstruction/CUDA/ITMSurfelSceneReconstructionEngine_CUDA.h
        )

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_SOURCES
        ITMLib/Engines/Reconstruction/Interface/ITMSurfelSceneReconstructionEngine.tpp
        )

SET(ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_HEADERS
        ITMLib/Engines/Reconstruction/Interface/ITMSceneReconstructionEngine.h
        ITMLib/Engines/Reconstruction/Interface/ITMSurfelSceneReconstructionEngine.h
        )

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_SHARED_HEADERS
        ITMLib/Engines/Reconstruction/Shared/ITMSceneReconstructionEngine_Shared.h
        ITMLib/Engines/Reconstruction/Shared/ITMSurfelSceneReconstructionEngine_Shared.h
        )

##
SET(ITMLIB_ENGINES_SWAPPING_HEADERS
        ITMLib/Engines/Swapping/ITMSwappingEngineFactory.h
        )

##
SET(ITMLIB_ENGINES_SWAPPING_CPU_SOURCES
        ITMLib/Engines/Swapping/CPU/ITMSwappingEngine_CPU.tpp
        )

SET(ITMLIB_ENGINES_SWAPPING_CPU_HEADERS
        ITMLib/Engines/Swapping/CPU/ITMSwappingEngine_CPU.h
        )

##
SET(ITMLIB_ENGINES_SWAPPING_CUDA_SOURCES
        ITMLib/Engines/Swapping/CUDA/ITMSwappingEngine_CUDA.tcu
        )

SET(ITMLIB_ENGINES_SWAPPING_CUDA_HEADERS
        ITMLib/Engines/Swapping/CUDA/ITMSwappingEngine_CUDA.h
        )

##
SET(ITMLIB_ENGINES_SWAPPING_INTERFACE_HEADERS
        ITMLib/Engines/Swapping/Interface/ITMSwappingEngine.h
        )

##
SET(ITMLIB_ENGINES_SWAPPING_SHARED_HEADERS
        ITMLib/Engines/Swapping/Shared/ITMSwappingEngine_Shared.h
        )

##
SET(ITMLIB_ENGINES_VIEWBUILDING_SOURCES
        ITMLib/Engines/ViewBuilding/ITMViewBuilderFactory.cpp
        )

SET(ITMLIB_ENGINES_VIEWBUILDING_HEADERS
        ITMLib/Engines/ViewBuilding/ITMViewBuilderFactory.h
        )

##
SET(ITMLIB_ENGINES_VIEWBUILDING_CPU_SOURCES
        ITMLib/Engines/ViewBuilding/CPU/ITMViewBuilder_CPU.cpp
        )

SET(ITMLIB_ENGINES_VIEWBUILDING_CPU_HEADERS
        ITMLib/Engines/ViewBuilding/CPU/ITMViewBuilder_CPU.h
        )

##
SET(ITMLIB_ENGINES_VIEWBUILDING_CUDA_SOURCES
        ITMLib/Engines/ViewBuilding/CUDA/ITMViewBuilder_CUDA.cu
        )

SET(ITMLIB_ENGINES_VIEWBUILDING_CUDA_HEADERS
        ITMLib/Engines/ViewBuilding/CUDA/ITMViewBuilder_CUDA.h
        )

##
SET(ITMLIB_ENGINES_VIEWBUILDING_INTERFACE_HEADERS
        ITMLib/Engines/ViewBuilding/Interface/ITMViewBuilder.h
        )

##
SET(ITMLIB_ENGINES_VIEWBUILDING_SHARED_HEADERS
        ITMLib/Engines/ViewBuilding/Shared/ITMViewBuilder_Shared.h
        )

##
SET(ITMLIB_ENGINES_VISUALISATION_SOURCES
        ITMLib/Engines/Visualisation/ITMSurfelVisualisationEngineFactory.tpp
        )

SET(ITMLIB_ENGINES_VISUALISATION_HEADERS
        ITMLib/Engines/Visualisation/ITMMultiVisualisationEngineFactory.h
        ITMLib/Engines/Visualisation/ITMSurfelVisualisationEngineFactory.h
        ITMLib/Engines/Visualisation/ITMVisualisationEngineFactory.h
        )

##
SET(ITMLIB_ENGINES_VISUALISATION_CPU_SOURCES
        ITMLib/Engines/Visualisation/CPU/ITMMultiVisualisationEngine_CPU.tpp
        ITMLib/Engines/Visualisation/CPU/ITMSurfelVisualisationEngine_CPU.tpp
        ITMLib/Engines/Visualisation/CPU/ITMVisualisationEngine_CPU.tpp
        )

SET(ITMLIB_ENGINES_VISUALISATION_CPU_HEADERS
        ITMLib/Engines/Visualisation/CPU/ITMMultiVisualisationEngine_CPU.h
        ITMLib/Engines/Visualisation/CPU/ITMSurfelVisualisationEngine_CPU.h
        ITMLib/Engines/Visualisation/CPU/ITMVisualisationEngine_CPU.h
        )

##
SET(ITMLIB_ENGINES_VISUALISATION_CUDA_SOURCES
        ITMLib/Engines/Visualisation/CUDA/ITMMultiVisualisationEngine_CUDA.tcu
        ITMLib/Engines/Visualisation/CUDA/ITMSurfelVisualisationEngine_CUDA.tcu
        ITMLib/Engines/Visualisation/CUDA/ITMVisualisationEngine_CUDA.tcu
        ITMLib/Engines/Visualisation/CUDA/ITMVisualisationHelpers_CUDA.cu
        )

SET(ITMLIB_ENGINES_VISUALISATION_CUDA_HEADERS
        ITMLib/Engines/Visualisation/CUDA/ITMMultiVisualisationEngine_CUDA.h
        ITMLib/Engines/Visualisation/CUDA/ITMSurfelVisualisationEngine_CUDA.h
        ITMLib/Engines/Visualisation/CUDA/ITMVisualisationEngine_CUDA.h
        ITMLib/Engines/Visualisation/CUDA/ITMVisualisationHelpers_CUDA.h
        )

##
SET(ITMLIB_ENGINES_VISUALISATION_INTERFACE_SOURCES
        ITMLib/Engines/Visualisation/Interface/ITMSurfelVisualisationEngine.tpp
        ITMLib/Engines/Visualisation/Interface/ITMVisualisationEngine.cpp
        )

SET(ITMLIB_ENGINES_VISUALISATION_INTERFACE_HEADERS
        ITMLib/Engines/Visualisation/Interface/ITMMultiVisualisationEngine.h
        ITMLib/Engines/Visualisation/Interface/ITMSurfelVisualisationEngine.h
        ITMLib/Engines/Visualisation/Interface/ITMVisualisationEngine.h
        )

##
SET(ITMLIB_ENGINES_VISUALISATION_SHARED_HEADERS
        ITMLib/Engines/Visualisation/Shared/ITMSurfelVisualisationEngine_Settings.h
        ITMLib/Engines/Visualisation/Shared/ITMSurfelVisualisationEngine_Shared.h
        ITMLib/Engines/Visualisation/Shared/ITMVisualisationEngine_Shared.h
        )

##
SET(ITMLIB_OBJECTS_CAMERA_SOURCES
        ITMLib/Objects/Camera/ITMCalibIO.cpp
        )

SET(ITMLIB_OBJECTS_CAMERA_HEADERS
        ITMLib/Objects/Camera/ITMCalibIO.h
        ITMLib/Objects/Camera/ITMDisparityCalib.h
        ITMLib/Objects/Camera/ITMExtrinsics.h
        ITMLib/Objects/Camera/ITMIntrinsics.h
        ITMLib/Objects/Camera/ITMRGBDCalib.h
        )

##
SET(ITMLIB_OBJECTS_MESHING_HEADERS
        ITMLib/Objects/Meshing/ITMMesh.h
        )

##
SET(ITMLIB_OBJECTS_MISC_HEADERS
        ITMLib/Objects/Misc/ITMIMUCalibrator.h
        ITMLib/Objects/Misc/ITMIMUMeasurement.h
        ITMLib/Objects/Misc/ITMPointCloud.h
        )

##
SET(ITMLIB_OBJECTS_RENDERSTATES_SOURCES
        ITMLib/Objects/RenderStates/ITMSurfelRenderState.cpp
        )

SET(ITMLIB_OBJECTS_RENDERSTATES_HEADERS
        ITMLib/Objects/RenderStates/ITMRenderState.h
        ITMLib/Objects/RenderStates/ITMRenderStateMultiScene.h
        ITMLib/Objects/RenderStates/ITMRenderState_VH.h
        ITMLib/Objects/RenderStates/ITMRenderStateFactory.h
        ITMLib/Objects/RenderStates/ITMSurfelRenderState.h
        )

##
SET(ITMLIB_OBJECTS_SCENE_HEADERS
        ITMLib/Objects/Scene/ITMGlobalCache.h
        ITMLib/Objects/Scene/ITMLocalMap.h
        ITMLib/Objects/Scene/ITMLocalVBA.h
        ITMLib/Objects/Scene/ITMMultiSceneAccess.h
        ITMLib/Objects/Scene/ITMPlainVoxelArray.h
        ITMLib/Objects/Scene/ITMRepresentationAccess.h
        ITMLib/Objects/Scene/ITMScene.h
        ITMLib/Objects/Scene/ITMSurfelScene.h
        ITMLib/Objects/Scene/ITMSurfelTypes.h
        ITMLib/Objects/Scene/ITMVoxelBlockHash.h
        ITMLib/Objects/Scene/ITMVoxelTypes.h
        )

##
SET(ITMLIB_OBJECTS_TRACKING_HEADERS
        ITMLib/Objects/Tracking/ITMDepthHierarchyLevel.h
        ITMLib/Objects/Tracking/ITMImageHierarchy.h
        ITMLib/Objects/Tracking/ITMIntensityHierarchyLevel.h
        ITMLib/Objects/Tracking/ITMRGBHierarchyLevel.h
        ITMLib/Objects/Tracking/ITMSceneHierarchyLevel.h
        ITMLib/Objects/Tracking/ITMTemplatedHierarchyLevel.h
        ITMLib/Objects/Tracking/ITMTrackingState.h
        ITMLib/Objects/Tracking/ITMViewHierarchyLevel.h
        ITMLib/Objects/Tracking/TrackerIterationType.h
        )

##
SET(ITMLIB_OBJECTS_VIEWS_HEADERS
        ITMLib/Objects/Views/ITMView.h
        ITMLib/Objects/Views/ITMViewIMU.h
        )

##
SET(ITMLIB_TRACKERS_HEADERS
        ITMLib/Trackers/ITMTrackerFactory.h
        )

##
SET(ITMLIB_TRACKERS_CPU_SOURCES
        ITMLib/Trackers/CPU/ITMColorTracker_CPU.cpp
        ITMLib/Trackers/CPU/ITMDepthTracker_CPU.cpp
        ITMLib/Trackers/CPU/ITMExtendedTracker_CPU.cpp
        )

SET(ITMLIB_TRACKERS_CPU_HEADERS
        ITMLib/Trackers/CPU/ITMColorTracker_CPU.h
        ITMLib/Trackers/CPU/ITMDepthTracker_CPU.h
        ITMLib/Trackers/CPU/ITMExtendedTracker_CPU.h
        )

##
SET(ITMLIB_TRACKERS_CUDA_SOURCES
        ITMLib/Trackers/CUDA/ITMColorTracker_CUDA.cu
        ITMLib/Trackers/CUDA/ITMDepthTracker_CUDA.cu
        ITMLib/Trackers/CUDA/ITMExtendedTracker_CUDA.cu

        )

SET(ITMLIB_TRACKERS_CUDA_HEADERS
        ITMLib/Trackers/CUDA/ITMColorTracker_CUDA.h
        ITMLib/Trackers/CUDA/ITMDepthTracker_CUDA.h
        ITMLib/Trackers/CUDA/ITMExtendedTracker_CUDA.h
        )

##
SET(ITMLIB_TRACKERS_INTERFACE_SOURCES
        ITMLib/Trackers/Interface/ITMColorTracker.cpp
        ITMLib/Trackers/Interface/ITMDepthTracker.cpp
        ITMLib/Trackers/Interface/ITMExtendedTracker.cpp
        ITMLib/Trackers/Interface/ITMFileBasedTracker.cpp
        ITMLib/Trackers/Interface/ITMForceFailTracker.cpp
        ITMLib/Trackers/Interface/ITMIMUTracker.cpp
        )

SET(ITMLIB_TRACKERS_INTERFACE_HEADERS
        ITMLib/Trackers/Interface/ITMColorTracker.h
        ITMLib/Trackers/Interface/ITMCompositeTracker.h
        ITMLib/Trackers/Interface/ITMDepthTracker.h
        ITMLib/Trackers/Interface/ITMExtendedTracker.h
        ITMLib/Trackers/Interface/ITMFileBasedTracker.h
        ITMLib/Trackers/Interface/ITMForceFailTracker.h
        ITMLib/Trackers/Interface/ITMIMUTracker.h
        ITMLib/Trackers/Interface/ITMTracker.h
        )

##
SET(ITMLIB_TRACKERS_SHARED_HEADERS
        ITMLib/Trackers/Shared/ITMColorTracker_Shared.h
        ITMLib/Trackers/Shared/ITMDepthTracker_Shared.h
        ITMLib/Trackers/Shared/ITMExtendedTracker_Shared.h
        )

##
SET(ITMLIB_UTILS_SOURCES
        ITMLib/Utils/ITMLibSettings.cpp
        )

SET(ITMLIB_UTILS_HEADERS
        ITMLib/Utils/ITMCUDAUtils.h
        ITMLib/Utils/ITMLibSettings.h
        ITMLib/Utils/ITMPixelUtils.h
        ITMLib/Utils/ITMSceneParams.h
        ITMLib/Utils/ITMSurfelSceneParams.h
        )

file(GLOB itmlib_srcs
        ${ITMLIB_TOPLEVEL_CPU_SOURCES}
        ${ITMLIB_TOPLEVEL_CUDA_SOURCES}
        ${ITMLIB_CORE_SOURCES}
        ${ITMLIB_ENGINES_LOWLEVEL_SOURCES}
        ${ITMLIB_ENGINES_LOWLEVEL_CPU_SOURCES}
        ${ITMLIB_ENGINES_LOWLEVEL_CUDA_SOURCES}
        ${ITMLIB_ENGINES_MESHING_CPU_SOURCES}
        ${ITMLIB_ENGINES_MESHING_CUDA_SOURCES}
        ${ITMLIB_ENGINES_MULTISCENE_SOURCES}
        ${ITMLIB_ENGINES_RECONSTRUCTION_SOURCES}
        ${ITMLIB_ENGINES_RECONSTRUCTION_CPU_SOURCES}
        ${ITMLIB_ENGINES_RECONSTRUCTION_CUDA_SOURCES}
        ${ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_SOURCES}
        ${ITMLIB_ENGINES_SWAPPING_CPU_SOURCES}
        ${ITMLIB_ENGINES_SWAPPING_CUDA_SOURCES}
        ${ITMLIB_ENGINES_VIEWBUILDING_SOURCES}
        ${ITMLIB_ENGINES_VIEWBUILDING_CPU_SOURCES}
        ${ITMLIB_ENGINES_VIEWBUILDING_CUDA_SOURCES}
        ${ITMLIB_ENGINES_VISUALISATION_SOURCES}
        ${ITMLIB_ENGINES_VISUALISATION_CPU_SOURCES}
        ${ITMLIB_ENGINES_VISUALISATION_CUDA_SOURCES}
        ${ITMLIB_ENGINES_VISUALISATION_INTERFACE_SOURCES}
        ${ITMLIB_OBJECTS_CAMERA_SOURCES}
        ${ITMLIB_OBJECTS_RENDERSTATES_SOURCES}
        ${ITMLIB_TRACKERS_CPU_SOURCES}
        ${ITMLIB_TRACKERS_CUDA_SOURCES}
        ${ITMLIB_TRACKERS_INTERFACE_SOURCES}
        ${ITMLIB_UTILS_SOURCES})

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             infinitam

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ${fernreloc_srcs}
             ${orutils_srcs}
             ${minislamgraph_srcs}
             ${itmlib_srcs}
             ${inputsource_srcs}
             InfiniTAMApp.cpp
             native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
find_library(OpenSLES-lib OpenSLES)

target_link_libraries( # Specifies the target library.
                       infinitam

                       # Links the target library to the log library
                       # included in the NDK.
        ${android-lib}
        ${GLESv2-lib}
        ${EGL-lib}
        ${OpenSLES-lib}
                       ${log-lib} )