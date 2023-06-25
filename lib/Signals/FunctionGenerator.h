#pragma once

#include "Arduino.h"
#include <Mathematics.h>

class FunctionGenerator{
public:
    enum Function{
        Triangle,
        Square,
        Sine,
        Sawtooth
    };

private:
    Function function;
    float minimum = 0.0f;
    float maximum = 0.0f;
    float period = 0.0f;

    float TriangleWave(float ratio);
    float SquareWave(float ratio);
    float SineWave(float ratio);
    float SawtoothWave(float ratio);

public:
    FunctionGenerator(Function function, float minimum, float maximum, float period);

    float Update();
};
