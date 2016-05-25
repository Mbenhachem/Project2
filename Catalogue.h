#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "tinyxml.h"
#include "ProductChoice.h"
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
		// doc_param : XML de param�trage 
		TiXmlDocument doc_param(".//product file//Catalogue.xml");

		if (doc_param.LoadFile())
		{
			TiXmlHandle XMLparam(&doc_param); // ouverture du fichier XML de param�trage

			//====================================================
			//             recherche par boucle
			//=====================================================
			string nameProd;
			string typeProd;
			string pathXML;

			TiXmlElement* param = XMLparam.FirstChild("BODY").FirstChild("productList").Child("prod", 0).ToElement();

			while (param) // boucle sur les elements du XML param�tr�
			{

				vector < string > prod;
				nameProd = param->Attribute("name");
				typeProd = param->Attribute("type");
				pathXML = param->GetText();
				prod.push_back(string(nameProd));
				prod.push_back(string(typeProd));
				prod.push_back(string(pathXML));

				VecCatalogue.push_back(prod);

				param = param->NextSiblingElement(); // iteration sur param : les elements
			}


			param = XMLparam.FirstChild("BODY").FirstChild("typeList").Child("prod", 0).ToElement();

			while (param) // boucle sur les elements du XML param�tr�
			{

				vector < string > prod;
				typeProd = param->Attribute("type");
				pathXML = param->GetText();
				prod.push_back(string(typeProd));
				prod.push_back(string(pathXML));

				VecCatalogueType.push_back(prod);

				param = param->NextSiblingElement(); // iteration sur param : les elements
			}


		} // fin de if (doc_param.LoadFile())
	}

	//=================================================================
	//===============   Attribut   =====================================
	//=================================================================
	vector<vector<string>> VecCatalogue; // nameProd, typeProd et XML path

	vector<vector<string>> VecCatalogueType;

	//=================================================================
	//===============   M�thodes   =====================================
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

	void updateCatalogue(char* typeProd, char* nameProd)
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
				elem->LinkEndChild(element2);

				string path = string(typeProd) + ".xml";

				TiXmlText* texti = new TiXmlText(path.c_str());
				element2->LinkEndChild(texti);

				//ajout du produit au vecteur du catalogue
				vector<string> produit;
				produit.push_back(string(nameProd));
				produit.push_back(string(typeProd));
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


};



#endif


