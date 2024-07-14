#pragma
using namespace System::Drawing;
class Provicion
{
public:
	Provicion(int nivel) {
		this->nivel = nivel;
		x = y = 0;
		
	}
	~Provicion(){}
	void dibujar(Graphics^ g,Bitmap^img1,Bitmap^img2) {
		if (nivel == 1) {
			g->DrawImage(img1, x, y, 20, 20);
		}
		else {
			g->DrawImage(img2, x, y, 20, 20);
		}	
	}
	void move(int x, int y) {
			this->x = x;
			this->y = y;
		
	}
	
	
private:
	int nivel;
	int x, y;
};
