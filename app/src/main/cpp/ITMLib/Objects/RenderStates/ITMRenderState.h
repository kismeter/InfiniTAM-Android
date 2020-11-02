// Copyright 2014-2017 Oxford University Innovation Limited and the authors of InfiniTAM

#pragma once

#ifndef __METALC__

#include "../../../ORUtils/Image.h"
#include "../../../ORUtils/Math.h"

namespace ITMLib
{
	/** \brief
		Stores the render state used by the SceneReconstruction
		and Visualisation engines.
		*/
	class ITMRenderState
	{
	public:
		/** @brief
		Gives the raycasting operations an idea of the
		depth range to cover

		Each pixel contains an expected minimum and maximum
		depth. The raycasting step would use this
		information to reduce the range for searching an
		intersection with the actual surface. Should be
		updated by a ITMLib::Engine::ITMVisualisationEngine
		before any raycasting operation.
		*/
		ORUtils::Image<Vector2f> *renderingRangeImage;

		/** @brief
		Float rendering output of the scene, containing the 3D
		locations in the world generated by the raycast.

		This is typically created as a by-product of
		raycasting operations.
		*/
		ORUtils::Image<Vector4f> *raycastResult;

		ORUtils::Image<Vector4f> *forwardProjection;
		ORUtils::Image<int> *fwdProjMissingPoints;
		int noFwdProjMissingPoints;

		ORUtils::Image<Vector4u> *raycastImage;

	private:
		ORUtils::Image<Vector2f> *defaultRenderingRangeImage;
		MemoryDeviceType memoryDeviceType;

	public:
		ITMRenderState(const Vector2i &imgSize, float vf_min, float vf_max, MemoryDeviceType memoryType)
			: memoryDeviceType(memoryType)
		{
			renderingRangeImage = new ORUtils::Image<Vector2f>(imgSize, memoryType);
			raycastResult = new ORUtils::Image<Vector4f>(imgSize, memoryType);
			forwardProjection = new ORUtils::Image<Vector4f>(imgSize, memoryType);
			fwdProjMissingPoints = new ORUtils::Image<int>(imgSize, memoryType);
			raycastImage = new ORUtils::Image<Vector4u>(imgSize, memoryType);

			defaultRenderingRangeImage = new ORUtils::Image<Vector2f>(imgSize, true, memoryType == MEMORYDEVICE_CUDA); // Always allocate on the CPU, to allow the call to Fill.
			defaultRenderingRangeImage->Fill(Vector2f(vf_min, vf_max));

			Reset();
		}

		virtual ~ITMRenderState()
		{
			delete defaultRenderingRangeImage;
			delete renderingRangeImage;
			delete raycastResult;
			delete forwardProjection;
			delete fwdProjMissingPoints;
			delete raycastImage;
		}

		virtual void Reset()
		{
			if(memoryDeviceType == MEMORYDEVICE_CUDA)
			{
#ifndef COMPILE_WITHOUT_CUDA
				renderingRangeImage->SetFrom(defaultRenderingRangeImage, ORUtils::MemoryBlock<Vector2f>::CUDA_TO_CUDA);
#endif
			}
			else renderingRangeImage->SetFrom(defaultRenderingRangeImage, ORUtils::MemoryBlock<Vector2f>::CPU_TO_CPU);

			noFwdProjMissingPoints = 0;
		}
	};
}

#endif
