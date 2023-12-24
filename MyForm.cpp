#include "MyForm.h"
#include <Windows.h>
#include <stdio.h>
#include<cmath>
#pragma comment(lib, "user32.lib")
# define M_PI          3.141592653589793238462643383279502884L
#define int INT32
#define ToInt16 ToInt32
const int widthMax = GetSystemMetrics(SM_CXSCREEN);
const int heightMax = GetSystemMetrics(SM_CYSCREEN);
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ИДЗООП::MyForm form;
	Application::Run(% form);
}
class VDouble2D;
// для хранения координат
class Vector2D {
public:
	int X, Y;

	Vector2D operator=(Vector2D& A)
	{
		X = A.X;
		Y = A.Y;
		return *this; // возвращает объект, который сгенерировал вызов
	}
};
Vector2D mousePosition, mousePositionLine;

//для хранения посчитанных величин измерения отклонения координат для стрелчоки
class VDouble2D {
public:
	double X, Y;
	VDouble2D operator=(Vector2D &A)
	{
		X = A.X;
		Y = A.Y;
		return *this; // возвращает объект, который сгенерировал вызов
	}

	VDouble2D operator=(VDouble2D &A)
	{
		X = (int)A.X;
		Y = (int)A.Y;
		return *this; // возвращает объект, который сгенерировал вызов
	}
};
VDouble2D XY;
////для хранения отклонения для координат стрелочки
class XY_ {
public:
	int x1, x2, y1, y2;
};
XY_ ddd;

//расчёт изменения координат для стрелочки
void Arrow(int size) {
	XY.X = mousePositionLine.X - mousePosition.X;
	XY.Y = mousePositionLine.Y - mousePosition.Y;

	try {
		ddd.x1 = (3 * size * cos(atan((-XY.X / XY.Y)) + M_PI / 4.));
		ddd.y1 = (3 * size * sin(atan((-XY.X / XY.Y)) + M_PI / 4.));
		ddd.x2 = (3 * size * cos(atan((-XY.X / XY.Y)) - M_PI / 4.));
		ddd.y2 = (3 * size * sin(atan((-XY.X / XY.Y)) - M_PI / 4.));
	}
	catch (...) 
	{
		ddd.x1 = 0;
		ddd.y1 = 0;
		ddd.x2 = 0;
		ddd.y2 = 0;
	}

	if (mousePositionLine.Y < mousePosition.Y) {
		ddd.x1 = -ddd.x1;
		ddd.y1 = -ddd.y1;
		ddd.x2 = -ddd.x2;
		ddd.y2 = -ddd.y2;
	}
}

ИДЗООП::MyForm::MyForm(void)
{
	InitializeComponent();
	saveFileDialog1->Filter = "Файлы изображения (*.bmp, *.jpg, *.png)|*.bmp;*.jpg;*.png";//формат сохранения фото
}

System::Void ИДЗООП::MyForm::очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{//создаёт пустую картинку, присваивает её picterBox1, задний фон делает белым и очищает массив точек
	Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	points->Clear();
	canvas = Graphics::FromImage(Img);
	pictureBox1->Image = Img;
	pictureBox1->BackColor = Color::White;
}

System::Void ИДЗООП::MyForm::цветToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	colorDialog1->ShowDialog();//выбирает цвет
	color = colorDialog1->Color;//изменение цвета
	цветToolStripMenuItem->BackColor = color;//окраска блока изменения цвета

	if (color == Color::Black) {//если цвет чёрный, то текст белый иначе чёрный
		цветToolStripMenuItem->ForeColor = Color::White;
	}
	else {
		цветToolStripMenuItem->ForeColor = Color::Black;
	}

	pen = gcnew Pen(color, size);//изменение карандаша
}

