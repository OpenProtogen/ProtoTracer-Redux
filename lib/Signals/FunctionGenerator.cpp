#include "FunctionGenerator.h"

FunctionGenerator::FunctionGenerator(Function function, float minimum, float maximum, float period) {
	this->function = function;
	this->minimum = minimum;
	this->maximum = maximum;
	this->period = period;
}

float FunctionGenerator::Update() {
	float currentTime = fmod(micros() / 1000000.0f, period);
	float ratio = currentTime / period;

	switch (function) {
		case Triangle:
			return TriangleWave(ratio);
			break;
		case Square:
			return SquareWave(ratio);
			break;
		case Sine:
			return SineWave(ratio);
			break;
		case Sawtooth:
			return SawtoothWave(ratio);
			break;
		default:
			return 0.0f;
			break;
	}
}

float FunctionGenerator::TriangleWave(float ratio) {
	float wave = (ratio > 0.5f ? 1.0f - ratio : ratio) * 2.0f;

	return Mathematics::Map(wave, 0.0f, 1.0f, minimum, maximum);
}

float FunctionGenerator::SquareWave(float ratio) {
	float wave = ratio > 0.5f ? 1.0f : 0.0f;

	return Mathematics::Map(wave, 0.0f, 1.0f, minimum, maximum);
}

float FunctionGenerator::SineWave(float ratio) {
	float wave = sinf(ratio * 360.0f * 3.14159f / 180.0f);

	return Mathematics::Map(wave, -1.0f, 1.0f, minimum, maximum);
}

float FunctionGenerator::SawtoothWave(float ratio) {
	return Mathematics::Map(ratio, 0.0f, 1.0f, minimum, maximum);
}