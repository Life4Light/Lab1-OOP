#pragma once
#include <iostream>
#include <windows.h>          // Подключим функции Windows
#include "Card.h"
class TornCard : public Card
{
public:
	TornCard(int left, int top, int right1, int bottom, int width, int height);
	~TornCard();
	void Show();
	
	
};