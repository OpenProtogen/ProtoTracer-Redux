#pragma once
#ifndef __PROTOTRACER_CONTROLLER_H
#define __PROTOTRACER_CONTROLLER_H

#include <CameraBase.h>
#include "Arduino.h"

class Controller {
  private:
	const float softStart = 3000000;  // microseconds
	long previousTime;
	CameraBase** cameras;
	uint8_t count = 0;
	float renderTime = 0.0f;
	uint8_t maxBrightness;
	uint8_t maxAccentBrightness;
	bool isOn = false;

	void UpdateBrightness();

  protected:
	uint8_t brightness;
	uint8_t accentBrightness;

	Controller(CameraBase** cameras, uint8_t count, uint8_t maxBrightness, uint8_t maxAccentBrightness);

  public:
	CameraBase** GetCameras();

	uint8_t GetCameraCount();

	void Render(Scene* scene);

	void RenderCamera(Scene* scene, uint8_t cameraNum);

	void SetBrightness(uint8_t maxBrightness);

	void SetAccentBrightness(uint8_t maxAccentBrightness);

	virtual void Initialize() = 0;
	virtual void Display() = 0;

	float GetRenderTime();
};

#endif