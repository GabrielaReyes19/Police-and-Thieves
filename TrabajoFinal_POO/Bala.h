#pragma once
using namespace System::Drawing;
class Bala
{
public:
	Bala(int x, int y, int dx,int dy) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		visible = true;
		if (dx > 0) columna = 1;
		if (dx < 0) columna = 0;
	}
	~Bala() {}
	void dibujar(Graphics^ g, Bitmap^ img) {
		g->DrawImage(img, x,y,10,10);
		x += dx; y += dy;
	}
	bool limite(Graphics^ g) {
		return x + dx <= 0 || x + dx > g->VisibleClipBounds.Width || y + dy <= 0 || y + dy > g->VisibleClipBounds.Height;
	}
	Rectangle mascara() {
		return Rectangle(x, y, 7, 7);
	}
	bool getevisible() { return visible; }
	void setvisible(bool existe) { this->visible = existe; }
private:
	bool visible;
	int x, y;
	int dx, dy;
	int columna;
};
