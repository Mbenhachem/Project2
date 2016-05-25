/*
MatriceMust :
Classe qui cherche les variables(sur le MustML) déclarées comme matrices
crée une matrice de même taille et remplit les cases par les données sur MustML
les données qui seront stockées sont de type string
Constructeur :
- prend en paramètre le chamin du MustML et le nom de la variable matrice

Attributs :
- vector<vector<string>> matrice  : Matrice de 2 dimensions, sa taille n'est pas fixé au début, sa taille est définie dans le constructeur.
*/


#ifndef MATRICEMUST_H
#define MATRICEMUST_H

#include "tinyxml.h"
#include <string>
#include <iostream>
#include <vector> 
#include "ComponentMust.h"

using namespace std;

class MatriceMust : public ComponentMust
{
public:
	// Constructeurs
	MatriceMust::MatriceMust(char* path, string nameMatrix, string tradeId) // constructeur
	{
		int height; // nombre de lignes
		int width;  // nombre de colonnes
		TiXmlDocument doc(path);
		if (doc.LoadFile())
		{
			TiXmlHandle docMUSTHandle(&doc);

			// création de la matrice
			TiXmlElement *Component;


			TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

			while (Trade)
			{
				if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
				{

					Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();

					while (Component)
					{
						if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameMatrix.c_str()) == 0 && strcmp(Component->Value(), "VARIABLE") == 0)
						{
							height = boost::lexical_cast<int>(Component->FirstChild("META")->FirstChild("HEIGHT")->ToElement()->GetText());
							width = boost::lexical_cast<int>(Component->FirstChild("META")->FirstChild("WIDTH")->ToElement()->GetText());
							vector<vector<string>> mat(height, vector<string>(width));
							matrice = mat;
							int row, col;
							TiXmlElement *Item = Component->FirstChild("VALUES")->FirstChild("ITEM")->ToElement();
							while (Item)
							{
								row = boost::lexical_cast<int>(Item->FirstChild("ROW")->ToElement()->GetText());
								col = boost::lexical_cast<int>(Item->FirstChild("COL")->ToElement()->GetText());
								matrice[row - 1][col - 1] = Item->FirstChild("FORMULA")->ToElement()->GetText();
								Item = Item->NextSiblingElement();
							}

						}
						Component = Component->NextSiblingElement();
					}


				}
				Trade = Trade->NextSiblingElement();
			}// fin de while(Trade)



		} // fin de if(doc)



	}

	//map contient la matrice qui, pour chaque paramètre Must  affecte son equivalent QuantLib
	vector<vector<string>> matrice;

};

#endif