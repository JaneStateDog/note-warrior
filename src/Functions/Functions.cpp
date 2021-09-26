#include "Functions.h"


Vector2 Lengthdir(float angle, float length) {
    return {(float)(cos(angle * M_PI / 180) * length), (float)(sin(angle * M_PI / 180) * length)};
}