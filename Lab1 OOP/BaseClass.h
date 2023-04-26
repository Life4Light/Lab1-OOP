#pragma once
#include <windows.h>          // Подключим функции Windows 
class Location
{
protected:     //предоставляет возможность потомкам (производному 
				//классу) иметь доступ к частным данным
	int X;
	int Y;

public:   //эти методы доступны извне всем в программе
	Location(int InitX, int InitY);  //конструктор 
	~Location();                     //деструктор
	int GetX();
	int GetY();
	
};

/********************************************************************/
class Point : public Location
{
	// Point - производный класс от Location
	// атрибут public в объявлении производного класса означает
	// возможность вызова любого из полей и методов, унаследованных
	// от Location

protected:  //классам, производным от Point, потребуется доступ public
	bool Visible;   //светится точка или нет
	POINT heights[1];
	POINT widths[1];

public:
	Point(int InitX, int InitY);     //конструктор класса
	virtual ~Point();                         //деструктор
	bool IsVisible();                 //узнать про светимость точки
	void Hide();						    //спрятать фигуру
	virtual void Show();							 //показать фигуру
	virtual POINT GetWidth();
	virtual POINT GetHeight();
	void GetHitbox();
	void HideHitbox();

	void MoveTo(int NewX, int NewY); //переместить фигуру
	void Drag(int Step);			//буксировка фигуры
};

/********************************************************************/
