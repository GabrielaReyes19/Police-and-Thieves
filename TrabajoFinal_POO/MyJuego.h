#pragma once
#include "Controladora.h"
#include "Guia de Posicion.h"
#include "formGameOver.h"
#include "formYouWin.h"
namespace TrabajoFinalPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyJuego
	/// </summary>
	public ref class MyJuego : public System::Windows::Forms::Form
	{
	public:
		MyJuego(int n1,int n2,int n3,int n4,int tiempo)
		{
			InitializeComponent();
			punto = new Puntosarray();
			canvas = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(canvas, this->ClientRectangle);
			juego = new Juego(n1, n4,n2);
			Policia1 = gcnew Bitmap("Imagenes//policia1.png"); 
			Policia2 = gcnew Bitmap("Imagenes//policia2.png"); 
			Ratero1 = gcnew Bitmap("Imagenes//ratero1.png");
			Ratero2 = gcnew Bitmap("Imagenes//ratero2.png");
			Trabajador1 = gcnew Bitmap("Imagenes//trabajador1.png");
			Trabajador2 = gcnew Bitmap("Imagenes//trabajador1.png");
			ciudadano1 = gcnew Bitmap("Imagenes//ciudadano1.png");
			ciudadano2 = gcnew Bitmap("Imagenes//ciudadano1.png");
			fondo1 = gcnew Bitmap("Imagenes//mapa1.png");
			fondo2 = gcnew Bitmap("Imagenes//mapa2.png");
			proviciones1 = gcnew Bitmap("Imagenes//Proviciones1.png");
			proviciones2 = gcnew Bitmap("Imagenes//Proviciones2.png");
			imgbala = gcnew Bitmap("Imagenes//bala.png");
			cantTrabajadores = n3;
			cantRateros = n2;
			this->tiempo = tiempo;
			listo = false;
			cancion = gcnew SoundPlayer("musicgame.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyJuego()
		{
			if (components)
			{
				delete components;
			}
			cancion->Stop();
			timer1->Enabled = false;
			delete canvas, buffer, espacio;
		}

	private:
		bool listo;
		int tiempo;
		Puntosarray* punto;
		Juego* juego;
		SoundPlayer^ cancion;
		Graphics^ canvas;
		Bitmap^ Policia1,^Policia2,^ Ratero1,^Ratero2, ^ Trabajador1, ^ Trabajador2, ^ ciudadano1, ^ ciudadano2, ^ fondo1, ^ fondo2,
			^ proviciones1,^proviciones2,^imgbala;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		int cantTrabajadores;
		int cantRateros;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyJuego::timer1_Tick);
			// 
			// MyJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 581);
			this->Name = L"MyJuego";
			this->Text = L"MyJuego";
			this->Load += gcnew System::EventHandler(this, &MyJuego::MyJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyJuego::MyJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyJuego::MyJuego_KeyUp);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyJuego::MyJuego_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyJuego::MyJuego_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: 
		void showGameOver() {
			formGameOver^ gameover = gcnew formGameOver();
			gameover->ShowDialog();
		}
		void showYouWin() {
			formYouWin^ youwin = gcnew formYouWin();
			youwin->ShowDialog();
		}

	private: System::Void MyJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up) {
			juego->getpolicia()->cambiarTecla(Arriba);
		}if (e->KeyCode == Keys::Down) {
			juego->getpolicia()->cambiarTecla(Abajo);
		}if (e->KeyCode == Keys::Left) {
			juego->getpolicia()->cambiarTecla(Izquierda);
		}if (e->KeyCode == Keys::Right) {
			juego->getpolicia()->cambiarTecla(Derecha);
		}if (e->KeyCode == Keys::Space && juego->cantidadTrabajador()<cantTrabajadores-juego->getmuertos() ) {
			juego->agregarTrabajador(); 
		}if (e->KeyCode == Keys::S) {
			juego->getpolicia()->agregarBala();
		}
	}
	private: System::Void MyJuego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->getpolicia()->cambiarTecla(Ninguna);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		juego->IniciarJuego(buffer->Graphics, Trabajador1, Trabajador2, Ratero1,Ratero2,
			ciudadano1, ciudadano2, Policia1,Policia2, fondo1, fondo2,proviciones1,proviciones2,imgbala);
		punto->dibujar(buffer->Graphics);
		punto->dibujar(buffer->Graphics);
		buffer->Render(canvas);

		if (juego->getminutos() == tiempo) {
			timer1->Enabled = false; this->Hide(); showGameOver();
		}
		if (juego->getpuntos() == 100) {
			timer1->Enabled = false; this->Hide(); showYouWin();
		}
	}
	private: System::Void MyJuego_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			for (int i = 0; i < punto->getpunto().size(); i++) {
				if (e->X >= this->punto->getpunto().at(i)->getX() && e->X <= punto->getpunto().at(i)->getX() + 50 &&
					e->Y >= this->punto->getpunto().at(i)->getY() && e->Y <= this->punto->getpunto().at(i)->getY() + 50)
				{
					this->punto->getpunto().at(i)->move(e->X - 25, e->Y - 25);
				}
			}
		}
	}
	private: System::Void MyJuego_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			for (int i = 0; i < punto->getpunto().size(); i++) {
				if (e->X >= this->punto->getpunto().at(i)->getX() && e->X <= punto->getpunto().at(i)->getX() + 50 &&
					e->Y >= this->punto->getpunto().at(i)->getY() && e->Y <= this->punto->getpunto().at(i)->getY() + 50)
				{
					this->punto->getpunto().at(i)->move(e->X - 25, e->Y - 25);
				}
			}
		}
	}
private: System::Void MyJuego_Load(System::Object^ sender, System::EventArgs^ e) {
	cancion->PlayLooping();
}
};
}
