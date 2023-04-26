/**************************************************************************
*                      К  У  Р  С      О  О  П                            *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : \Курсы_С++\Lesson_05_Принципы _ООП\Ex05_02              *
* Project Type  : Win32 Console application                               *
* File Name     : Lektsii2.cpp                                            *
* Language      : Visual C++           MS VS 2015                         *
* Programmer(s) : Луганский А.                                            *
* Modified By   : Луганский А.                                            *
* Created       : 15 / 04 / 2023                                          *
* Last Revision : 15 / 04 / 2023                                          *
* Comment(s)    : Рисует на рабочем столе по вертикали 6 точек            *
*                 и линию                                                *
*                                                                         *
***************************************************************************/

#pragma once                  
#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>   
#include "TornCard.h"
#include "Katana.h"
#include "Scotch.h"
using namespace std;           // Пространство имен std
//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

HDC hdc;// Объявим контекст устройства
		// Контекст устройства по сути это структура,
		// содержащая описание видеокарты на вашем компьютере
		// и всех необходимых графических элементов

/*---------------------------------------------------------------------*/
/*               П Р О Т О Т И П Ы    Ф У Н К Ц И Й                    */
/*---------------------------------------------------------------------*/
HWND GetConcolWindow(); //указатель на консольное окно
void PressKey(int VkCode)
{
	while (1)
		if (KEY_DOWN(VkCode))
			break;
}
void Game(Point *card, Katana *katana, Scotch *scotch, TornCard *tornCard, int step);
bool is_figure_intersec(Point* f1, Point* f2);

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
void main()
{
	//объявление и инициализация переменных
	int x0 = 100;	//стартовые координаты точки
	int y0 = 200;
	int x1 = 160;	//для квадрата
	int y1 = 300;
	int xk = 500;	//стартовые координаты катаны
	int yk = 200;
	int xs = 650;
	int ys = 400;
	int width0 = 30;
	int height0 = 30;
	int Radius0 = 25;
	int DeltaRad = 20;
	int RingW0 = 20;
	int DeltaWide = 10;
	
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			//===================================================================
			//	М Е С Т О    В С Т А В К И 	
			/***************** Точка *********************/
			
			Point* pPoint;
			Point APoint(x0, y0);//Инициализации точки
			
			//pPoint = &APoint;
			//pPoint->Show();//Показать точку
			//PressKey(49);
			//APoint.Hide();
			CardWithoutSuit* ACardWithoutSuit=new CardWithoutSuit(x0, y0, x1, y1, width0, height0);
			//ACardWithoutSuit.Show();
			//PressKey(50);
			//ACardWithoutSuit.Hide();
			Point* ACard=new Card(x0, y0, x1, y1, width0, height0);
			//ACard.Show();
			//PressKey(51);
			//ACard.Hide();
			//PressKey(52);
			//ACard.Drag(40);
			//
			Katana* AKatana=new Katana(xk, yk);
			//AKatana.Show();
			//PressKey(53);
			//AKatana.Drag(20);
			//
			Scotch* AScotch= new Scotch(xs,ys,Radius0);
			//AScotch.Show();
			//PressKey(54);
			//AScotch.Drag(20);
			//PressKey(55);
			//ACard.Hide();
			TornCard* ATornCard = new TornCard(x0, y0, x1, y1, width0, height0);
			//ATornCard.Show();
			//PressKey(56);
			//ATornCard.Drag(20);
			
			Game(ACard, AKatana, AScotch,ATornCard,10);
			
			//===================================================================
		}//end if
	}//end if

}//end main()

