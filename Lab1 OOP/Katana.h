#pragma once
#include <iostream>
#include <windows.h>          // ��������� ������� Windows
#include "BaseClass.h"
class Katana : public Point
{
public:
	Katana(int InitX, int InitY);
	~Katana();
	void Show();

	POINT GetWidth() override;
	POINT GetHeight() override;
};