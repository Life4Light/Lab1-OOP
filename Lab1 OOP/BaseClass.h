#pragma once
#include <windows.h>          // ��������� ������� Windows 
class Location
{
protected:     //������������� ����������� �������� (������������ 
				//������) ����� ������ � ������� ������
	int X;
	int Y;

public:   //��� ������ �������� ����� ���� � ���������
	Location(int InitX, int InitY);  //����������� 
	~Location();                     //����������
	int GetX();
	int GetY();
	
};

/********************************************************************/
class Point : public Location
{
	// Point - ����������� ����� �� Location
	// ������� public � ���������� ������������ ������ ��������
	// ����������� ������ ������ �� ����� � �������, ��������������
	// �� Location

protected:  //�������, ����������� �� Point, ����������� ������ public
	bool Visible;   //�������� ����� ��� ���
	POINT heights[1];
	POINT widths[1];

public:
	Point(int InitX, int InitY);     //����������� ������
	virtual ~Point();                         //����������
	bool IsVisible();                 //������ ��� ���������� �����
	void Hide();						    //�������� ������
	virtual void Show();							 //�������� ������
	virtual POINT GetWidth();
	virtual POINT GetHeight();
	void GetHitbox();
	void HideHitbox();

	void MoveTo(int NewX, int NewY); //����������� ������
	void Drag(int Step);			//���������� ������
};

/********************************************************************/
