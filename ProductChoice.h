#include <cliext/vector>
#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ProductChoice
	/// </summary>
	public ref class ProductChoice : public System::Windows::Forms::Form
	{
	public :
		vector<string>* myVector;	

	public: cliext::vector<System::Windows::Forms::RadioButton^> vectorRadioButton;
	public:
		ProductChoice(vector<string> vectorArg)
		{
			myVector = &vectorArg;
			InitializeComponent(vectorArg);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProductChoice()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^  button1;
	public :System::Windows::Forms::GroupBox^ groupBox1;


	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(vector<string> Vector)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			
			myVector = &Vector;



			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(77, 394);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ProductChoice::button1_Click);
			// 
			// ProductChoice
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Name = L"ProductChoice";
			this->Text = L"Choix du produit";
			this->ResumeLayout(false);

			//
			//groupBox1
			//
			
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(250, 500); //////
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			
			//les radioButton
			for (size_t indice = 0; indice < myVector->size();indice++)
			{
				System::Windows::Forms::RadioButton^  radioButton3 = gcnew  System::Windows::Forms::RadioButton();
				radioButton3->AutoSize = true;
				radioButton3->Location = System::Drawing::Point(29, 30 * (indice + 1));
				radioButton3->Name = gcnew String((*myVector)[indice].c_str());
				radioButton3->Size = System::Drawing::Size(85, 17);
				radioButton3->TabIndex = indice;
				if (indice == 0)
				{
					radioButton3->Checked = true;
				}

				radioButton3->TabStop = true;
				radioButton3->Text = gcnew String((*myVector)[indice].c_str());
				radioButton3->UseVisualStyleBackColor = true;
				vectorRadioButton.push_back(radioButton3);
				this->groupBox1->Controls->Add(radioButton3);
			}

			this->Controls->Add(this->groupBox1);


		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{

				 for (size_t indice = 0; indice < vectorRadioButton.size();indice++)
				 {
					 if (vectorRadioButton[indice]->Checked)
						 button1->Text = vectorRadioButton[indice]->Name;
				 }

	}



	public :
		String^ testDeRetour()
	{
			for (size_t indice = 0; indice < vectorRadioButton.size(); indice++)
			{
				if (vectorRadioButton[indice]->Checked)
				{
					
					return vectorRadioButton[indice]->Name;
				}
			}
		
	}
	};
}
