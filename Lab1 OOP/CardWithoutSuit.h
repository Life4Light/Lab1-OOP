#pragma once
#include <windows.h>          // Подключим функции Windows
#include <iostream>
#include "BaseClass.h"
class CardWithoutSuit	:	public Point
{
protected:
	int X2;
	int Y2;
	int width;
	int height;
public:
	CardWithoutSuit(int left, int top, int right, int bottom, int width, int height);
	~CardWithoutSuit();
	void Show();
	
	POINT GetWidth() override;
	POINT GetHeight() override;
};
