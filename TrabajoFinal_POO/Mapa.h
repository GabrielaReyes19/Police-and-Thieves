#pragma once
using namespace System::Drawing;

class Mapa
{
public:
	Mapa(int elegir) {
		nivel = elegir;
	}
	~Mapa(){}
	void dibujar(Graphics^ g, Bitmap^ img1, Bitmap^ img2) {
		if (nivel == 1) {
			g->DrawImage(img1, 0, 0, 1000, 600);
		}
		else {
			g->DrawImage(img2, 0, 0, 1000, 600);
		}
	}
private:
	int nivel;
};