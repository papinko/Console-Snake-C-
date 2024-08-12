#pragma once
#include "snake.h"
#include "eat.h"
#include "parameters.h"

struct Print
{
public:
	void menu();
	void results(Snake* p_snake, Eat* p_eat, Parameter* p_parameter);
	void Read();
};
