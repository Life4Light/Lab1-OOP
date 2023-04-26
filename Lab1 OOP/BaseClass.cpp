#include "BaseClass.h"       //с виртуальными функциями
extern HDC hdc;               // объявим  контекст устройства
// Макросы для проверки состояния клавиатуры
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*----------------------------------------------------------------*/
/*                 Р Е А Л И З А Ц И Я    М Е Т О Д О В           */
/*----------------------------------------------------------------*/
/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Location          */
/*----------------------------------------*/
//-------------------------------------------------------------------
Location::Location(int InitX, int InitY)            //конструктор с реализацией
{
	X = InitX;
	Y = InitY;
	
}
//-------------------------------------------------------------------
Location::~Location()                      //деструктор
{
};
//-------------------------------------------------------------------
int Location::GetX()
{
	return X;
}                                //функция с реализацией
//-------------------------------------------------------------------
int Location::GetY()
{
	return Y;
}                                //функция с реализацией


/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Point             */
/*----------------------------------------*/
//-------------------------------------------------------------------
//конструктор
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = false;  //по умолчанию фигура невидима
	heights->x = InitX;
	heights->y = InitY;
	widths->x = InitX;
	widths->y = InitY;
}
//-------------------------------------------------------------------
//деструктор
Point::~Point()
{
}

//-------------------------------------------------------------------
void Point::Show()
{
	Visible = true;    //фигуру видно
	SetPixel(hdc, X, Y, RGB(0, 0, 0));   //рисуем установленным цветом
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));   //рисуем установленным цветом
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));   //рисуем установленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));   //рисуем установленным цветом
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

	Hide();  //сделать фигуру(!) невидимой
	X = NewX; //поменять координаты
	Y = NewY;
	//GetHitbox();
	HideHitbox();
	Show();  //показать фигуру(!) на новом месте
};

//-------------------------------------------------------------------
void Point::Drag(int Step)    //перемещение фигуры
{
	int FigX, FigY;   //новые координаты фигуры
	GetHitbox();
	Show();

	FigX = GetX();    //получаем начальное положение фигуры
	FigY = GetY();

	while (1)
	{

		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
		{
			Hide();
			Show();
			break;
		}
			

		//направление движения объекта

		if (KEY_DOWN(VK_LEFT))   //стрелка влево  37
		{
			FigX -= Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}

		if (KEY_DOWN(VK_RIGHT))  //стрелка вправо  39
		{
			FigX += Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}

		if (KEY_DOWN(VK_DOWN))   //стрелка вниз  40
		{
			FigY += Step;
			MoveTo(FigX, FigY);
			Sleep(500);

		}

		if (KEY_DOWN(VK_UP))     //стрелка вверх  38
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