System::Void ИДЗООП::MyForm::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	if (time) return;
	time = true;
	switch (statePen)//перебор состояния карандаша
	{
	case 1://кривая
		if (points->Count > 1) {
			canvas->DrawLines(pen, points->ToArray());//рисуются точки из массива points
		}
		break;

	case 2://прямая
		   //проверка координат на выход за границы
		if (mousePosition.X != -1 && mousePosition.Y != -1 && mousePositionLine.X != -1 && mousePositionLine.Y != -1)
		{
			//расчёт изменения координат для стрелочки
			Arrow(size);
			try {

				//проверка на выход за границы и идентичные точки
				if (mousePosition.X != -1 && mousePosition.Y != -1
					&& mousePositionLine.X > 0 && mousePositionLine.Y > 0 
					&& (mousePosition.X != mousePositionLine.X
					|| mousePosition.Y != mousePositionLine.Y))
				{//рисуется стрелочка
					e->Graphics->DrawLine(pen, mousePositionLine.X + size * ddd.x1 / tt, mousePositionLine.Y + size * ddd.y1 / tt, mousePositionLine.X - ddd.x1, mousePositionLine.Y - ddd.y1);
					e->Graphics->DrawLine(pen, mousePosition.X, mousePosition.Y, mousePositionLine.X, mousePositionLine.Y);
					e->Graphics->DrawLine(pen, mousePositionLine.X - size * ddd.x2 / tt, mousePositionLine.Y - size * ddd.y2 / tt, mousePositionLine.X + ddd.x2, mousePositionLine.Y + ddd.y2);
				}
			}
			catch (...) {}
		}
		break;

	default://не найдено состояние
		break;
	}

	time = false;
}

System::Void ИДЗООП::MyForm::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (time) return;
	time = true;
	draw = true;//пользователь рисует
	if (statePen == 1) {//кривая
		points->Clear();
		points->Add(e->Location);
	}
	else {//прямая
		mousePosition.X = e->Location.X;
		mousePosition.Y = e->Location.Y;
		mousePositionLine.X = 1+e->Location.X;
		mousePositionLine.Y = 1+e->Location.Y;
	}
	pictureBox1->Invalidate();//перерисовывание
	time = false;
}

System::Void ИДЗООП::MyForm::pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (time) return;
	time = true;
	if (draw && points->Contains(Point(e->X, e->Y)) == false) {//проверка на наличие такой точки в массиве
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {//проверка на нажатие ЛКМ
			//проверка на выход за границы picterBox1
			if (e->Location.X < 0 || e->Location.X > pictureBox1->Width)
			{
				time = false;
				return;
			}
			if (e->Location.Y < 0 || e->Location.Y > pictureBox1->Height)
			{
				time = false;
				return;
			}
			switch (statePen)
			{
			case 1://кривая
				if (e->Button == System::Windows::Forms::MouseButtons::Left) {
					points->Add(e->Location);
				}
				break;

			case 2://прямая
				Arrow(size);
				//переприсваивание координат
				mousePositionLine.X = e->Location.X;
				mousePositionLine.Y = e->Location.Y;
				break;
			}
		}
		pictureBox1->Invalidate();//перерисовывание
	}
	time = false;
}

