#pragma once
#include<vector>
using namespace std;
#include "Bala.h"
#include "Clase Padre.h"
enum Tecla{Arriba,Abajo,Derecha,Izquierda,Ninguna};
class Policia:public Sprite
{
public:
	Policia(int eleccion):Sprite(eleccion){
		if (elegir == 1) {
			x = 203;
			y = 356;
		}else{
            x = 866;
			y = 307;
		}
		direccion = 0;
	}
	~Policia(){}
	void mover() {
		switch (tecla) {
		case Arriba: fila = 3; columna++; if (columna == 4)columna = 0; dx = 0; dy = -10; direccion = 1; break;
		case Abajo: fila = 0; columna++; if (columna == 4)columna = 0; dx = 0; dy = 10; direccion = 2; break;
		case Derecha: fila = 1; columna++; if (columna == 4)columna = 0; dx = 10; dy = 0; direccion = 3; break;
		case Izquierda:fila = 2; columna++; if (columna == 4)columna = 0; dx = -10; dy = 0; direccion = 4; break;
		case Ninguna: columna = 0; dx = 0; dy = 0; break;
		}
		if (elegir == 1) {
			if (x + dx <= 0 || x + dx + (ancho * 0.4) > 1000) dx = 0;
			if (y + dy <= 0 || y + dy + (alto * 0.4) > 600) dy = 0;
		}
		else {
			if (x + dx <= 73 || x + dx + (ancho * 0.4) > 973) dx = 0;
			if (y + dy <= 97 || y + dy + (alto * 0.4) > 519) dy = 0;
		}
		x += dx; y += dy;
	}
	void cambiarTecla(Tecla var) {
		tecla = var;
	}
	void dibujarBalas(Graphics^ g, Bitmap^ img) {
		EraseBala(g);
		for (int i = 0; i < bala.size(); i++) {
			bala[i]->dibujar(g, img);
		}
	}
	void agregarBala() {
		switch (direccion) {
		case 1:bala.push_back(new Bala(x+10, y, 0,-20)); break;
		case 2:bala.push_back(new Bala(x+10, y+40,0,20)); break;
		case 3:bala.push_back(new Bala(x+20, y+20, 20,0)); break;
		case 4:bala.push_back(new Bala(x, y+20, -20,0)); break;
		}
	}
	void EraseBala(Graphics^ g) {
		for (int i = 0; i < bala.size(); i++) {
			if (bala[i]->limite(g)) {
				eliminarBala(i);
			}
		}
	}
	
	void eliminarBala(int pos) {
		bala.erase(bala.begin() + pos);
	}
	vector<Bala*>getbala() {
		return bala;
	}
	
private:
	Tecla tecla;
	int direccion;
	vector<Bala*>bala;
};

