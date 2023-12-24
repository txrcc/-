#pragma once

namespace ИДЗООП {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);
		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ очиститьToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ цветToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ типЛинийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ криваяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ прямаяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ширинаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ установитьЗначениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ размерыПоляToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox2;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox3;
	private: System::Windows::Forms::ToolStripMenuItem^ установитьРазмерToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ластикToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьКакToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ установитьМаксимальныйРазмерToolStripMenuItem;

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->очиститьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->цветToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->типЛинийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->криваяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->прямаяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ластикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ширинаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->установитьЗначениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->размерыПоляToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox2 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripTextBox3 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->установитьРазмерToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьКакToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->установитьМаксимальныйРазмерToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->очиститьToolStripMenuItem,
					this->цветToolStripMenuItem, this->типЛинийToolStripMenuItem, this->ширинаToolStripMenuItem, this->размерыПоляToolStripMenuItem,
					this->сохранитьКакToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(780, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// очиститьToolStripMenuItem
			// 
			this->очиститьToolStripMenuItem->Name = L"очиститьToolStripMenuItem";
			this->очиститьToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->очиститьToolStripMenuItem->Text = L"Очистить";
			this->очиститьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::очиститьToolStripMenuItem_Click);
			// 
			// цветToolStripMenuItem
			// 
			this->цветToolStripMenuItem->Name = L"цветToolStripMenuItem";
			this->цветToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->цветToolStripMenuItem->Text = L"Цвет";
			this->цветToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::цветToolStripMenuItem_Click);
			// 
			// типЛинийToolStripMenuItem
			// 
			this->типЛинийToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->криваяToolStripMenuItem,
					this->прямаяToolStripMenuItem, this->ластикToolStripMenuItem
			});
			this->типЛинийToolStripMenuItem->Name = L"типЛинийToolStripMenuItem";
			this->типЛинийToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->типЛинийToolStripMenuItem->Text = L"Тип линий";
			// 
			// криваяToolStripMenuItem
			// 
			this->криваяToolStripMenuItem->Name = L"криваяToolStripMenuItem";
			this->криваяToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->криваяToolStripMenuItem->Text = L"Кривая";
			this->криваяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::криваяToolStripMenuItem_Click);
			// 
			// прямаяToolStripMenuItem
			// 
			this->прямаяToolStripMenuItem->Name = L"прямаяToolStripMenuItem";
			this->прямаяToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->прямаяToolStripMenuItem->Text = L"Прямая";
			this->прямаяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::прямаяToolStripMenuItem_Click);
			// 
			// ластикToolStripMenuItem
			// 
			this->ластикToolStripMenuItem->Name = L"ластикToolStripMenuItem";
			this->ластикToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->ластикToolStripMenuItem->Text = L"Ластик";
			this->ластикToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ластикToolStripMenuItem_Click);
			// 
			// ширинаToolStripMenuItem
			// 
			this->ширинаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripTextBox1,
					this->установитьЗначениеToolStripMenuItem
			});
			this->ширинаToolStripMenuItem->Name = L"ширинаToolStripMenuItem";
			this->ширинаToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->ширинаToolStripMenuItem->Text = L"Ширина";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 23);
			this->toolStripTextBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::toolStripTextBox1_KeyPress);
			// 
			// установитьЗначениеToolStripMenuItem
			// 
			this->установитьЗначениеToolStripMenuItem->Name = L"установитьЗначениеToolStripMenuItem";
			this->установитьЗначениеToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->установитьЗначениеToolStripMenuItem->Text = L"Установить значение";
			this->установитьЗначениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::установитьЗначениеToolStripMenuItem_Click);
			// 
			// размерыПоляToolStripMenuItem
			// 
			this->размерыПоляToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripTextBox2,
					this->toolStripTextBox3, this->установитьРазмерToolStripMenuItem, this->установитьМаксимальныйРазмерToolStripMenuItem
			});
			this->размерыПоляToolStripMenuItem->Name = L"размерыПоляToolStripMenuItem";
			this->размерыПоляToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->размерыПоляToolStripMenuItem->Text = L"Размеры поля";
			// 
			// toolStripTextBox2
			// 
			this->toolStripTextBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox2->Name = L"toolStripTextBox2";
			this->toolStripTextBox2->Size = System::Drawing::Size(100, 23);
			this->toolStripTextBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::toolStripTextBox2_KeyPress);
			// 
			// toolStripTextBox3
			// 
			this->toolStripTextBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox3->Name = L"toolStripTextBox3";
			this->toolStripTextBox3->Size = System::Drawing::Size(100, 23);
			this->toolStripTextBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::toolStripTextBox3_KeyPress);
			// 
			// установитьРазмерToolStripMenuItem
			// 
			this->установитьРазмерToolStripMenuItem->Name = L"установитьРазмерToolStripMenuItem";
			this->установитьРазмерToolStripMenuItem->Size = System::Drawing::Size(267, 22);
			this->установитьРазмерToolStripMenuItem->Text = L"Установить размер";
			this->установитьРазмерToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::установитьРазмерToolStripMenuItem_Click);
			// 
			// сохранитьКакToolStripMenuItem
			// 
			this->сохранитьКакToolStripMenuItem->Name = L"сохранитьКакToolStripMenuItem";
			this->сохранитьКакToolStripMenuItem->Size = System::Drawing::Size(108, 20);
			this->сохранитьКакToolStripMenuItem->Text = L"Сохранить как...";
			this->сохранитьКакToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьКакToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(780, 433);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// установитьМаксимальныйРазмерToolStripMenuItem
			// 
			this->установитьМаксимальныйРазмерToolStripMenuItem->Name = L"установитьМаксимальныйРазмерToolStripMenuItem";
			this->установитьМаксимальныйРазмерToolStripMenuItem->Size = System::Drawing::Size(267, 22);
			this->установитьМаксимальныйРазмерToolStripMenuItem->Text = L"Установить максимальный размер";
			this->установитьМаксимальныйРазмерToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::установитьМаксимальныйРазмерToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 457);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(100, 100);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			Graphics^ canvas;//хранение картинки для picterbox
			List<Point>^ points;//хранение точек для рисования
			Pen^ pen;//хранение характеристик карандаша
			bool draw;//переменная показывающая, рисует ли в данный момент пользователь или нет
			bool time;//показывает, выполнена прошлая операция или нет
			Color color;////хранение цвета карандаша
			int size;//хранения ширины карандаша
			int statePen;//хранение типа карандаша (прямая/кривая)
			int tt;//коэфициент для стрелочки
			/*enum statePen
			{
				1 - кривая
				2 - прямая
			};*/
	private: System::Void очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void цветToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) ;
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void криваяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void прямаяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void установитьЗначениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolStripTextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void установитьРазмерToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);;
private: System::Void toolStripTextBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void toolStripTextBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void ластикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void сохранитьКакToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void установитьМаксимальныйРазмерToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
