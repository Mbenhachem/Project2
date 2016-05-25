/*
MyForm.h :
-Définit les élèments de l'interface
-appelle les autres classes
-appelle la table de mapping
-appelle le code de pricing
*/

/*!
Copyright (C) 2005, 2006, 2007, 2009 StatPro Italia srl

This file is part of QuantLib, a free-software/open-source library
for financial quantitative analysts and developers - http://quantlib.org/

QuantLib is free software: you can redistribute it and/or modify it
under the terms of the QuantLib license.  You should have received a
copy of the license along with this program; if not, please email
<quantlib-dev@lists.sf.net>. The license is also available online at
<http://quantlib.org/license.shtml>.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <ql/quantlib.hpp>

#ifdef BOOST_MSVC
/* Uncomment the following lines to unmask floating-point
exceptions. Warning: unpredictable results can arise...

See http://www.wilmott.com/messageview.cfm?catid=10&threadid=9481
Is there anyone with a definitive word about this?
*/
// #include <float.h>
// namespace { unsigned int u = _controlfp(_EM_INEXACT, _MCW_EM); }
#endif

#include <boost/foreach.hpp>
#include <boost/timer.hpp>
#include <iostream>
#include <iomanip>

using namespace QuantLib;

#ifdef BOOST_MSVC
#ifdef QL_ENABLE_THREAD_SAFE_OBSERVER_PATTERN
#include <ql/auto_link.hpp>
#define BOOST_LIB_NAME boost_system
#include <boost/config/auto_link.hpp>
#undef BOOST_LIB_NAME
#define BOOST_LIB_NAME boost_thread
#include <boost/config/auto_link.hpp>
#undef BOOST_LIB_NAME
#endif
#endif

#if defined(QL_ENABLE_SESSIONS)
namespace QuantLib
{

	Integer sessionId()
	{
		return 0;
	}
}
#endif

#pragma once
#include <boost/algorithm/string.hpp>
#include "tinyxml.h"
#include "Mapping.h"
#include "MyFormTable.h"
#include "DetailsForm.h"
#include "GrecsForm.h"
#include <sstream>
#include <string>
#include <iostream>
#include "MustProduct.h"
#include "Pricer.h"
#include "ComponentIndexMust.h"
#include "ComponentPrincipalMust.h"
#include "ComponentCashFlowMust.h"
#include "ComponentOptionMust.h"
#include "DateMust.h"
#include "RateMust.h"
#include "TradeMust.h"
#include "Portefeuille.h"
#include "MustVanilleSwap.h"
#include "MustCapFloor.h"




