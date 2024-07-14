#pragma once
using namespace System::Drawing;
#include<vector>
using namespace std;
class Sprite
{
public:
	Sprite(int elegir){
		this->elegir = elegir;
		fila = columna = 0;
		x = y = 0;
		dx = dy = 0;
		ancho = 65;
		alto = 107;
	}
	~Sprite(){}
	void dibujar(Graphics^canvas,Bitmap^img1,Bitmap^img2) {
	 
		Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho*0.5, alto*0.5);
		if (elegir == 1) {
			canvas->DrawImage(img1, zoom, frame, GraphicsUnit::Pixel);
		}
		else {
			canvas->DrawImage(img2, zoom, frame, GraphicsUnit::Pixel);
		}
	}
	Rectangle mascara() { return Rectangle(x, y, ancho * 0.5 - 10, alto * 0.5 - 10); }
	int getx() { return x; }
	int gety() { return y; }
	void setx(int var) { x = var; }
	void sety(int var) { y = var; }
	void setdx(int var) { dx = var; }
	void setdy(int var) { dy = var; }
protected:
	int x, y;
	int dx, dy;
	int fila, columna;
	int ancho, alto;
	int elegir;
};
