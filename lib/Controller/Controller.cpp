#include "Controller.h"

void Controller::UpdateBrightness() {
	if (!isOn && previousTime < softStart) {
		brightness = map(previousTime, 0, softStart, 0, maxBrightness);
		accentBrightness = map(previousTime, 0, softStart, 0, maxAccentBrightness);
	} else if (!isOn) {
		brightness = maxBrightness;
		accentBrightness = maxAccentBrightness;
		isOn = true;
	}
}

Controller::Controller(CameraBase** cameras, uint8_t count, uint8_t maxBrightness, uint8_t maxAccentBrightness) {
	this->cameras = cameras;
	this->count = count;
	this->maxBrightness = maxBrightness;
	this->maxAccentBrightness = maxAccentBrightness;
	previousTime = micros();
}

CameraBase** Controller::GetCameras() {
	return cameras;
}

uint8_t Controller::GetCameraCount() {
	return count;
}

void Controller::Render(Scene* scene) {
	previousTime = micros();

	UpdateBrightness();

	for (int i = 0; i < count; i++) {
		cameras[i]->Rasterize(scene);

		if (scene->UseEffect()) {
			scene->GetEffect()->ApplyEffect(cameras[i]->GetPixelGroup());
		}
	}

	renderTime = ((float)(micros() - previousTime)) / 1000000.0f;
}

void Controller::RenderCamera(Scene* scene, uint8_t cameraNum) {
	previousTime = micros();

	UpdateBrightness();

	cameras[cameraNum]->Rasterize(scene);

	if (scene->UseEffect()) {
		scene->GetEffect()->ApplyEffect(cameras[cameraNum]->GetPixelGroup());
	}

	renderTime = ((float)(micros() - previousTime)) / 1000000.0f;
}

void Controller::SetBrightness(uint8_t maxBrightness) {
	this->maxBrightness = maxBrightness;

	if (isOn) {  // past soft start
		this->brightness = maxBrightness;
	}
}

void Controller::SetAccentBrightness(uint8_t maxAccentBrightness) {
	this->maxAccentBrightness = maxAccentBrightness;

	if (isOn) {  // past soft start
		this->accentBrightness = maxAccentBrightness;
	}
}

float Controller::GetRenderTime() {
	return renderTime;
}