namespace Project2
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices; // marshal : conversion

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public
	ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		MyFormTable ^ formTable;

	private:
		Portefeuille* portefeuille;

	private:
		System::Windows::Forms::Button ^ button1;

	private:
		System::Windows::Forms::TextBox ^ textBox1;

	private:
		System::Windows::Forms::Label ^ label1;

	private:
		System::Windows::Forms::MenuStrip ^ menuStrip1;

	private:
		System::Windows::Forms::ToolStripMenuItem ^ MenuMapping;

	private:
		System::Windows::Forms::ToolStripMenuItem ^ tableDeMappingToolStripMenuItem;

	private:
		System::Windows::Forms::ToolStripMenuItem ^ marketDataToolStripMenuItem;

	private:
		System::Windows::Forms::Label ^ label2;

	private:
		System::Windows::Forms::TextBox ^ textBox2;

	private:
		System::Windows::Forms::Button ^ button3;

	private:
		System::Windows::Forms::Button ^ button2;

	private:
		System::Windows::Forms::TextBox ^ textBox3;

	private:
		System::Windows::Forms::Label ^ label3;

	private:
		System::Windows::Forms::Button ^ button4;

	private:
		System::ComponentModel::Container ^ components;

	private:
		System::Windows::Forms::TextBox ^ textBox4;

	private:
		System::Windows::Forms::Label ^ label4;

	private:
		System::Windows::Forms::ToolStripMenuItem ^ typesDeProduitsToolStripMenuItem;

	private:
		vector<tuple<string, string, double, double, double> >* tableauNPV
			= new vector<tuple<string, string, double, double, double> >;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuMapping = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableDeMappingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->marketDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->typesDeProduitsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(556, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Charger";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(111, 111);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(394, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(220, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(336, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Pricing de produit structuré MUST";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->MenuMapping });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MenuMapping
			// 
			this->MenuMapping->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->MenuMapping->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tableDeMappingToolStripMenuItem,
					this->marketDataToolStripMenuItem
			});
			this->MenuMapping->Name = L"MenuMapping";
			this->MenuMapping->Size = System::Drawing::Size(67, 20);
			this->MenuMapping->Text = L"Mapping";
			// 
			// tableDeMappingToolStripMenuItem
			// 
			this->tableDeMappingToolStripMenuItem->Name = L"tableDeMappingToolStripMenuItem";
			this->tableDeMappingToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->tableDeMappingToolStripMenuItem->Text = L"Table de mapping";
			this->tableDeMappingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tableDeMappingToolStripMenuItem_Click);
			// 
			// marketDataToolStripMenuItem
			// 
			this->marketDataToolStripMenuItem->Name = L"marketDataToolStripMenuItem";
			this->marketDataToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->marketDataToolStripMenuItem->Text = L"Market data";
			// 
			// typesDeProduitsToolStripMenuItem
			// 
			this->typesDeProduitsToolStripMenuItem->Name = L"typesDeProduitsToolStripMenuItem";
			this->typesDeProduitsToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(132, 341);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 20;
			this->label2->Text = L"NPV :";
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(272, 341);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(150, 26);
			this->textBox2->TabIndex = 21;
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(270, 264);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(152, 41);
			this->button3->TabIndex = 22;
			this->button3->Text = L"Price";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(496, 329);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(212, 41);
			this->button2->TabIndex = 31;
			this->button2->Text = L"Details des NPV";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(272, 386);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(150, 26);
			this->textBox3->TabIndex = 33;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(132, 386);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 17);
			this->label3->TabIndex = 32;
			this->label3->Text = L"Delta :";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->Enabled = false;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(496, 376);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(212, 41);
			this->button4->TabIndex = 34;
			this->button4->Text = L"Facteurs de risque";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(272, 432);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(150, 26);
			this->textBox4->TabIndex = 36;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(132, 432);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 17);
			this->label4->TabIndex = 35;
			this->label4->Text = L"Vega :";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Pricing de produits structurés MUST :";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// bouton parcourir
	private:
		System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
		{

			// Effacer les résultats du pricing précédent
			textBox2->Text = "";

			// ouverture de la fenêtre pour choisir le fichier
			OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog;
			openFileDialog1->ShowDialog();
			String ^ FilePath = openFileDialog1->FileName;
			// remplir le textBox1 par le chemin du MUSTML
			textBox1->Text = FilePath;

			// si un chemin est indiqué
			if (textBox1->Text != "")
			{

				char* pathC = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();
				string ret(pathC); // convert char* to string
				string extension = pathC;
				extension.erase(0, extension.length() - 3);

				if (boost::iequals(
					extension, "xml")) // vérifier l'extension du fichier :xml, XML,Xml,xMl,xmL
				{
					TiXmlDocument doc(pathC);
					TiXmlHandle hdl(&doc);
					if (!doc.LoadFile())
					{
						MessageBox::Show("Erreur du chargement du fichier XML", "Erreur du chargement",
							MessageBoxButtons::OK, MessageBoxIcon::Error);

						textBox2->Enabled = false;
						button2->Enabled = false;
						button3->Enabled = false;
						button4->Enabled = false;
					}
					else // si le fichier est chargé
					{
						// création de la fenêtre de la table de mapping
						textBox2->Enabled = true;
						button2->Enabled = true;
						button3->Enabled = true;
						button4->Enabled = true;

						portefeuille = new Portefeuille(pathC);



					}
				}
				else // si le fichier chargé a une autre extension que "xml"
				{
					textBox2->Enabled = false;
					button2->Enabled = false;
					button3->Enabled = false;
					button4->Enabled = false;

					MessageBox::Show("Erreur du chargement du fichier XML", "Erreur du chargement",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

	private:
		// Click sur le menu mapping => table de mapping
		System::Void tableDeMappingToolStripMenuItem_Click(
			System::Object ^ sender, System::EventArgs ^ e)
		{
			// affichade l'écran de la table de mapping
			formTable = gcnew MyFormTable();
			formTable->Show();
		}

		// Bouton pricing
	private:
		System::Void button3_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			

			tableauNPV->clear();
			char* pathC = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer(); // chemin du MustML

			/*
			Pour chaque objet :
			Rechercher son nom sur la première colonne de la table de mapping
			créer un objet de la classe du composant
			affecter la donnée à une variable du même type
			*/


			Catalogue* catalogue = new Catalogue();
			////
			double npv;
			double npvfixleg;
			double npvfloatleg;
			double npvSomme = 0;
			/////
			int quitter = 0; // pour quitter la boucle de pricing
			

			//===============================================================================
			//===================== BOUCLE QUI CHERCHE LES TYPES ===============
			//===============================================================================
			for (std::size_t iTrade = 0; iTrade < portefeuille->AllTrades.size(); iTrade++)
			{
				

				if (catalogue->SearchType(portefeuille->AllTrades[iTrade]->nameProduct) != "" 
					&& catalogue->SearchModel(portefeuille->AllTrades[iTrade]->nameProduct) != "") // càd si le produit existe dans le catalogue des produits
					{
					portefeuille->AllTrades[iTrade]->modele = catalogue->SearchModel(portefeuille->AllTrades[iTrade]->nameProduct);
						//textBox2->Text = gcnew String((*typePr)[iTrade].second[0].c_str());
					if (catalogue->SearchType(portefeuille->AllTrades[iTrade]->nameProduct) == "MYSWAP")
						{
							portefeuille->AllTrades[iTrade]->typeProduct = "MYSWAP";
							

						} // fin de if pour tester si c un produit de type MYSWAP

					if (catalogue->SearchType(portefeuille->AllTrades[iTrade]->nameProduct) == "MYCAPFLOOR")
						{
							portefeuille->AllTrades[iTrade]->typeProduct = "MYCAPFLOOR";
							


						} // fin de if pour tester si c un produit de type MYCAPFLOOR


					}

				else 
					{
						//si le produit n'existe pas dans le catalogue
						string monMessage = "Le trade '" + portefeuille->AllTrades[iTrade]->nameProduct + "' de ID : " + portefeuille->AllTrades[iTrade]->tradeID + " n'existe pas dans le catalogue !";
						System::Windows::Forms::DialogResult result = MessageBox::Show(this, gcnew String(monMessage.c_str()), "Produit inconnu", MessageBoxButtons::OK, MessageBoxIcon::None);
						if (System::Windows::Forms::DialogResult::OK == result)
						{
							formTable = gcnew MyFormTable();
							formTable->Show();
							quitter = 1;
							break;
						}
					}

				if (quitter == 1)
				{
					break;
				}

			} // fin de la boucle for


			//===============================================================================
			//=====================BOUCLE QUI FAIT LE PRICING ===============
			//===============================================================================


			if (quitter == 0)
			{
				for (std::size_t iTrade = 0; iTrade < portefeuille->AllTrades.size(); iTrade++)
				{
					npv = 0;
					npvfixleg =0;
					npvfloatleg = 0;
					if (portefeuille->AllTrades[iTrade]->typeProduct != "") // càd si le produit existe dans le catalogue des produits
					{
						if (portefeuille->AllTrades[iTrade]->typeProduct == "MYSWAP")
						{
							Mapping* tab_mapp = new Mapping("MYSWAP");
							// nominal
							string nominalMust = tab_mapp->search_mapping("NominalQuantLib");
							ComponentPrincipalMust* nominalObj = new ComponentPrincipalMust(
								pathC, nominalMust, portefeuille->AllTrades[iTrade]->tradeID);
							Real nominal = nominalObj->nominal[0];
							

							// settlementDate
							string startDateMust = tab_mapp->search_mapping("startDateQuantLib");
							DateMust* startDateObj = new DateMust(
								pathC, startDateMust, portefeuille->AllTrades[iTrade]->tradeID);
							Date settlementDate = startDateObj->dateQ;

							// maturity
							string endDateMust = tab_mapp->search_mapping("endDateQuantLib");
							DateMust* endDateObj = new DateMust(
								pathC, endDateMust, portefeuille->AllTrades[iTrade]->tradeID);
							Date maturity = endDateObj->dateQ;

							// fixedRate

							string fixedRateMust = tab_mapp->search_mapping("FixedRateQuantLib");
							RateMust* fixedRateObj = new RateMust(
								pathC, fixedRateMust, portefeuille->AllTrades[iTrade]->tradeID);
							Rate fixedRate = fixedRateObj->rates[0];
							fixedRateObj->SetMatrixRate(settlementDate, maturity, fixedRateObj->rates);

							//=============FIXED LEG================
							string fixedLegMust = tab_mapp->search_mapping("FixedLegQuantLib");
							ComponentCashFlowMust* fixedLegObj = new ComponentCashFlowMust(
								pathC, fixedLegMust, portefeuille->AllTrades[iTrade]->tradeID);
							Frequency fixedLegFrequency = fixedLegObj->freqQ;
							DayCounter fixedLegDayCounter = fixedLegObj->basisQ;

							//=============FLOATING LEG================
							string floatingLegMust = tab_mapp->search_mapping("FloatingLegQuantLib");
							ComponentCashFlowMust* floatingLegObj = new ComponentCashFlowMust(
								pathC, floatingLegMust, portefeuille->AllTrades[iTrade]->tradeID);
							Frequency floatingLegFrequency = floatingLegObj->freqQ;
							DayCounter floatingLegDayCounter = floatingLegObj->basisQ;

							// Index
							string indexMust = tab_mapp->search_mapping("IndexQuantLib");
							ComponentIndexMust* IndexObj = new ComponentIndexMust(
								pathC, indexMust, portefeuille->AllTrades[iTrade]->tradeID);
							IndexObj->SetMatrixSpread(settlementDate, maturity, IndexObj->spreads);

							//*******************************

							MustPricer* mustPricer = new MustPricer();

							//mustPricer->Test();

							MustVanilleSwap* must_Swap = new MustVanilleSwap(*nominalObj, *fixedLegObj,
								*floatingLegObj, *IndexObj, *startDateObj, *endDateObj, *fixedRateObj);
							

							//************* Appel des méthodes de pricing
							npv = mustPricer->Price(must_Swap, 1);
							npvfixleg = mustPricer->Price(must_Swap, 2);
							npvfloatleg = mustPricer->Price(must_Swap, 3);

							// limiter les NPV à 2 chiffres après la virgule
							DeuxChiff(&npv);
							DeuxChiff(&npvfixleg);
							DeuxChiff(&npvfloatleg);

							// sommer les NPV
							npvSomme += npv;

							// remplir le vecteur de tuple par les résultats des trades un par un.
							tableauNPV->push_back(std::make_tuple(portefeuille->AllTrades[iTrade]->tradeID,
								portefeuille->AllTrades[iTrade]->nameProduct, npv, npvfixleg, npvfloatleg));
								
						} // fin de if pour tester si c un produit de type MYSWAP

						if (portefeuille->AllTrades[iTrade]->typeProduct == "MYCAPFLOOR")
						{
							Mapping* tab_mapp = new Mapping("MYCAPFLOOR");
							// nominal
							string nominalMust = tab_mapp->search_mapping("NominalQuantLib");
							ComponentPrincipalMust* nominalObj = new ComponentPrincipalMust(
								pathC, nominalMust, portefeuille->AllTrades[iTrade]->tradeID);
							Real nominal = nominalObj->nominal[0];


							// settlementDate
							string startDateMust = tab_mapp->search_mapping("startDateQuantLib");
							DateMust* startDateObj = new DateMust(
								pathC, startDateMust, portefeuille->AllTrades[iTrade]->tradeID);
							Date settlementDate = startDateObj->dateQ;

							// maturity
							string endDateMust = tab_mapp->search_mapping("endDateQuantLib");
							DateMust* endDateObj = new DateMust(
								pathC, endDateMust, portefeuille->AllTrades[iTrade]->tradeID);
							Date maturity = endDateObj->dateQ;

							// fixedRate

							string fixedRateMust = tab_mapp->search_mapping("StrikeQuantLib");
							RateMust* fixedRateObj = new RateMust(
								pathC, fixedRateMust, portefeuille->AllTrades[iTrade]->tradeID);
							Rate fixedRate = fixedRateObj->rates[0];
							fixedRateObj->SetMatrixRate(settlementDate, maturity, fixedRateObj->rates);


							//=============FLOATING LEG================
							string floatingLegMust = tab_mapp->search_mapping("FloatingLegQuantLib");
							ComponentCashFlowMust* floatingLegObj = new ComponentCashFlowMust(
								pathC, floatingLegMust, portefeuille->AllTrades[iTrade]->tradeID);
							Frequency floatingLegFrequency = floatingLegObj->freqQ;
							DayCounter floatingLegDayCounter = floatingLegObj->basisQ;

							// Index
							string indexMust = tab_mapp->search_mapping("IndexQuantLib");
							ComponentIndexMust* IndexObj = new ComponentIndexMust(
								pathC, indexMust, portefeuille->AllTrades[iTrade]->tradeID);
							IndexObj->SetMatrixSpread(settlementDate, maturity, IndexObj->spreads);

							//*******************************

							MustPricer* mustPricer = new MustPricer();
							
							//mustPricer->Test();

							MustCapFloor* must_Cap = new  MustCapFloor(*nominalObj, *floatingLegObj, *IndexObj, *startDateObj, *endDateObj, *fixedRateObj);

							//************* Appel des méthodes de pricing
							npv = mustPricer->Price(must_Cap, 1);

							// limiter les NPV à 2 chiffres après la virgule
							DeuxChiff(&npv);

							// sommer les NPV
							npvSomme += npv;

							// remplir le vecteur de tuple par les résultats des trades un par un.
							tableauNPV->push_back(std::make_tuple(portefeuille->AllTrades[iTrade]->tradeID,
								portefeuille->AllTrades[iTrade]->nameProduct, npv, npvfixleg, npvfloatleg));

							//** code de pricing
							
						} // fin de if pour tester si c'est un produit de type MYCAPFLOOR
					}
					
				}// fin de la boucle for
				// affichage de la NPV globale
				textBox2->Text = npvSomme.ToString();
			}// fin de if (quitter == 0 )

		}

	private:
		//détails NPV
		System::Void button2_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			DetailsForm ^ detailsForm = gcnew DetailsForm();

			// ajouter des lignes au dataGrid : ajouter le meme nombre que la taille du tableau des
			// résultats.
			detailsForm->dataGridView1->Rows->Add(tableauNPV->size());

			// Afficher les éléments du tableau des résultats dans le dataGrid.
			for (std::size_t indice = 0; indice < tableauNPV->size(); indice++)
			{
				detailsForm->dataGridView1->Rows[indice]->Cells[0]->Value
					= gcnew String(std::get<0>(tableauNPV[0][indice]).c_str());
				detailsForm->dataGridView1->Rows[indice]->Cells[1]->Value
					= gcnew String(std::get<1>(tableauNPV[0][indice]).c_str());
				detailsForm->dataGridView1->Rows[indice]->Cells[2]->Value
					= std::get<2>(tableauNPV[0][indice]).ToString();
				detailsForm->dataGridView1->Rows[indice]->Cells[3]->Value
					= std::get<3>(tableauNPV[0][indice]).ToString();
				detailsForm->dataGridView1->Rows[indice]->Cells[4]->Value
					= std::get<4>(tableauNPV[0][indice]).ToString();
			}

			// afficher l'écran "Détails"
			detailsForm->Show();
		}

	private:
		//détails grecs
		System::Void button4_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			GrecsForm ^ grecsFrom = gcnew GrecsForm();

			grecsFrom->Show();
		}

	private : 
		void DeuxChiff(double *my_double) /* test attend l'adresse d'un entier... */
		{
			if (*my_double >= 0)
					*my_double = (floor(*my_double * 100)) / 100;
			else
					*my_double = (floor(*my_double * 100 + 1)) / 100;
			return;
		}
	};
}