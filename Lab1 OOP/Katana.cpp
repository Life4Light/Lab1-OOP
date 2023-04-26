#include <windows.h>          // Подключим функции Windows 

extern HDC hdc;               // объявим  контекст устройства

#include "Katana.h"       //с виртуальными функциями
//#include "CardWithoutSuit.h"       //с виртуальными функциями
// Макросы для проверки состояния клавиатуры
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

Katana::Katana(int InitX, int InitY) : Point(InitX, InitY)
{

}
Katana::~Katana()
{
}
void Katana::Show()
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));

	POINT blade[4];
	blade[0].x = X; blade[0].y = Y;
	blade[1].x = X+200; blade[1].y = Y;
	blade[2].x = X+200; blade[2].y = Y+10;
	blade[3].x = X+20; blade[3].y = Y+10;

	Visible = true;
	SelectObject(hdc, CreateSolidBrush(RGB(128, 128, 128)));
	SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));
	
	Polygon(hdc, blade, 4);
	SelectObject(hdc, Pen);
	MoveToEx(hdc,X,Y,0);
	LineTo(hdc, X + 25, Y+18);
	LineTo(hdc, X + 200, Y + 18);
	SelectObject(hdc, CreateSolidBrush(RGB(150, 75, 0)));
	Rectangle(hdc, X + 200, Y - 25, X + 210, Y + 45);
	Rectangle(hdc,X+210,Y+15,X+260,Y+3);
	SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
	Rectangle(hdc, X+250, Y+15, X+260, Y+3 );
	DeleteObject(Pen);
}

POINT Katana::GetHeight()
{
	heights->x = X-5;
	heights->y = Y-30;
	return (*heights);
}
POINT Katana::GetWidth()
{
	widths->x = X + 265;
	widths->y = Y + 50;
	return (*widths);
}
