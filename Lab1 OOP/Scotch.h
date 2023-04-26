#pragma once
#pragma once
#include <iostream>
#include <windows.h>          // Подключим функции Windows
#include "BaseClass.h"
class Scotch : public Point
{
protected:
	int Radius;
public:
	Scotch(int InitX,int InitY,int InitRadius);
	~Scotch();
	void Show();
	
	POINT GetWidth() override;
	POINT GetHeight() override;
	/*POINT GetWidth(void);
	POINT GetHeight(void);*/
};