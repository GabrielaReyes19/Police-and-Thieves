#pragma once
#include "Clase Padre.h"
class Ciudadano :public Sprite
{
public:
	Ciudadano(int elegir,int x,int y,int cant) :Sprite(elegir) {
		this->x = x;
		this->y = y;
	
		switch (cant) {
		case 0: dx = 0; dy = 3; break;
		case 1: dx = 3; dy = 0; break;
		case 2: dx = 0; dy = -3;break;
		case 3: dx = -3; dy = 0;break;
		}
		
	}
	~Ciudadano() {}
	void mover() {
		if (elegir == 1) {
			if (x + dx >= 482 || x + dx <= 367) dx = -dx;
			if (y + dy >= 296 || y + dy <= 209) dy = -dy;
		}
		else {
			if (x + dx >= 573 || x + dx <= 394) dx = -dx;
			if (y + dy >= 335 || y + dy <= 265) dy = -dy;
		}
		if (dx == 0 && dy > 0) fila = 0;
		if (dx < 0 && dy == 0) fila = 1;
		if (dx > 0 && dy == 0)fila = 2;
		if (dy < 0 && dx == 0)fila = 3;

		columna++; if (columna == 4)columna = 0;
		x += dx; y += dy;
	}
	
private:
	
};
