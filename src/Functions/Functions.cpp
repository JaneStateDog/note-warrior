#include "Functions.h"

#include <cmath>


Vector2 Lengthdir(float angle, float length) { return {(float)(cos(angle * M_PI / 180) * length), (float)(sin(angle * M_PI / 180) * length)}; }
float ValueFromTwoRanges(float oldMin, float oldMax, float inputValue, float newMin, float newMax) { return (float)((((inputValue - oldMin) * (newMax - newMin)) / (oldMax - oldMin)) + newMin); }