System::Void ИДЗООП::MyForm::pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (time) return;
	time = true;
	bool a;
	if (points->Contains(Point(e->X, e->Y)) == false) {//проверка на наличие такой точки в массиве
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {//проверка на нажатие ЛКМ
			//Прорисовка прямой на случай, если во время рисования был выход за границы picterBox1
			try {
			canvas->DrawLine(pen, mousePositionLine.X + size * ddd.x1 / tt, mousePositionLine.Y + size * ddd.y1 / tt, mousePositionLine.X - ddd.x1, mousePositionLine.Y - ddd.y1);
			canvas->DrawLine(pen, mousePosition.X, mousePosition.Y, mousePositionLine.X, mousePositionLine.Y);
			canvas->DrawLine(pen, mousePositionLine.X - size * ddd.x2 / tt, mousePositionLine.Y - size * ddd.y2 / tt, mousePositionLine.X + ddd.x2, mousePositionLine.Y + ddd.y2);
			}
			catch(...){}
			//проверка на выход за границы picterBox1
			if (e->Location.X < 0 || e->Location.X > pictureBox1->Width)
			{
				time = false;
				return;
			}
			if (e->Location.Y < 0 || e->Location.Y > pictureBox1->Height)
			{
				time = false;
				return;
			}
			//переприсваивание координат
			mousePositionLine.X = e->Location.X;
			mousePositionLine.Y = e->Location.Y;
			switch (statePen)
			{
			case 1://кривая
				if (points->Count > 1) {
					//Прорисовка массива точек для кривой
					canvas->DrawLines(pen, points->ToArray());
				}
				break;

			case 2://прямая
				//проверка на выход за границы
				if (mousePosition.X != -1 && mousePosition.Y != -1 && mousePositionLine.X > 0 && mousePositionLine.Y > 0)
				{
					try {
					canvas->DrawLine(pen, mousePositionLine.X, mousePositionLine.Y, mousePositionLine.X - ddd.x1, mousePositionLine.Y - ddd.y1);
					canvas->DrawLine(pen, mousePosition.X, mousePosition.Y, mousePositionLine.X, mousePositionLine.Y);
					canvas->DrawLine(pen, mousePositionLine.X, mousePositionLine.Y, mousePositionLine.X + ddd.x2, mousePositionLine.Y + ddd.y2);
					}
					catch (...) {}
				}
				break;

			default:
				break;
			}

		}
		pictureBox1->Invalidate();
	}
	draw = false;//пользователь больше не рисует
	pictureBox1->Invalidate();//перерисовывание
	//переприсваивание координат
	mousePosition.X = -1;
	mousePosition.Y = -1;
	mousePositionLine.X = -1;
	mousePositionLine.Y = -1;
	time = false;
}

System::Void ИДЗООП::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	color = Color::Black;//задаём начальный настройки
	цветToolStripMenuItem->ForeColor = Color::White;//цвет текста кнопки изменения цвета
	size = 10;//толщина карандаша по умолчанию
	pen = gcnew Pen(color, size);//чёрный карандаш по умолчанию с длиной 10 
	points = gcnew List <Point>();//создаём массив для точек
	draw = false;//пользователь не рисует
	statePen = 2;//по умолчанию прямая
	time = false;//ничего не выполняется
	Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	canvas = Graphics::FromImage(Img);
	pictureBox1->Image = Img;
	pictureBox1->BackColor = Color::White;//по умолчанию цвет фона
	tt = 3 * size * 2;
	MaximizeBox = false;//запрет на расширение экрана на весь экран

	цветToolStripMenuItem->BackColor = color;
	toolStripTextBox2->Text = Convert::ToString(MyForm::Width);
	toolStripTextBox3->Text = Convert::ToString(MyForm::Height);
	toolStripTextBox1->Text = Convert::ToString(size);
}

System::Void ИДЗООП::MyForm::криваяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	statePen = 1;
	pen = gcnew Pen(color, size);//меняем перо
}

System::Void ИДЗООП::MyForm::прямаяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	statePen = 2;
	pen = gcnew Pen(color, size);//меняем перо
}

System::Void ИДЗООП::MyForm::установитьЗначениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (toolStripTextBox1->Text == "")//проверка на пустую строку
		toolStripTextBox1->Text = "10";
	int sizeTemp = Convert::ToInt16(toolStripTextBox1->Text);
	if (sizeTemp <= 25)//проверка на максимальный условный размер
	{	
		if(sizeTemp < 1)//проверка на минимальный размер
			toolStripTextBox1->Text = "1";
		else
		{
			size = sizeTemp;
			pen = gcnew Pen(color, size);//изменяем перо
			tt = 3 * size * 2;//изменение коэфициента для стрелочки
		}
	}
	else
		toolStripTextBox1->Text = "25";
}

