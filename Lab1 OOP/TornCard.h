#pragma once
#include <iostream>
#include <windows.h>          // ��������� ������� Windows
#include "Card.h"
class TornCard : public Card
{
public:
	TornCard(int left, int top, int right1, int bottom, int width, int height);
	~TornCard();
	void Show();
	
	
};