#pragma once
#pragma once
using namespace System::Drawing;
#include<vector>
using namespace std;
class Punto
{
public:
	Punto(int x, int y) {
		this->x = x;
		this->y = y;
	}
	~Punto() {}
	void dibujar(Graphics^ g) {
		Font^ t = gcnew Font("Arial", 8, FontStyle::Italic);
		g->FillRectangle(Brushes::Black, x, y, 40, 10);
		g->DrawString("" + x + "," + y, t, Brushes::White, x, y);

	}
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;

	}
	int getY() {
		return y;
	}
private:
	int x, y;
};
class Puntosarray
{
public:
	Puntosarray() {
		int i = 0;
		int x = 200;
		int y = 50;
		while (i < 8) {
			punto.push_back(new Punto(x, y));
			x += 70;
			i++;
		}
	}
	~Puntosarray() {}
	void dibujar(Graphics^ g) {
		for (int i = 0; i < punto.size(); i++) {
			punto.at(i)->dibujar(g);
		}
	}
	vector<Punto*>getpunto() {
		return punto;
	}
private:
	vector<Punto*>punto;
};