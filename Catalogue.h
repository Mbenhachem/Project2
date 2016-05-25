#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "tinyxml.h"
#include <string>
#include <iostream>
#include <tuple>
#include <vector> 

using namespace std;

class Catalogue
{
public:

	Catalogue::Catalogue() // constructeur
	{
		// doc_param : XML de paramètrage 
		TiXmlDocument doc_param(".//product file//Catalogue.xml");

		if (doc_param.LoadFile())
		{
			TiXmlHandle XMLparam(&doc_param); // ouverture du fichier XML de paramétrage

			//====================================================
			//             recherche par boucle
			//=====================================================
			string nameProd;
			string typeProd;
			string pathXML;
			string activated;
			string modele;

			TiXmlElement* param = XMLparam.FirstChild("BODY").FirstChild("productList").Child("prod", 0).ToElement();

			while (param) // boucle sur les elements du XML paramétré
			{

				vector < string > prod;
				nameProd = param->Attribute("name");
				typeProd = param->Attribute("type");
				activated = param->Attribute("activate");
				modele = param->Attribute("modele");
				pathXML = param->GetText();
				prod.push_back(string(nameProd));
				prod.push_back(string(typeProd));
				prod.push_back(string(activated));
				prod.push_back(string(modele));
				prod.push_back(string(pathXML));

				VecCatalogue.push_back(prod);

				param = param->NextSiblingElement(); // iteration sur param : les elements
			}

			//================== Boucle sur les types de produits===================
			param = XMLparam.FirstChild("BODY").FirstChild("typeList").Child("prod", 0).ToElement();

			while (param) // boucle sur les elements du XML paramétré
			{

				vector < string > prod;
				typeProd = param->Attribute("type");
				pathXML = param->GetText();
				prod.push_back(string(typeProd));
				prod.push_back(string(pathXML));

				VecCatalogueType.push_back(prod);

				param = param->NextSiblingElement(); // iteration sur param : les elements
			}


			//================== Boucle sur les modèles ===================
			param = XMLparam.FirstChild("BODY").FirstChild("modelList").Child("model", 0).ToElement();
			string model;
			while (param) // boucle sur les elements du XML paramétré
			{

				model = param->Attribute("name");


				VecCatalogueModel.push_back(model);

				param = param->NextSiblingElement(); // iteration sur param : les elements
			}


		} // fin de if (doc_param.LoadFile())
	}

	//=================================================================
	//===============   Attribut   =====================================
	//=================================================================
	vector<vector<string>> VecCatalogue; // nameProd, typeProd , activate et XML path

	vector<vector<string>> VecCatalogueType; // typeProd et XML path

	vector<string> VecCatalogueModel; // noms des modeles

	//=================================================================
	//===============   Méthodes   =====================================
	//=================================================================

	//SuppDoublons : pour supprimer les doublons dans un vecteur de string
	vector<string> SuppDoublons(vector<string> vec)
	{
		std::vector<std::string> result;
		bool inserer;
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			inserer = true;
			for (unsigned int j = i + 1; j < vec.size(); j++)
			{
				if (vec[i] == vec[j])
					inserer = false;
			}
			if (inserer)
				result.push_back(vec[i]);
		}
		return result;
	}


	
	// *******************
	// update catalogue par les noms de produits, les types et les chemins des XML

	void updateCatalogue(char* typeProd, char* nameProd, char* activated, char* modele)
	{
		TiXmlDocument doc(".//product file//Catalogue.xml");
		TiXmlHandle hdl(&doc);
		if (doc.LoadFile())
		{
			TiXmlElement *elem = hdl.FirstChild("BODY").FirstChild("productList").ToElement();
			if (elem)
			{
				//balise produit
				TiXmlElement* element2 = new TiXmlElement("prod");
				element2->SetAttribute("name", nameProd);
				element2->SetAttribute("type", typeProd);
				element2->SetAttribute("activate", activated);
				element2->SetAttribute("modele", modele);
				elem->LinkEndChild(element2);

				string path = string(typeProd) + ".xml";

				TiXmlText* texti = new TiXmlText(path.c_str());
				element2->LinkEndChild(texti);

				//ajout du produit au vecteur du catalogue
				vector<string> produit;
				produit.push_back(string(nameProd));
				produit.push_back(string(typeProd));
				produit.push_back(string(activated));
				produit.push_back(string(modele));
				produit.push_back(path);
				this->VecCatalogue.push_back(produit);

				doc.SaveFile(".//product file//Catalogue.xml");  // enregistrement de la modification
			}
		}
	}

	//*******************

	bool isInCatalogue(string typeProd, string nameProd)
	{
	//verifier si le nom et le type du meme produit existent dans le vecteur du catalogue
		for (size_t i = 0; i < this->VecCatalogue.size(); i++)
		{
			if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][1] == typeProd)
				return true;
		}
		return false;
	}


	//*******************

	bool doublonsActifs(string nameProd, string activated, int indice)
	{
		//verifier si le nom et le type du meme produit existent dans le vecteur du catalogue
		for (size_t i = 0; i < indice; i++)
		{
			if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][2] == "True" && activated=="True")
				return true;
		}
		return false;
	}

	//**********************************
	void deleteCatalogue()
	{
		TiXmlDocument doc(".//product file//Catalogue.xml");

		if (doc.LoadFile())
		{
			bool trouve = false;
			TiXmlHandle hdl(&doc);
			TiXmlElement *elem = hdl.FirstChild("BODY").FirstChild("productList").FirstChildElement().ToElement();
			TiXmlElement *elem2 = elem;

			while (elem2)
			{

				TiXmlElement *f = hdl.FirstChild("BODY").FirstChild("productList").ToElement();
				elem = elem2;
				elem2 = elem->NextSiblingElement();
				f->RemoveChild(elem);


			}
			doc.SaveFile(".//product file//Catalogue.xml");

			this->VecCatalogue.clear();
		}
	}

	//**********************************
	string SearchType(string nameProd)
	{
		for (size_t i = 0; i < this->VecCatalogue.size(); i++)
		{
			if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][2] == "True")
				return this->VecCatalogue[i][1];
		}
		return "";
		
	}

	//**********************************
	string SearchModel(string nameProd)
	{
		for (size_t i = 0; i < this->VecCatalogue.size(); i++)
		{
			if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][2] == "True")
				return this->VecCatalogue[i][3];
		}
		return "";

	}

};



#endif


