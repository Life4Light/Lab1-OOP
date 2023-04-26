#pragma once
#include <windows.h>          // Подключим функции Windows 

extern HDC hdc;               // объявим  контекст устройства

#include "Scotch.h"       //с виртуальными функциями
//#include "CardWithoutSuit.h"       //с виртуальными функциями
// Макросы для проверки состояния клавиатуры
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
Scotch::Scotch(int InitX, int InitY, int InitRad) : Point(InitX, InitY)
{
	Radius = InitRad;
}
Scotch::~Scotch() 
{

}
void Scotch::Show()
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HPEN Pen2 = CreatePen(PS_SOLID, 40, RGB(255, 248, 0));
	SelectObject(hdc,Pen2);
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);
	SelectObject(hdc, Pen);
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Ellipse(hdc, X-Radius, Y - Radius, X + Radius, Y + Radius);
}

POINT Scotch::GetWidth()
{
	widths->x = 2*Radius + X;
	widths->y = 2*Radius + Y;
	return *widths;
}
POINT Scotch::GetHeight()
{
	heights->x = X - 2*Radius ;
	heights->y = Y - 2*Radius;
	return *heights;
}