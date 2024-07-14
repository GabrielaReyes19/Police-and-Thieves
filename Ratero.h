#pragma once
#include<vector>
using namespace std;
#include "Clase Padre.h"
#include "Trabajador.h"
#include <math.h>
#include "Policia.h"
class Ratero:public Sprite
{
public:
	Ratero(int elegir,int posx):Sprite(elegir){
		nivel = elegir;
		if (elegir == 1) {
			x =posx;
			y =15;
		}
		else {
			x = posx;
			y = 1;
		}
		ix = x;
		iy = y;
		existe = false;
		indice = 0;
		rebote = false;
	}
	~Ratero(){}
	int distancia(int x,int y,int n,int m) {
		return sqrt(pow(n-x,2) + pow(m-y,2));
	}
	void mover(vector<Trabajador*>trabajador,Policia*policia) {

		//------------&&-----------//
		if (dx > 0) fila = 2;
		if (dx < 0) fila = 1;
		if (dy > 0) fila = 0;
		if (dy < 0)fila = 3;		
		columna++; if (columna == 4)columna = 0;
		//------------&&-----------//
		int menor = 999;
		if (trabajador.size() > 0) existe = true; else existe = false;
		//------&& Verificar al trabajador mas cerca &&--------------------//
		for (int i = 0; i < trabajador.size(); i++) {
			if (distancia(x, y, trabajador.at(i)->getx(), trabajador.at(i)->gety()) < menor) {
				menor = distancia(x, y, trabajador.at(i)->getx(), trabajador.at(i)->gety());
				indice = i;
			}
		}
		//-------&& Verificar si existe colision con el policía &&------------//
		if (policia->mascara().IntersectsWith(mascara())) {
			rebote = true;
		}
		for (int i = 0; i < policia->getbala().size(); i++) {
			if (policia->getbala().at(i)->mascara().IntersectsWith(mascara())) {
				policia->eliminarBala(i); rebote = true;
			}
		}
		//------------------------------------------------------------------//
		if (existe && !rebote) {
			if (x == trabajador.at(indice)->getx()) {
				dx = 0;
			}
			else if (x < trabajador.at(indice)->getx()) {
				dx = 4;
			}
			else if (x > trabajador.at(indice)->getx()) {
				dx = -4;
			}
			if (y == trabajador.at(indice)->gety()) {
				dy = 0;
			}
			else if (y < trabajador.at(indice)->gety()) {
				dy = 4;
			}
			else if (y > trabajador.at(indice)->gety()) {
				dy = -4;
			}
		}
		else {
			//------&&--------//
			
				if (x == ix) {
					dx = 0;
				}
				else if (x < ix) {
					dx = 4;
				}
				else if (x > ix) {
					dx = -4;
				}
				if (y == iy) {
					dy = 0;
				}
				else if (y < iy) {
					dy = 4;
				}
				else if (y > iy) {
					dy = -4;
				}
			
			//------&&--------//
			if (dx == 0 && dy == 0) {
				rebote = false;
				columna = 0;
			}
			//------&&--------//
		}
	
		x += dx; y += dy;
	}
	
private:
	int ix, iy;
	int nivel;
	int indice;
	bool existe;
	bool rebote;
};

