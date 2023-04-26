/********************************************************************
 *                      �  �  �  �  �     �  +  +                   *
 *------------------------------------------------------------------*
 * Project Type  : Win32 Application                                *
 * Project Name  : \�����_�++\Lesson_05_��������_���\Ex05_04_Virt   *
 * File Name     : Point05_04.�PP                                   *
 * Programmer(s) : ������� �.�.  &   ��������� �.�.                 *
 * Modifyed By   :                                                  *
 * Created       : 06/05/04                                         *
 * Last Revision : 19/10/04                                         *
 * Comment(s)    : ���������� ���� ������� �� ����                  *
 *                 ������������                                     *
 *                 ����������� ������� � Point                      *
 *                                                                  *
 ********************************************************************/

#include <windows.h>          // ��������� ������� Windows 

extern HDC hdc;               // �������  �������� ����������

#include "Card.h"       //� ������������ ���������
//#include "CardWithoutSuit.h"       //� ������������ ���������
// ������� ��� �������� ��������� ����������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)


//}
/*----------------------------------------*/
/*        ������ ������ Line              */
/*----------------------------------------*/
Card::Card(int left, int top, int right1, int bottom, int width, int height) : CardWithoutSuit(left, top,right1,bottom,width,height)
{
}
Card::~Card() {  };
void Card::Show()
{
	
	POINT apt[4];
	apt[0].x = 80+X; apt[0].y = 110 + Y;
	apt[1].x = 50+X; apt[1].y = 150 + Y;
	apt[2].x = 80+X; apt[2].y = 190 + Y;
	apt[3].x = 110+X; apt[3].y = 150 + Y;
	Visible = true;
	// ������� ���� � ���� ����


	HPEN Pen2 = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));

	CardWithoutSuit::Show();

	SelectObject(hdc, Pen2);
	LineTo(hdc, X + 15, Y + 40);
	LineTo(hdc, X + 25, Y + 20);
	LineTo(hdc, X + 35, Y + 40);
	MoveToEx(hdc, X + 35, Y + 33, 0);
	LineTo(hdc, X + 15, Y + 33);
	LineTo(hdc, X + 36, Y + 33);
	//////////������ �/////////////////
	MoveToEx(hdc, X + 135, Y + 270, 0); //135 250

	LineTo(hdc, X + 125, Y + 250);   //125 270
	LineTo(hdc, X + 135, Y + 270); //135 250
	LineTo(hdc, X + 145, Y + 250); // 145 270
	MoveToEx(hdc, X + 145, Y + 258, 0); //145 260
	LineTo(hdc, X + 125, Y + 258); //125 260

	SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
	SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));
	Polygon(hdc, apt, 4);


	DeleteObject(Pen2);
}


/******************   End of File Point05_04.�PP   ****************/
