#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <algorithm>
#include "SFML/Graphics.hpp"

#define PI 3.14159265358979323846

#define MASK_SHAPE_RECTANGLE 1
#define MASK_SHAPE_CIRCLE 2

float clamp(float value, float min, float max);