System::Void ИДЗООП::MyForm::toolStripTextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != Convert::ToChar(8))//можно ввести только цифры e->KeyChar != Convert::ToChar(8) для работы удаления
	{
			e->Handled = true;
	}
	else
	{
		if(toolStripTextBox1->Text->Length >= 2 && e->KeyChar != Convert::ToChar(8))//ограничение длины строки
			e->Handled = true;
	}
}

System::Void ИДЗООП::MyForm::установитьРазмерToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (toolStripTextBox2->Text == "")//проверка на пустой ввод
		toolStripTextBox2->Text = Convert::ToString(MyForm::Width);
	if (toolStripTextBox3->Text == "")
		toolStripTextBox3->Text = Convert::ToString(MyForm::Height);
	int width = Convert::ToInt16(toolStripTextBox2->Text);
	int height = Convert::ToInt16(toolStripTextBox3->Text);
	if (width < 400 || height < 400) {//проверка на условно минимальный размер
		toolStripTextBox2->Text == "400";
		toolStripTextBox3->Text == "400";
		return;
	}

	if (width > widthMax || height > heightMax) {//проверка на максимальный размер
		toolStripTextBox2->Text = Convert::ToString(widthMax);
		toolStripTextBox3->Text = Convert::ToString(heightMax);
		return;
	}

	try {
	MyForm::Height = height + 67;//меняем размеры окна
	MyForm::Width = width + 20;
	Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);//создание чистого поля
	points->Clear();//очистка массива с точками, которые будут закрашиваться
	canvas = Graphics::FromImage(Img);
	pictureBox1->Image = Img;
	pictureBox1->BackColor = Color::White;
	pictureBox1->Refresh();//переапуск
	this->CenterToScreen();//центр экрана
	}
	catch (...) {}

}

System::Void ИДЗООП::MyForm::toolStripTextBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != Convert::ToChar(8))//можно ввести только цифры e->KeyChar != Convert::ToChar(8) для работы удаления
	{
		e->Handled = true;
	}
	else
	{
		if (toolStripTextBox2->Text->Length >= 5 && e->KeyChar != Convert::ToChar(8))//ограничение длины строки
			e->Handled = true;
	}
}

System::Void ИДЗООП::MyForm::toolStripTextBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != Convert::ToChar(8))//можно ввести только цифры e->KeyChar != Convert::ToChar(8) для работы удаления
	{
		e->Handled = true;
	}
	else
	{
		if (toolStripTextBox3->Text->Length >= 5 && e->KeyChar != Convert::ToChar(8))//ограничение длины строки
			e->Handled = true;
	}
}

System::Void ИДЗООП::MyForm::ластикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	statePen = 1;//устанавливаем режим как кривая и цвет белый
	auto colora = Color::White;
	pen = gcnew Pen(colora, size);
}

System::Void ИДЗООП::MyForm::сохранитьКакToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ fname;
	saveFileDialog1->ShowDialog();
	fname = saveFileDialog1->FileName;//запись пути сохранения

	if (fname == "")//если пользователь не выбрал место сохранения
		return;

	Bitmap^ img = gcnew Bitmap(pictureBox1->Image);
	img->MakeTransparent(Color::White);//делаем белый цвет прозрачным
	try {
		img->Save(fname);//сохранениt
		MessageBox::Show("Изображение сохранено  в \"" + fname + "\".", "Файл успешно сохранён!");
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Информация об ошибке: " + Convert::ToString(e->Data), "Ошибка сохранения файла");
	}
}

System::Void ИДЗООП::MyForm::установитьМаксимальныйРазмерToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
	MyForm::Height = heightMax + 67;//меняем размеры окна
	MyForm::Width = widthMax + 20;
	Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);//создание чистого поля
	points->Clear();//очистка массива с точками, которые будут закрашиваться
	canvas = Graphics::FromImage(Img);
	pictureBox1->Image = Img;
	pictureBox1->BackColor = Color::White;
	pictureBox1->Refresh();//переапуск
	this->CenterToScreen();//центр экрана
	}
	catch (...) {}

}