/*---------------------------------------------------------------------*/
/*               Р Е А Л И З А Ц И Я   Ф У Н К Ц И Й                   */
/*---------------------------------------------------------------------*/
void Game(Point *card, Katana *katana, Scotch *scotch,TornCard *tornCard, int step)
{
	Point* cardCurrent = card;
	int cardX, cardY, katanaX, katanaY, scotchX, scotchY, startKatanaX, startKatanaY, startCardX, startCardY, startScotchX, startScotchY;   //новые координаты фигуры
	//card1->GetHitbox();
	cardCurrent->Show();
	//katana1->GetHitbox();
	katana->Show();
	//scotch1->GetHitbox();
	scotch->Show();

	startCardX = cardX = cardCurrent->GetX();    //получаем начальное положение фигуры
	startCardY = cardY = cardCurrent->GetY();
	startKatanaX = katanaX = katana->GetX();    //получаем начальное положение фигуры
	startKatanaY = katanaY = katana->GetY();
	startScotchX = scotchX = scotch->GetX();    //получаем начальное положение фигуры
	startScotchY = scotchY = scotch->GetY();


	while (1)
	{

		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27
		{
			katana->Hide();
			katana->Show();
			scotch->Hide();
			scotch->Show();
			cardCurrent->Hide();
			cardCurrent->Show();
			break;
		}


		//направление движения объекта

		if (KEY_DOWN(VK_LEFT))   //стрелка влево  37
		{
			katanaX -= step;
			katana->MoveTo(katanaX, katanaY);
			Sleep(25);
		}

		if (KEY_DOWN(VK_RIGHT))  //стрелка вправо  39
		{
			katanaX += step;
			katana->MoveTo(katanaX, katanaY);
			Sleep(25);
		}

		if (KEY_DOWN(VK_DOWN))   //стрелка вниз  40
		{
			katanaY += step;
			katana->MoveTo(katanaX, katanaY);
			Sleep(25);

		}

		if (KEY_DOWN(38))     //стрелка вверх  38
		{
			katanaY -= step;
			katana->MoveTo(katanaX, katanaY);
			Sleep(25);

		}
		if (KEY_DOWN(87)	)	//w(вверх) 119
		{
			cardY -= step;
			cardCurrent->MoveTo(cardX, cardY);
			Sleep(25);

		}
		if (KEY_DOWN(65))		//a(влево) 97
		{
			cardX -= step;
			cardCurrent->MoveTo(cardX, cardY);
			Sleep(25);

		}
		if (KEY_DOWN(68))		//d(вправо) 100
		{
			cardX += step;
			cardCurrent->MoveTo(cardX, cardY);
			Sleep(25);

		}
		if (KEY_DOWN(83))		//s(вниз) 115
		{
			cardY += step;
			cardCurrent->MoveTo(cardX, cardY);
			Sleep(25);

		}

		if (KEY_DOWN(85))	//u(вверх) 85
		{
			scotchY -= step;
			scotch->MoveTo(scotchX, scotchY);
			Sleep(25);

		}
		if (KEY_DOWN(72))		//h(влево) 97
		{
			scotchX -= step;
			scotch->MoveTo(scotchX, scotchY);
			Sleep(25);

		}
		if (KEY_DOWN(75))		//k(вправо) 100
		{
			scotchX += step;
			scotch->MoveTo(scotchX, scotchY);
			Sleep(25);

		}
		if (KEY_DOWN(74))		//j(вниз) 115
		{
			scotchY += step;
			scotch->MoveTo(scotchX, scotchY);
			Sleep(25);

		}
		if (is_figure_intersec(cardCurrent, katana))
		{
			cardCurrent->MoveTo(startCardX, startCardY);
			katanaX = startKatanaX;
			katanaY = startKatanaY;
			katana->MoveTo(startKatanaX, startKatanaY);
			cardCurrent->Show();
			cardX = startCardX;
			cardY = startCardY;
			
			cardCurrent->Hide();
			cardCurrent = tornCard;
			cardCurrent->MoveTo(startCardX, startCardY);
			cardCurrent->Show();
			
		}

		if (is_figure_intersec(cardCurrent, scotch))
		{
			scotchX = startScotchX;
			scotchY = startScotchY;
			scotch->MoveTo(startScotchX, startScotchY);
			//card1->Show();

			cardCurrent->Hide();
			cardCurrent = card;
			cardX = startCardX;
			cardY = startCardY;
			cardCurrent->MoveTo(startCardX+10, startCardY+10);
			/*card1->Hide();
			card1->Show();*/

		}
		if (is_figure_intersec(katana, scotch))
		{
			katanaX = startKatanaX;
			katanaY = startKatanaY;
			katana->MoveTo(startKatanaX, startKatanaY);
			scotchX = startScotchX;
			scotchY = startScotchY;
			scotch->MoveTo(startScotchX, startScotchY);

		}
	}   //while
}
bool is_figure_intersec(Point* f1, Point* f2)
{
	int x0 = f1->GetHeight().x;
	int y0 = f1->GetHeight().y;
	int x1 = f1->GetWidth().x;
	int y1 = f1->GetWidth().y;

	int x2 = f2->GetHeight().x;
	int y2 = f2->GetHeight().y;
	int x3 = f2->GetWidth().x;
	int y3 = f2->GetWidth().y;

	return !(x0 > x3 || x1 < x2 || y0 > y3 || y1 < y2);

}


/*----------------------------------------------------------------------*/
/*  Создать консольное окно  */
/*---------------------------*/
HWND GetConcolWindow()
{
	char str[128];
	// char title[128]="xxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";	//новая версия Windows
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // получить заголовок окна
	SetConsoleTitle(title);						// установить новый заголовок окна
	Sleep(100);									// ждем смены заголовка окна (100 мс);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);// определяем дескриптор окна
	SetConsoleTitle((LPWSTR)str);				//возвращаем прежний заголовок

	return hwnd;//вернуть дескриптор окна
}//end GetConcolWindow()

/**********************  End Of Ex05_02_Con.CPP File ********************/
