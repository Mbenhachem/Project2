#ifndef COMPONENTOPTIONMUST_H
#define COMPONENTOPTIONMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>

using namespace std;
using namespace QuantLib;

class ComponentOptionMust : public ComponentMust
{
public:
	// Constructeurs
	ComponentOptionMust(char* path, string nameOption, string tradeId)
	{

		TiXmlDocument doc(path);
		if (doc.LoadFile())
		{
			TiXmlHandle docMUSTHandle(&doc);
			TiXmlElement *Component;
			TiXmlElement *elem;

			TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

			while (Trade)
			{
				if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
				{
					Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->
						FirstChild("COMPONENT_LIST")->FirstChild("COMPONENT_OPTION")->ToElement();
					while (Component)
					{
						if (strcmp(Component->Value(), "COMPONENT_OPTION") == 0)
						{

							if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameOption.c_str()) == 0)
							{
								payOrSell = Component->FirstChild("PORS")->ToElement()->GetText();
								freqString = Component->FirstChild("EXPIRY_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ")->ToElement()->GetText();
								//firstExpiry = Component->FirstChild("EXPIRY_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("START_DATE")->FirstChild("DATE_FORMULA")->FirstChild("TARGET")->FirstChild("ATTRIBUTE")->ToElement()->GetText();
								//lastExpiry = Component->FirstChild("EXPIRY_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("END_DATE")->FirstChild("DATE_FORMULA")->FirstChild("TARGET")->FirstChild("ATTRIBUTE")->ToElement()->GetText();

							}
						}
						Component = Component->NextSiblingElement();
					}


					//****** recherche du type de l'option

					elem = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->
						FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();

					while (elem)
					{
						if (strcmp(elem->Value(), "VARIABLE") == 0)
						{

							if (strcmp(elem->FirstChild("NAME")->ToElement()->GetText(), "OptionStyle") == 0)
							{
								typeOption = elem->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
							}
						}
						elem = elem->NextSiblingElement();
					}


				}
				Trade = Trade->NextSiblingElement();
			}






		}
	}

	//attributs
	string typeOption;
	string payOrSell;
	string freqString;
	//string firstExpiry;
	//string lastExpiry;


};

#endif