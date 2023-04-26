#include "CardWithoutSuit.h"       //с виртуальными функциями
extern HDC hdc;               // объявим  контекст устройства
// Макросы для проверки состояния клавиатуры
CardWithoutSuit::CardWithoutSuit(int left, int top, int right, int bottom, int width, int height):Point(left,top)
{
	X2 = right;
	Y2 = bottom;
	this->width = width;
	this->height = height;
}
CardWithoutSuit::~CardWithoutSuit()
{

}
void CardWithoutSuit:: Show()
{
	Visible = true;
	// Зададим перо и цвет пера
	SelectObject(hdc,GetStockObject(WHITE_BRUSH));
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	MoveToEx(hdc, X + 25, Y + 20,0);
	SelectObject(hdc, Pen);
	RoundRect(hdc, X, Y, X2+X, Y2+Y, width, height);
	DeleteObject(Pen);

}


POINT CardWithoutSuit::GetHeight() 
{
	heights->x = X - 5;
	heights->y = Y - 5;
	return (*heights);
}
POINT CardWithoutSuit::GetWidth()
{
	widths->x = X + X2 + 5;
	widths->y = Y + Y2 + 5;
	return (*widths);
}
