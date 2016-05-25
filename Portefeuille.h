/*
Portefeuille :
Classe qui représente le portefeuille chargé (le MustML)

attribut :
- tableau de trades : nom et type de chaque trade

*/

#ifndef PORTEFEUILLE_H
#define PORTEFEUILLE_H


#include "ComponentMust.h"
#include "tinyxml.h"
#include "TradeMust.h"
#include <string>


class Portefeuille
{
public:
	// Constructeurs
	Portefeuille(char* path)
	{
		TradeMust* currentTrade;
		string prod_name;
		string trade_id;
		TiXmlDocument doc(path);
		if (doc.LoadFile())
		{
			TiXmlHandle docMUSTHandle(&doc);
			TiXmlElement *Component = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

			while (Component)
			{
				prod_name = Component->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPDefName")->ToElement()->GetText();
				trade_id = Component->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("TradeId")->ToElement()->GetText();
				currentTrade = new TradeMust(prod_name, trade_id);
				AllTrades.push_back(currentTrade);
				Component = Component->NextSiblingElement();

			}
		}
	}


	//==========================================================
	//============================= Attributs====================
	//===========================================================
	vector<TradeMust*> AllTrades;

	//==========================================================
	//============================= Méthodes====================
	//===========================================================
	

	int isInCatalogue(string nameProd, Catalogue* cata)
	{
		int retour = 0;
		for (size_t indice = 0; indice < cata->VecCatalogue.size(); indice++)
		{
			if (cata->VecCatalogue[indice][0] == nameProd)
			{
				retour++;
			}
		}
		return retour;
	}



	vector<string> listTypes(string nameProd, Catalogue* cata)
	{
		vector<string> retour;
		for (size_t indice = 0; indice < cata->VecCatalogue.size(); indice++)
		{
			if (cata->VecCatalogue[indice][0] == nameProd)
			{
				retour.push_back(cata->VecCatalogue[indice][1]);
			}
		}
		return retour;
	}


};

#endif