#include "Mathematics.h"

String Mathematics::DoubleToCleanString(float value) {
	return String(value, 4);
}

bool Mathematics::IsNaN(float value) {
	return value != value;
}

bool Mathematics::IsInfinite(float value) {
	return isinf(value);
}

bool Mathematics::IsFinite(float value) {
	return isfinite(value);
}

bool Mathematics::IsClose(float v1, float v2, float epsilon) {
	return fabs(v1 - v2) < epsilon;
}

int Mathematics::Sign(float value) {
	return (0 < value) - (value < 0);
}

float Mathematics::Pow(float value, float exponent) {
	union {
		float d;
		int x[2];
	}

	u = {value};
	u.x[1] = (int)(exponent * (u.x[1] - 1072632447) + 1072632447);
	u.x[0] = 0;

	return u.d;
}

float Mathematics::Sqrt(float value) {
	return sqrtf(value);
}

float Mathematics::Fract(float value) {
	return value - floor(value);
}

float Mathematics::CosineInterpolation(float beg, float fin, float ratio) {
	float mu2 = (1.0f - cosf(ratio * MPI)) / 2.0f;

	return (beg * (1.0f - mu2) + fin * mu2);
}

float Mathematics::BounceInterpolation(float beg, float fin, float ratio) {
	// logarithm added with diminshing sine wave
	// log max amplitude = 1 - sine max amplitude / 2
	float baseLog = log10f(10.0f * ratio + 1.0f);
	float baseSine = sinf(16.0f * ratio) * powf((2.0f * ratio - 2.0f), 2.0f) / 4.0f / 4.0f;
	float bounce = baseLog + baseSine;

	return Map(ratio, 0.0f, bounce, beg, fin);
}

int Mathematics::RoundUpWindow(int value, int multiple) {
	if (multiple == 0)
		return value;

	int remainder = abs(value) % multiple;
	if (remainder == 0)
		return value;

	if (value < 0)
		return -(abs(value) - remainder);
	else
		return value + multiple - remainder;
}
