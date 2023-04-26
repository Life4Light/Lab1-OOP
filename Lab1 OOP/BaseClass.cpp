#include "BaseClass.h"       //� ������������ ���������
extern HDC hdc;               // �������  �������� ����������
// ������� ��� �������� ��������� ����������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*----------------------------------------------------------------*/
/*                 � � � � � � � � � �    � � � � � � �           */
/*----------------------------------------------------------------*/
/*----------------------------------------*/
/*        ������ ������ Location          */
/*----------------------------------------*/
//-------------------------------------------------------------------
Location::Location(int InitX, int InitY)            //����������� � �����������
{
	X = InitX;
	Y = InitY;
	
}
//-------------------------------------------------------------------
Location::~Location()                      //����������
{
};
//-------------------------------------------------------------------
int Location::GetX()
{
	return X;
}                                //������� � �����������
//-------------------------------------------------------------------
int Location::GetY()
{
	return Y;
}                                //������� � �����������


/*----------------------------------------*/
/*        ������ ������ Point             */
/*----------------------------------------*/
//-------------------------------------------------------------------
//�����������
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = false;  //�� ��������� ������ ��������
	heights->x = InitX;
	heights->y = InitY;
	widths->x = InitX;
	widths->y = InitY;
}
//-------------------------------------------------------------------
//����������
Point::~Point()
{
}

//-------------------------------------------------------------------
void Point::Show()
{
	Visible = true;    //������ �����
	SetPixel(hdc, X, Y, RGB(0, 0, 0));   //������ ������������� ������
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));   //������ ������������� ������
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));   //������ ������������� ������
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));   //������ ������������� ������
}

//-------------------------------------------------------------------
void Point::Hide()
{
	HideHitbox();
}

//-------------------------------------------------------------------
bool Point::IsVisible() { return Visible; };

//-------------------------------------------------------------------
void Point::MoveTo(int NewX, int NewY)
{

	Hide();  //������� ������(!) ���������
	X = NewX; //�������� ����������
	Y = NewY;
	//GetHitbox();
	HideHitbox();
	Show();  //�������� ������(!) �� ����� �����
};

//-------------------------------------------------------------------
void Point::Drag(int Step)    //����������� ������
{
	int FigX, FigY;   //����� ���������� ������
	GetHitbox();
	Show();

	FigX = GetX();    //�������� ��������� ��������� ������
	FigY = GetY();

	while (1)
	{

		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
		{
			Hide();
			Show();
			break;
		}
			

		//����������� �������� �������

		if (KEY_DOWN(VK_LEFT))   //������� �����  37
		{
			FigX -= Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}

		if (KEY_DOWN(VK_RIGHT))  //������� ������  39
		{
			FigX += Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}

		if (KEY_DOWN(VK_DOWN))   //������� ����  40
		{
			FigY += Step;
			MoveTo(FigX, FigY);
			Sleep(500);

		}

		if (KEY_DOWN(VK_UP))     //������� �����  38
		{
			FigY -= Step;
			MoveTo(FigX, FigY);
			Sleep(500);

		}
	}   //while

}
POINT Point::GetHeight()
{
	heights->x = X + 2;
	heights->y = Y + 2;
	return *heights;
}
POINT Point::GetWidth()
{
	widths->x = X + 2;
	widths->y = Y + 2;
	return *widths;
}

void Point::GetHitbox()
{
	SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Rectangle(hdc, GetHeight().x, GetHeight().y, GetWidth().x, GetWidth().y);
}
void Point::HideHitbox()
{
	SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(255, 255, 255)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Rectangle(hdc, GetHeight().x, GetHeight().y, GetWidth().x, GetWidth().y);
}