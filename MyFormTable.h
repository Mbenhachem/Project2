/*
Fichier de la Form(fenêtre) de la table de mapping
Cette form est appelèe via le menu de la première interface
*/

#pragma once


#include "Mapping.h"
#include <sstream>
#include <string>
#include <iostream>
#include "Catalogue.h"


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices; // marshal : conversion
	

	/// <summary>
	/// Summary for MyFormTable
	/// </summary>
	public ref class MyFormTable : public System::Windows::Forms::Form
	{
	public:
		MyFormTable(void)
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
		~MyFormTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::DataGridView^  dataG;
	public:




	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;



	private: System::Windows::Forms::Button^  button3;



	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	public: System::Windows::Forms::DataGridView^  dataGridView1;

	public:

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column2;
	public: System::Windows::Forms::Label^  label1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataG = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataG))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(137, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Type du produit";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(301, 44);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(164, 21);
			this->comboBox1->TabIndex = 20;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyFormTable::comboBox1_SelectedIndexChanged);
			// 
			// dataG
			// 
			this->dataG->AllowUserToDeleteRows = false;
			this->dataG->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataG->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataG->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column4, this->Column5,
					this->Column6
			});
			this->dataG->GridColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataG->Location = System::Drawing::Point(32, 107);
			this->dataG->Name = L"dataG";
			this->dataG->Size = System::Drawing::Size(502, 297);
			this->dataG->TabIndex = 22;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Composante MUST";
			this->Column4->Name = L"Column4";
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column4->Width = 150;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Type Must";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 150;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Objet QuantLib";
			this->Column6->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"FixedLegQuantLib", L"FloatingLegQuantLib", L"IndexQuantLib",
					L"NominalQuantLib", L"startDateQuantLib", L"endDateQuantLib", L"FixedRateQuantLib", L"PayOffQuantLib", L"StrikeQuantLib"
			});
			this->Column6->Name = L"Column6";
			this->Column6->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column6->Width = 150;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(232, 434);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 34);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Enregistrer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyFormTable::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(418, 434);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 34);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Annuler";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyFormTable::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(41, 434);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 34);
			this->button3->TabIndex = 26;
			this->button3->Text = L"Créer";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyFormTable::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(301, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(164, 20);
			this->textBox1->TabIndex = 27;
			this->textBox1->Visible = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(1, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(581, 560);
			this->tabControl1->TabIndex = 28;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(573, 534);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Types de produits";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(306, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"1";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(170, 448);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(194, 34);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Enregistrer les modifications";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyFormTable::button4_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(67, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(449, 373);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Produit";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Type";
			this->Column2->Name = L"Column2";
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Column2->Width = 200;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->textBox1);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->dataG);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(573, 534);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Table de mapping";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// MyFormTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 561);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyFormTable";
			this->Text = L"Table de mapping";
			this->Load += gcnew System::EventHandler(this, &MyFormTable::MyFormTable_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataG))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	//Bouton Annuler
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
			 //////
			 Column6->ReadOnly = true;
			 comboBox1->Visible = true;
			 textBox1->Visible = false;

			 /////
			 if (comboBox1->SelectedIndex != -1)
			 {

				 char* typeProd_string = (char*)Marshal::StringToHGlobalAnsi(comboBox1->SelectedItem->ToString()).ToPointer();

				 Mapping* mapping = new Mapping(typeProd_string);
				 mapping->affiche_data(comboBox1, dataG);

			 }
			 else
			 {
				 dataG->Rows->Clear();
			 }
}

		 //bouton enregistrer les modifications de la table de mapping
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 // si l'utilisateur veut afficher la table de mapping
			 if (comboBox1->Visible == true)

			 {
				 //si un des éléments de la comboBox est selectionné
				 if (comboBox1->SelectedIndex != -1)
				 {

					 char* typeProd_string = (char*)Marshal::StringToHGlobalAnsi(comboBox1->SelectedItem->ToString()).ToPointer();

					 Mapping* mapping = new Mapping(typeProd_string);

					 System::String^ cell1;
					 System::String^ cell2;

					 char* newCell1;
					 char* newCell2;

					 // mettre à jour le XML de paramètrage par les éléments de la datagrid
					 for (int row = 0; row < dataG->RowCount - 1; row++)
					 {

						 cell1 = dataG->Rows[row]->Cells[0]->Value->ToString();
						 cell2 = dataG->Rows[row]->Cells[2]->Value->ToString();
						 newCell1 = (char*)Marshal::StringToHGlobalAnsi(cell1).ToPointer();
						 newCell2 = (char*)Marshal::StringToHGlobalAnsi(cell2).ToPointer();
						 if (strcmp(newCell1, "") != 0 && strcmp(newCell2, "") != 0)
						 {
							 mapping->updateXML(newCell2, newCell1);

						 }
					 }
				 }
				 else // si la comboBox est vide
				 {
					 MessageBox::Show(
						 "Veuillez choisir le type de votre produit",
						 "Type du produit invalide", MessageBoxButtons::OK,
						 MessageBoxIcon::Warning);
				 }
			 }
				 

			 // si on veut créer un nouveau produit
			 if (textBox1->Visible == true)
			 {
				 // si l'utilisateur saisit un type de produit
				 if (textBox1->Text != "")
				 {
					 char* prodName;
					 bool isFull; // isFull = true : si la cellule est pleine
					 Mapping* newMapping = new Mapping(); //constructeur sans argument
					 vector<vector<string>> vectorMapping;// vecteur qui contient les elements de la dataGrid
					 if (textBox1->Text != "" && dataG->Rows->Count>2)
					 {
						 
						 //tester si le 1er élément de la datagrid existe
						 if (dataG->Rows[0]->Cells[0]->Value != nullptr)  isFull = true;
						 else isFull = false;

						 //parcourir la dataGrid
						 // tester si tous les elements de la datagrid ne sont pas vides 
						 //si seulement un est vide alors isFull = false
						 for (int indice = 0; indice < dataG->Rows->Count - 1;indice++)
						 {
							 if (dataG->Rows[indice]->Cells[0]->Value == nullptr || dataG->Rows[indice]->Cells[2]->Value == nullptr)
							 {
								 
								 isFull = isFull && false;
							 }
						 }
					 
						 //si aucun element n'est vide
						 if (isFull)
						 {
							 prodName = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();
							 string prodNameS(prodName);

							 // création de la table
							 vectorMapping = newMapping->tableVector(dataG);
							 newMapping->creat_Table(prodNameS, vectorMapping);

							 //update du catalogue

							 newMapping->updateCatalogue(prodName);
							 // vérifier si le fichier xml de paramètrage est crée
							 string pathFile = ".//product file//" + prodNameS + ".xml";
							 TiXmlDocument doc_param(pathFile.c_str());

							 if (doc_param.LoadFile())
							 {
								 //affichade d'un message : fichier enregistré
								 MessageBox::Show(
									 "Fichier XML de paramètrage de la nouvelle table de mapping est enregistré avec succès !",
									 "Fichier enregistré", MessageBoxButtons::OK,
									 MessageBoxIcon::None);

								 Column2->Items->AddRange(gcnew String(prodName));
								 comboBox1->Items->Add(gcnew String(prodName));
							 }

						 }

					 }	



				 }

				 else // si le textBox est vide
					 MessageBox::Show(
					 "Veuillez saisir le nom de votre produit",
					 "Nom du produit invalide", MessageBoxButtons::OK,
					 MessageBoxIcon::Warning);
		
			 }

				 
}

