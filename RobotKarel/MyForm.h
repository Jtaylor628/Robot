#pragma once
#include "Item.h";
#include "Beeper.h";
#include "robot.h";
#include "Wall.h";
#include "Cell.h";
#include <string>;
#include <fstream>;




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
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		///////*********************////////////+++++
		//Drawing objects
		Graphics^ g;
		Brush^ grayBrush;
		Brush^ BlueBrush;
		Brush^ burlyBrush;
		Brush^ randomBrush;
		Pen^ blackPen;
		static const int NUMROWS = 12;	
		static const int NUMCOLS = 12;
		static const int CELLSIZE = 22;
		static const int ARRAY_SIZE = 4;	//beeper array size.
		int wall_array_size = 9;		//Must change if txt file is changed
		int number_of_beepers = 0;
		int beeper_array_size = 0;
		array <Beeper^>^ beeper_array;
		array <Wall^>^ wall_array;
		array <Cell^,2>^ cell_array;
		robot^ myRobot;
		//Wall^ my_wall;
		String^ beepers;
		bool dropBeeper = false;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  timer1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Button^  button1;
			 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(286, 264);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(295, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Push";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(289, 244);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Beeper Bag: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(295, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Drop beeper";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(295, 70);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Add beepers";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(292, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 5;
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(402, 266);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	
		g = panel1->CreateGraphics();
		randomBrush = gcnew System::Drawing::SolidBrush(Color::Pink);
		grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
		BlueBrush = gcnew System::Drawing::SolidBrush(Color::Blue);
		burlyBrush = gcnew System::Drawing::SolidBrush(Color::BurlyWood);
		blackPen = gcnew System::Drawing::Pen(Color::Black);
		beepers = gcnew String("beepers");
		
		//maze = gcnew array<Item^, 2>(NUMROWS, NUMCOLS);

		//initializes beepers.
		beeper_array = gcnew array<Beeper^>(ARRAY_SIZE);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			beeper_array[i] = gcnew Beeper();
		}


		//initializes cell array.
		cell_array = gcnew array<Cell^, 2>(NUMROWS, NUMCOLS);
		for (int row = 0; row < NUMROWS; row++) {
			for (int col = 0; col < NUMCOLS; col++) {
				cell_array[row,col] = gcnew Cell;
			}
		}
		

		//initializes wall objects.
		wall_array = gcnew array<Wall^>(wall_array_size);
		for (int i = 0; i < wall_array_size; i++) {
			wall_array[i] = gcnew Wall();
		}
		

	}

	


		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		button2->Visible = true;
		button3->Visible = true;
		//textBox1->Text = myRobot->Beeper_Bag.ToString();
		
		get_data(beeper_array, cell_array, 1); //gets input from file
		get_data(wall_array, cell_array, 2);
		drawMap();		//draws world.

	
		
		//Draws beepers.
		for (int i = 0; i < ARRAY_SIZE; i++) {
			Rectangle beeperRect = Rectangle(beeper_array[i]->get_x() * CELLSIZE, beeper_array[i]->get_y() * CELLSIZE, CELLSIZE - 1, CELLSIZE - 1);
			//using brush for now until we use icon.
			//g->FillRectangle(burlyBrush, beeperRect);
			//g->DrawRectangle(blackPen, beeperRect);
			g->DrawImage(beeper_array[i]->get_bmp(), beeperRect);
			
		}





		//Draws walls
		for (int i = 0; i < wall_array_size; i++) {
			Rectangle wallRect = Rectangle(wall_array[i]->get_x() * CELLSIZE, wall_array[i]->get_y() * CELLSIZE, CELLSIZE - 1, CELLSIZE - 1);
			//using brush for now until we use icon.
			g->FillRectangle(grayBrush, wallRect);
			g->DrawRectangle(blackPen, wallRect);


			//g->DrawIcon(MyRobot->getIcon(), beeperRect);

			//robot starting position.
			myRobot = gcnew robot;
			myRobot->set_x(3);
			myRobot->set_y(3);

			//draws robot starting location
			Rectangle robotRect = Rectangle(myRobot->get_x() * CELLSIZE, myRobot->get_y() * CELLSIZE, CELLSIZE - 1, CELLSIZE - 1);
			g->DrawImage(myRobot->get_bmp(), robotRect);
			timer1->Start();
			

		}
		



	}


			 


			 private: void drawMap()	//draws world.
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
						 y = col * CELLSIZE;
						 x = row * CELLSIZE;
						 Rectangle gridRect = Rectangle(x, y, CELLSIZE - 1, CELLSIZE - 1);
						 g->FillRectangle(BlueBrush, gridRect);
						 g->DrawRectangle(blackPen, gridRect);
					 }
				 }



				 












			 }




					





					  //outside form
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
	if (!dropBeeper) {	//fills back in old location of robot. 
		Rectangle OldRect = Rectangle(myRobot->get_x() * CELLSIZE, myRobot->get_y() * CELLSIZE, CELLSIZE - 1, CELLSIZE - 1);
		//using brush for now until we use icon.
		g->FillRectangle(BlueBrush, OldRect);
		g->DrawRectangle(blackPen, OldRect);
		dropBeeper = false;
	}dropBeeper = false;
	myRobot->move_robot(cell_array);

	//Draws new location of robot.
	Rectangle robotRect = Rectangle(myRobot->get_x() * CELLSIZE, myRobot->get_y() * CELLSIZE, CELLSIZE - 1, CELLSIZE - 1);
	g->DrawRectangle(blackPen, robotRect);
	g->DrawImage(myRobot->get_bmp(), robotRect);

	
	label1->Text = "Beeper Bag: " + myRobot->Beeper_Bag.ToString();
	
}






		 //Gets walls location, beeper location from file.

		 void get_data(array<Item^>^ beeper_array, array<Item^, 2>^ cell_array, int input)
		 {
			 
			 //System::String^ managedString = "test";
			 //msclr::interop::marshal_context context;
			 //std::string file1 = context.marshal_as<std::string>(this->file);
			 //file = msclr::interop::marshal_as<std::string>(this->file);
			 std::string file = "stuff.txt";
			 if (input == 2)
				 file = "Wall.txt";
			 int number_ofThings = 0;
			 int x = 0;
			 int y = 0;
			 std::string str;
			 std::ifstream in_stream;
			 in_stream.open(file);
			 if (in_stream.fail()) {
				 MessageBox::Show("failed to open file");
				 exit(1);
			 }
			 int count = 0;
			 while (!in_stream.eof()) {
				 in_stream >> str;
				 in_stream >> number_ofThings;
				 //array_size = number_ofThings;
				 for (int i = 0; i < number_ofThings; i++) {
					 in_stream >> x;
					 beeper_array[i]->set_x(x);
					 in_stream >> y;
					 beeper_array[i]->set_y(y);
					 //if(str == "beeper")
					 if(input == 1)
					 cell_array[x, y]->beeper = true;
					 if(input == 2)
					 cell_array[x, y]->wall = true;

				 }
				 //count++;
			 }


		 }







		 //drops beeper.
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (myRobot->Beeper_Bag > 0) {
		dropBeeper = true;
		Rectangle beeperRect = Rectangle(myRobot->get_x() * CELLSIZE, myRobot->get_y() * CELLSIZE, CELLSIZE - 1, CELLSIZE - 1);
		//Draws new beeper
		g->DrawImage(beeper_array[0]->get_bmp(), beeperRect);
		cell_array[myRobot->get_x(), myRobot->get_y()]->beeper = true;
		myRobot->Beeper_Bag -= 1;
	}
	else MessageBox::Show("You have no more beepers!");
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	myRobot->Beeper_Bag += 100;
	label2->Text = "Buy full version for\n unlimited beepers!";
	button3->Enabled = false;
}
};
	

}
