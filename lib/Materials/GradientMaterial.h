#pragma once

#include "Material.h"
#include <Mathematics.h>
#include <Vector2D.h>
#include <EulerConstants.h>
#include <EulerAngles.h>
#include <Rotation.h>

template<size_t colorCount>
class GradientMaterial : public Material {
private:
    RGBColor rgbColors[colorCount];
    RGBColor* baseRGBColors;
    Vector2D positionOffset;
    Vector2D rotationOffset;//point to rotate about
    float gradientPeriod = 1.0f;
    float rotationAngle = 0.0f;//rotate input xyPosition
    bool isRadial = false;
    bool isStepped = false;
    float gradientShift = 0.0f;
  
public:
    GradientMaterial(RGBColor* rgbColors, float gradientPeriod, bool isRadial, bool isStepped = false);


    //x 0->1 mapping all counts of colors, linearly interpolating

    //xy offset
    //rotation offset
    //gradient period

    void SetPositionOffset(Vector2D positionOffset);
    void SetRotationOffset(Vector2D rotationOffset);

    void SetRotationAngle(float rotationAngle);
    void SetGradientPeriod(float gradientPeriod);

    void GradientShift(float ratio);
    void HueShift(float hueDeg);

    void UpdateRGB();
    
    RGBColor GetRGB(Vector3D position, Vector3D normal, Vector3D uvw) override;
};
