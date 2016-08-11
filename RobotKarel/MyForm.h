#pragma once
#include "Item.h";
#include "Beeper.h";
namespace RobotKarel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		///////*********************////////////+++++
		//Drawing objects
		Graphics^ g;
		Brush^ grayBrush;
		Brush^ BlueBrush;
		Brush^ burlyBrush;
		Pen^ blackPen;
		static const int NUMROWS = 16;
		static const int NUMCOLS = 20;
		static const int CELLSIZE = 25;

		Beeper^ beeper1 = gcnew Beeper;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;
			 array <Item^, 2>^ maze;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(668, 522);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(674, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(755, 534);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
		g = panel1->CreateGraphics();
		grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
		BlueBrush = gcnew System::Drawing::SolidBrush(Color::Blue);
		burlyBrush = gcnew System::Drawing::SolidBrush(Color::BurlyWood);
		blackPen = gcnew System::Drawing::Pen(Color::Black);

		//maze = gcnew array<Item^, 2>(NUMROWS, NUMCOLS);

	}

	


			//outside form
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		drawMaze();

		//draw buttons
		beeper1->set_x(5);
		beeper1->set_y(5);

		Rectangle beeperRect = Rectangle(beeper1->get_x() * CELLSIZE, beeper1->get_y() * CELLSIZE, CELLSIZE - 1, CELLSIZE - 1);
		g->FillRectangle(grayBrush, beeperRect);
		g->DrawRectangle(blackPen, beeperRect);
		
	}





			 private: void drawMaze()
			 {
				 //Declare local variables;
				 int row, col;
				 int x, y;

				 //Refresh the panel
				 panel1->Refresh();

				 //Draw the empty maze
				 for (row = 0; row < NUMROWS; row++)
				 {
					 for (col = 0; col < NUMCOLS; col++)
					 {
						 x = col * CELLSIZE;
						 y = row * CELLSIZE;
						 Rectangle gridRect = Rectangle(x, y, CELLSIZE - 1, CELLSIZE - 1);
						 g->FillRectangle(BlueBrush, gridRect);
						 g->DrawRectangle(blackPen, gridRect);
					 }
				 }
			 }
};
	

}
