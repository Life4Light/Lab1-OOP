#include "TornCard.h"
extern HDC hdc;
TornCard :: TornCard(int left, int top, int right1, int bottom, int width, int height) : Card(left, top, right1, bottom, width, height)
{

}
TornCard::~TornCard()
{

}
void TornCard :: Show()
{
	POINT triangle[4];
	triangle[0].x = X-2 ; triangle[0].y = Y+250;
	triangle[1].x = X+160; triangle[1].y = Y+70;
	triangle[3].x = X-2; triangle[3].y = Y+300;
	triangle[2].x = X+160; triangle[2].y = Y + 300;
	Card::Show();
	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	HPEN Pen2 = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));

	SelectObject(hdc, Pen);
	MoveToEx(hdc, X, Y + 250,0);
	LineTo(hdc,X + 160,Y + 70);
	SelectObject(hdc, Pen2);
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Polygon(hdc, triangle, 4);
	SelectObject(hdc, Pen);
	MoveToEx(hdc, X, Y + 245, 0);
	LineTo(hdc, X + 160, Y + 70);
	DeleteObject(Pen); DeleteObject(Pen2);
}
