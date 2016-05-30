
/*
Classe EnumMust pour chercher les variables de type Enum
*/


#ifndef ENUMMUST_H
#define ENUMMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>

using namespace std;
using namespace QuantLib;

class EnumMust : public ComponentMust
{
public:
	// Constructeurs
	EnumMust(char* path, string nameEnum, string tradeId)
	{
		int test = 0;
		TiXmlDocument doc(path);
		if (doc.LoadFile())
		{
			TiXmlHandle docMUSTHandle(&doc);
			TiXmlElement *Component;
			TiXmlElement *ComponentMatrix;
			TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

			while (Trade)
			{
				if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
				{
					Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();

					while (Component)
					{
						if (strcmp(Component->Value(), "VARIABLE") == 0 && strcmp(Component->FirstChild("TYPE")->ToElement()->GetText(), "ENUM") == 0)
						{

							if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameEnum.c_str()) == 0)
							{
								if (Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText())
								{
									valeur = Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
									SuppDoubleQuotes(&valeur);
									test = 1;
								}
							}
						}

						Component = Component->NextSiblingElement();
					}
				}
				Trade = Trade->NextSiblingElement();
			}
		}


		if (test == 0)
		{
			throw string("Erreur de la variable de type Enum");
		}
	}


	//Attributs
	string valeur;

};

#endif