#pragma once
#include "MenuOpciones.h"
#include "MyJuego.h"
#include "formGameOver.h";
#include "formYouWin.h"
#include "formInstrucciones.h"
namespace TrabajoFinalPOO {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuInicio : public System::Windows::Forms::Form
	{
	public:
		MenuInicio(void)
		{
			InitializeComponent();
		
			
	
		}

	protected:

		~MenuInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ imgMenu;


		   System::ComponentModel::Container^ components;
	private:
		//formJuego^ fjuego;
		MenuOpciones^ fopciones;
		MyJuego^ fjuego;
		int n1, n2, n3, n4, tiempo;
	private: System::Windows::Forms::Button^ btnPlay2;
	private: System::Windows::Forms::Button^ btnOpciones2;
	private: System::Windows::Forms::Button^ btnInstrucciones;

		
		
#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuInicio::typeid));
			this->imgMenu = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay2 = (gcnew System::Windows::Forms::Button());
			this->btnOpciones2 = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMenu))->BeginInit();
			this->SuspendLayout();
			// 
			// imgMenu
			// 
			this->imgMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgMenu.Image")));
			this->imgMenu->Location = System::Drawing::Point(-12, -1);
			this->imgMenu->Name = L"imgMenu";
			this->imgMenu->Size = System::Drawing::Size(577, 445);
			this->imgMenu->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgMenu->TabIndex = 0;
			this->imgMenu->TabStop = false;
			this->imgMenu->Click += gcnew System::EventHandler(this, &MenuInicio::imgMenu_Click);
			// 
			// btnPlay2
			// 
			this->btnPlay2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnPlay2->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlay2->Location = System::Drawing::Point(158, 102);
			this->btnPlay2->Name = L"btnPlay2";
			this->btnPlay2->Size = System::Drawing::Size(245, 60);
			this->btnPlay2->TabIndex = 1;
			this->btnPlay2->Text = L"Play";
			this->btnPlay2->UseVisualStyleBackColor = false;
			this->btnPlay2->Click += gcnew System::EventHandler(this, &MenuInicio::btnPlay2_Click_1);
			// 
			// btnOpciones2
			// 
			this->btnOpciones2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnOpciones2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpciones2->Location = System::Drawing::Point(158, 193);
			this->btnOpciones2->Name = L"btnOpciones2";
			this->btnOpciones2->Size = System::Drawing::Size(245, 61);
			this->btnOpciones2->TabIndex = 2;
			this->btnOpciones2->Text = L"Opciones";
			this->btnOpciones2->UseVisualStyleBackColor = false;
			this->btnOpciones2->Click += gcnew System::EventHandler(this, &MenuInicio::btnOpciones2_Click_1);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(158, 286);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(245, 57);
			this->btnInstrucciones->TabIndex = 3;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MenuInicio::btnInstrucciones_Click);
			// 
			// MenuInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 440);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnOpciones2);
			this->Controls->Add(this->btnPlay2);
			this->Controls->Add(this->imgMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuInicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"POLICE AND THIEVES";
			this->Load += gcnew System::EventHandler(this, &MenuInicio::MenuInicio_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMenu))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
		 
	private: System::Void MenuInicio_Load(System::Object^ sender, System::EventArgs^ e) {
		n1 = n2 = n3 = n4 = 1;
		btnPlay2->Parent = imgMenu;
		btnOpciones2->Parent = imgMenu;
		btnOpciones2->BackColor = Color::Transparent;
		btnPlay2->BackColor = Color::Transparent;
	}
private: System::Void btnPlay2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	fjuego = gcnew MyJuego(n1, n2, n3, n4, tiempo);
	fjuego->ShowDialog(); delete fjuego;
}
private: System::Void btnOpciones2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	fopciones = gcnew MenuOpciones();

	fopciones->ShowDialog();
	n1 = fopciones->nivel();
	n2 = fopciones->cant_rateros();
	n3 = fopciones->cant_trabajadores();
	n4 = fopciones->cant_ciudadanos();
	tiempo = fopciones->tiempo();
}
private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	formInstrucciones^ intruc = gcnew formInstrucciones();
	intruc->ShowDialog();
}
private: System::Void imgMenu_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
