#pragma once
#include "Ratero.h"
#include "Trabajador.h"
#include "Ciudadano.h"
#include "Policia.h"
#include "Mapa.h"
#include "Proviciones.h"
#include<iostream>
class Juego
{
public:
	Juego(int nivel,int cantCiudadanos,int cantRateros) {
		this-> nivel = nivel;
		policia = new Policia(nivel);
		mapa = new Mapa(nivel);
		segundos = 0;
		minutos = 0;
		puntos = 0;
		muertos = 0;
		//-------Agregamos---------//
	
		//------Creamos las posiciones para los ciudadanos-----//
		int x1[4]= {360,381,461,450};
		int y1[4] = {209,254,254,227};
		int x2[4]= {396,401,568,570};
		int y2[4] = {266,335,330,261};
		int i = 0;
		//-------------------&&-------------------------------//
		while (i < cantCiudadanos) {
			if (nivel == 1) {
				ciudadano.push_back(new Ciudadano(nivel, x1[i], y1[i],i)); i++;
			}
			else {
				ciudadano.push_back(new Ciudadano(nivel, x2[i], y2[i],i)); i++;
			}		
		} 
		//----agregarRatero-----//
		i = 0;
		int x = 84;
		while (i < cantRateros) {
			ratero.push_back(new Ratero(nivel, x)); i++;
			x += 300;
		}
	}
	~Juego() {}
	void agregarTrabajador() {
			trabajador.push_back(new Trabajador(nivel));
			provicion.push_back(new Provicion(nivel));
	}
	void dibujar(Graphics^ canvas, Bitmap^ img1trabajador, Bitmap^ img2trabajador, Bitmap^ imgratero1,Bitmap^imgratero2,
		Bitmap^ img1ciudadano, Bitmap^ img2ciudadano, Bitmap^ imgpolicia1,Bitmap^imgpolicia2, Bitmap^ img1mapa, Bitmap^ img2mapa,
		Bitmap^imgprovicion1,Bitmap^imgprovicion2,Bitmap^imgbala) {sss
		mapa->dibujar(canvas, img1mapa, img2mapa);
		policia->dibujar(canvas, imgpolicia1,imgpolicia2);
		policia->dibujarBalas(canvas, imgbala);
		
		for (int i = 0; i < ratero.size(); i++) {
			ratero.at(i)->dibujar(canvas,imgratero1,imgratero2);
		}
		for (int i = 0; i < trabajador.size(); i++) {
			trabajador.at(i)->dibujar(canvas, img1trabajador, img2trabajador);
		}
		for (int i = 0; i < provicion.size(); i++) {
			if (trabajador.at(i)->getlisto() == false) {
				provicion.at(i)->dibujar(canvas, imgprovicion1,imgprovicion2);
			}
		}
		for (int i = 0; i < ciudadano.size(); i++) {
			ciudadano.at(i)->dibujar(canvas, img1ciudadano, img2ciudadano);
		}
	}
	void mover() {
	
		policia->mover();
		for (int i = 0; i < ratero.size(); i++) {
			ratero.at(i)->mover(trabajador,policia);
		}
		for (int i = 0; i < trabajador.size(); i++) {
			trabajador.at(i)->mover();
			if (trabajador.at(i)->getsentido()==6 && trabajador.at(i)->getlisto()==false) {
				trabajador.at(i)->setlisto(true);
			}
		}
		for (int i = 0; i < provicion.size(); i++) {
			if (trabajador.at(i)->getlisto() == false) {
				provicion.at(i)->move(trabajador.at(i)->getx() + 20, trabajador.at(i)->gety() + 20);
			}
		}
		for (int i = 0; i < ciudadano.size(); i++) {
			ciudadano.at(i)->mover();
		}
	}
	void IniciarJuego(Graphics^ canvas, Bitmap^ img1trabajador, Bitmap^ img2trabajador, Bitmap^ imgratero1, Bitmap^ imgratero2,
		Bitmap^ img1ciudadano, Bitmap^ img2ciudadano, Bitmap^ imgpolicia1, Bitmap^ imgpolicia2, Bitmap^ img1mapa, Bitmap^ img2mapa,
		Bitmap^ imgprovicion1, Bitmap^ imgprovicion2,Bitmap^imgbala) {
		dibujar(canvas,  img1trabajador, img2trabajador,imgratero1,imgratero2,
			img1ciudadano, img2ciudadano,  imgpolicia1,imgpolicia2,img1mapa,img2mapa,imgprovicion1,imgprovicion2,imgbala);
		mover();
		eliminarTrabajador();
		tiempo(canvas);
		Puntuacion(canvas);
		misiones();
		esconder();
	}
	Policia* getpolicia() {
		return policia;
	}
	void tiempo(Graphics^canvas) {
		canvas->DrawString("Tiempo: 0" + minutos + ":" + segundos / 10, gcnew Font("Arial", 10, FontStyle::Bold), Brushes::Black, 460, 2);
		segundos++;
		if (segundos == 600) {
			segundos = 0;
			minutos++;
		}
	}
	void Puntuacion(Graphics^ canvas) {
		canvas->DrawString("Puntuacion: ", gcnew Font("Arial",10, FontStyle::Bold), Brushes::White, 785, 20);
		canvas->DrawString(""+puntos, gcnew Font("Arial", 10, FontStyle::Bold), Brushes::White, 930, 20);
		canvas->FillRectangle(Brushes::Red, 870, 20, puntos/2, 20);
		canvas->DrawRectangle(gcnew Pen(Color::Black, 3), 870, 20, 50, 20);
		for (int i = 0; i < trabajador.size(); i++) {
			if (trabajador.at(i)->getsentido() == 10 && trabajador.at(i)->getmision()==false) {
				trabajador.at(i)->cambiarmision(true);
				if (nivel == 1)
					puntos += 10;
				else puntos += 5;
			}
		}
	}
	void esconder() {
		for (int i = 0; i < trabajador.size(); i++) {
			if (trabajador.at(i)->finrecorrido()) {
				trabajador.erase(trabajador.begin() + i);
				provicion.erase(provicion.begin() + i);
			}
		}
	}
	void misiones() {
		for (int i = 0; i < trabajador.size(); i++) {
			if (trabajador.at(i)->finrecorrido() && trabajador.at(i)->getmision() == false) {
				trabajador.at(i)->cambiarmision(true);
				if (nivel == 1)
					puntos += 10;
				else puntos += 5;
			}
		}
	}
	int cantidadTrabajador() {
		return trabajador.size();
	}
	void eliminarTrabajador() {
		for (int i = 0; i < trabajador.size(); i++) {
			for (int j = 0; j < ratero.size(); j++) {
				if (trabajador.at(i)->mascara().IntersectsWith(ratero.at(j)->mascara())) {
					trabajador.at(i)->setvisible(false);
				}
			}
		}
		for (int i = 0; i < trabajador.size(); i++) {
				if (!trabajador.at(i)->getvisible()) {
					trabajador.erase(trabajador.begin() + i); provicion.erase(provicion.begin() + i);
					if (nivel == 1)  puntos -= 5;
					else puntos -= 10;
					  if (puntos < 0) puntos = 0; muertos++;
			}
		}
	}
	int getmuertos() { return muertos; }
	int getminutos() { return minutos; }
	int getpuntos() { return puntos; }
private:
	int muertos;
	int puntos;
	int nivel;
	int segundos;
	int minutos;
	vector<Trabajador*>trabajador;
	vector<Ratero*>ratero;
	vector<Ciudadano*>ciudadano;
	vector<Provicion*>provicion;
	Policia* policia;
	Mapa* mapa;
};
