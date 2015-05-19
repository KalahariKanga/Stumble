#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <algorithm>
#include "SFML/Graphics.hpp"


#define PI 3.14159265358979323846

#define MASK_SHAPE_RECTANGLE 1
#define MASK_SHAPE_CIRCLE 2

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define DLL _declspec(dllexport)

float DLL clamp(float value, float min, float max);
float DLL randomRange(float a, float b);