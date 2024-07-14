#pragma once

namespace TrabajoFinalPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuOpciones
	/// </summary>
	public ref class MenuOpciones : public System::Windows::Forms::Form
	{
	public:
		MenuOpciones(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuOpciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtTrabajadores;


	private: System::Windows::Forms::Button^ btnaceptar;
	protected:

	protected:





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbltiempo;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TrackBar^ tracktiempo;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ txtnivel;
	private: System::Windows::Forms::ComboBox^ txtciudadanos;
	private: System::Windows::Forms::ComboBox^ txtrateros;


	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuOpciones::typeid));
			this->txtTrabajadores = (gcnew System::Windows::Forms::TextBox());
			this->btnaceptar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbltiempo = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tracktiempo = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtnivel = (gcnew System::Windows::Forms::ComboBox());
			this->txtciudadanos = (gcnew System::Windows::Forms::ComboBox());
			this->txtrateros = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tracktiempo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtAliados
			// 
			this->txtTrabajadores->Location = System::Drawing::Point(270, 141);
			this->txtTrabajadores->Name = L"txtTrabajadores";
			this->txtTrabajadores->Size = System::Drawing::Size(70, 20);
			this->txtTrabajadores->TabIndex = 0;
			this->txtTrabajadores->Text = L"1";
			// 
			// btnaceptar
			// 
			this->btnaceptar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnaceptar->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnaceptar->Location = System::Drawing::Point(333, 287);
			this->btnaceptar->Name = L"btnaceptar";
			this->btnaceptar->Size = System::Drawing::Size(150, 71);
			this->btnaceptar->TabIndex = 5;
			this->btnaceptar->Text = L"aceptar";
			this->btnaceptar->UseVisualStyleBackColor = false;
			this->btnaceptar->Click += gcnew System::EventHandler(this, &MenuOpciones::btnaceptar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(-1, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 33);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Tiempo del juego";
			// 
			// lbltiempo
			// 
			this->lbltiempo->AutoSize = true;
			this->lbltiempo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbltiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltiempo->Location = System::Drawing::Point(414, 80);
			this->lbltiempo->Name = L"lbltiempo";
			this->lbltiempo->Size = System::Drawing::Size(47, 20);
			this->lbltiempo->TabIndex = 8;
			this->lbltiempo->Text = L"1 min";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label4->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(11, 220);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(213, 25);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Cantidad de rateros:";
			// 
			// tracktiempo
			// 
			this->tracktiempo->BackColor = System::Drawing::Color::White;
			this->tracktiempo->Location = System::Drawing::Point(194, 71);
			this->tracktiempo->Name = L"tracktiempo";
			this->tracktiempo->Size = System::Drawing::Size(214, 45);
			this->tracktiempo->TabIndex = 11;
			this->tracktiempo->Value = 1;
			this->tracktiempo->Scroll += gcnew System::EventHandler(this, &MenuOpciones::trackBar1_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label3->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(1, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(261, 25);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Cantidad de trabajadores:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label6->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(0, 183);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(237, 25);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Cantidad de ciudadanos";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(498, 365);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 287);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 27);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Nivel:";
			// 
			// txtnivel
			// 
			this->txtnivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtnivel->FormattingEnabled = true;
			this->txtnivel->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->txtnivel->Location = System::Drawing::Point(105, 293);
			this->txtnivel->Name = L"txtnivel";
			this->txtnivel->Size = System::Drawing::Size(61, 21);
			this->txtnivel->TabIndex = 16;
			this->txtnivel->Text = L"1";
			// 
			// txtciudadanos
			// 
			this->txtciudadanos->FormattingEnabled = true;
			this->txtciudadanos->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->txtciudadanos->Location = System::Drawing::Point(270, 183);
			this->txtciudadanos->Name = L"txtciudadanos";
			this->txtciudadanos->Size = System::Drawing::Size(69, 21);
			this->txtciudadanos->TabIndex = 17;
			this->txtciudadanos->Text = L"4";
			// 
			// txtrateros
			// 
			this->txtrateros->FormattingEnabled = true;
			this->txtrateros->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"1", L"2", L"3" });
			this->txtrateros->Location = System::Drawing::Point(270, 226);
			this->txtrateros->Name = L"txtrateros";
			this->txtrateros->Size = System::Drawing::Size(69, 21);
			this->txtrateros->TabIndex = 18;
			this->txtrateros->Text = L"1";
			// 
			// MenuOpciones
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(495, 363);
			this->Controls->Add(this->txtrateros);
			this->Controls->Add(this->txtciudadanos);
			this->Controls->Add(this->txtnivel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tracktiempo);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbltiempo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnaceptar);
			this->Controls->Add(this->txtTrabajadores);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MenuOpciones";
			this->Text = L"MenuOpciones";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tracktiempo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			int tiempo() {
				int t = Convert::ToInt32(tracktiempo->Value);
				return t;
		}
			int cant_trabajadores() {
				int cant = Convert::ToInt32(txtTrabajadores->Text);
				return cant;
			}
			int cant_rateros() {
				int cant = Convert::ToInt32(txtrateros->Text);
				return cant;
			}
			int cant_ciudadanos() {
				int cant = Convert::ToInt32(txtciudadanos->Text);
				return cant;
			}
			int nivel() {
				int niv = Convert::ToInt32(txtnivel->Text);
				return niv;
			}
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		lbltiempo->Text = Convert::ToString(tracktiempo->Value);
		lbltiempo->Text += " min";
	}
private: System::Void btnaceptar_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
};
}
