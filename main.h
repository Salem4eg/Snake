#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <chrono>
#include <random>
#include <fstream>

enum Language { english, ukrainian, notDefined };

struct coord
{
	int x, y;
	coord(int x = 0, int y = 0) : x(x), y(y) {}
};
