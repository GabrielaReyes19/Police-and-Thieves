#pragma once
#include "Clase Padre.h"
class Trabajador :public Sprite
{
public:
	Trabajador(int elegir) :Sprite(elegir) {
		nivel = elegir;
		if (nivel == 1) {
			x = 952;
			y = 500;
			dy = 0; dx = -3;
		}
		else {
			x = 99;
			y = 599;
			dy = -3; dx = 0;
		}
		sentido = 1;
		misionlisto = false;
		listo = false;
		visible = true;
	}
	~Trabajador() {}

	void mover() {
		if (nivel == 1) {
			if (sentido == 1 && x <= 867) { sentido = 2; dy = -3;dx = 0; }//
			if (sentido == 2 && y <= 405) { sentido = 3; dy = 0; dx = -3; }//
			if (sentido == 3 && x <= 505) { sentido = 4; dy = -3;dx =0; }//
			if (sentido == 4 && y <= 237) { sentido = 5; dy = 0;dx = -3; }//
			if (sentido == 5 && x <= 349) { sentido = 6; dy = 0;dx = -3; }//
			if (sentido == 6 && x <= 84) { sentido = 7;  dy = 3;dx = 0; }//
			if (sentido == 7 && y >= 460) { sentido = 8; dy = 0; dx = 3; }
			if (sentido == 8 && x >= 206) { sentido = 9; dy = 3; dx = 0; }
			if (sentido == 9 && y >= 547) { sentido = 10;dy = 0; dx = 0; }

		}
		else {
			if (sentido == 1 && y <= 435) { sentido = 2; dy = 0;dx = 3; }
			if (sentido == 2 && x >= 317) { sentido = 3; dy = -3; dx = 0; }
			if (sentido == 3 && y <= 289) { sentido = 4; dy = 0;dx = 3; }
			if (sentido == 4 && x >= 491) { sentido = 5; dy = 3; dx = 0; }
			if (sentido == 5 && y >= 331) { sentido = 6; dy = 0; dx = 3; }
			if (sentido == 6 && x >= 596) { sentido = 7; dy = 3;dx = 0; }
			if (sentido == 7 && y >= 478) { sentido = 8; dy = 0; dx = 3; }
			if (sentido == 8 && x >= 818) { sentido = 9; dy = 3;dx = 0; }
			if (sentido == 9 && y >= 555) { sentido = 10;dy = 0; dx = 0; }
			//-------------------------&&-----------------------//
		}
		if (dx == 0 && dy > 0) fila = 0;
		if (dx < 0 && dy == 0) fila = 1;
		if (dx > 0 && dy == 0)fila = 2;
		if (dy < 0 && dx == 0)fila = 3;

			columna++; if (columna == 4)columna = 0;
		
		//------------------------&&-----------------------//
		x += dx; y += dy;
	}
	int getsentido() { return sentido; }
	void cambiarmision(bool var) { misionlisto = var; }
	bool getmision() { return misionlisto; }
	bool getlisto() { return listo; }
	void setlisto(int var) { listo = var; }
	bool finrecorrido() {
		return dx == 0 && dy == 0;
	}
	bool getvisible() { return visible; }
	void setvisible(bool visible) { this->visible = visible; }
private:
	bool visible;
	int nivel;
	bool listo;
	int sentido;
	bool misionlisto;
};
