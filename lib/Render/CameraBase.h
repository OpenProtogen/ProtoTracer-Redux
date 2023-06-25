#pragma once
#ifndef __PROTOTRACER_CAMERABASE_H
#define __PROTOTRACER_CAMERABASE_H

#include <IPixelGroup.h>
#include <Scene.h>

class CameraBase {
  protected:
  public:
	CameraBase() {}

	virtual void Rasterize(Scene* scene) = 0;

	virtual IPixelGroup* GetPixelGroup() = 0;
};
#endif