// bouton Créer
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 Column6->ReadOnly = false;
			 dataG->Rows->Clear();
			 comboBox1->Visible = false;
			 textBox1->Visible = true;
			 textBox1->Clear();
}



private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{
			 if (comboBox1->SelectedIndex != -1)
			 {
				 
				char* prod = (char*)Marshal::StringToHGlobalAnsi(comboBox1->SelectedItem->ToString()).ToPointer();
					 
				Mapping* mapping = new Mapping(string(prod));
				mapping->affiche_data(comboBox1, dataG);

			 }
}







// chargement de la form
private: System::Void MyFormTable_Load(System::Object^  sender, System::EventArgs^  e) 
{
			 //objet de la classe Catalogue
			 Catalogue* catalogue = new Catalogue();

			 if (catalogue->VecCatalogue.size() != 0)
			 {
				//initier la taille de la datagridView
				 dataGridView1->Rows->Add(catalogue->VecCatalogue.size());

				 vector<string> elementsComboBox;

				 //boucle sur les elements du vecteur qui contient les noms et les types de produits 
				// et les chemins  des XML de paramètrage
				 for (size_t indice = 0; indice < catalogue->VecCatalogue.size();indice++)
				 {
					 if (catalogue->VecCatalogue[indice][0] != "" && catalogue->VecCatalogue[indice][1] != "")
					 {
						 //remplir les colonnes de la dataGrid avec les elements du vecteur VecCatalogue de l'objet catalogue
						 dataGridView1->Rows[indice]->Cells[0]->Value = gcnew String(catalogue->VecCatalogue[indice][0].c_str());
						 dataGridView1->Rows[indice]->Cells[1]->Value = gcnew String(catalogue->VecCatalogue[indice][1].c_str());
					 }
				 }

				 for (size_t indice = 0; indice < catalogue->VecCatalogueType.size(); indice++)
				 {
					 //remplir un autre vecteur avce les types de produits
					 elementsComboBox.push_back(catalogue->VecCatalogueType[indice][0]);
				 }



				 //supprimer les doublons dans le vecteur elementsComboBox
				 elementsComboBox = catalogue->SuppDoublons(elementsComboBox);

				 for (size_t indice = 0; indice < elementsComboBox.size(); indice++)
				 {
					 //remplir les comboBox de la datagrid et la comboBox de la table de mapping
					 comboBox1->Items->Add(gcnew String(elementsComboBox[indice].c_str()));
					 Column2->Items->AddRange(gcnew String(elementsComboBox[indice].c_str()));

				 }
			 }
			
			 
}

		 //bouton Enregistrer les modifications
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 Catalogue* catalogue = new Catalogue();
			 //parcourir toute la dataGrid
			 //pour chaque ligne :
			 // - verifier si nom+type (l'identifiant) existent dans le catalogue
			 // si oui : passer
			 // sinon : updateCatalogue
			 
			 catalogue->deleteCatalogue();


			 for(int indice = 0; indice < dataGridView1->Rows->Count-1;indice++)
			 {
				 if (dataGridView1->Rows[indice]->Cells[0]->Value != nullptr && dataGridView1->Rows[indice]->Cells[1]->Value != nullptr)
				 {
					 char* name = (char*)Marshal::StringToHGlobalAnsi(dataGridView1->Rows[indice]->Cells[0]->Value->ToString()).ToPointer();
					 char* type = (char*)Marshal::StringToHGlobalAnsi(dataGridView1->Rows[indice]->Cells[1]->Value->ToString()).ToPointer();
					 string nameProd(name);
					 string typeProd(type);
					 if (!catalogue->isInCatalogue(typeProd,nameProd))
					 {
						 catalogue->updateCatalogue(type,name);
					 }
					 else
					 {
						MessageBox::Show(
						 "Un produit du même type est enregistré sous le même nom",
						 "Produit existant", MessageBoxButtons::OK,
						 MessageBoxIcon::Warning);

						dataGridView1->Rows[indice]->Cells[0]->Value = nullptr;
					 }


				 }
			 }


			 
}


};
}
