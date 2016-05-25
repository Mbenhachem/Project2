/*
TradeMust :
Classe du trade

Constructeur :
A comme argument le chemin du fichier XML (le MUSTML)
remplit les attributs par les données récupérées du MustML
attributs :
-	std::string nameProduct; :	 Le nom du produit
-	std::string tradeID;	: le ID du trade

*/

#ifndef TRADEMUST_H
#define TRADEMUST_H


#include "tinyxml.h"
#include <string>


class TradeMust //: public ComponentMust
{
public:
	// Constructeurs

	TradeMust(string prodName, string trade_id)
	{
		this->nameProduct = prodName;
		this->tradeID = trade_id;
	}

	// ordreTrade le numéro d'ordre du trade dans le MUSTML lu
	TradeMust(char* path, int ordreTrade)
	{
		int trade_counter = 0;
		TiXmlDocument doc(path);
		if (doc.LoadFile())
		{
			TiXmlHandle docMUSTHandle(&doc);
			TiXmlElement *Component = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").FirstChild("MPTradeData")
				.FirstChild("MPTRDATA").ToElement();

			while (Component)
			{
				if (trade_counter == ordreTrade)
				{
					nameProduct = Component->FirstChild("MPDefName")->ToElement()->GetText();
					tradeID = Component->FirstChild("TradeId")->ToElement()->GetText();
				}
				trade_counter++;
				Component = Component->NextSiblingElement();

			}
		}
	}



	//attributs

	std::string nameProduct;
	std::string tradeID;
	std::string typeProduct;
	


	
};

#endif