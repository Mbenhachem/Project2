#ifndef DATEMUST_H
#define DATEMUST_H

#include "ComponentMust.h"
#include "tinyxml.h"
#include <string>

using namespace std;
using namespace QuantLib;

class DateMust : public ComponentMust
{
public:
	// Constructeurs
	DateMust(char* path, string nameDate, string tradeId)
	{

		TiXmlDocument doc(path);
		if (doc.LoadFile())
		{
			TiXmlHandle docMUSTHandle(&doc);
			TiXmlElement *Component;
			TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

			while (Trade)
			{
				if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
				{

					Component = Trade->FirstChild("MPTradeData")->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("VARIABLE_LIST")->FirstChild("VARIABLE")->ToElement();

					while (Component)
					{
						if (strcmp(Component->Value(), "VARIABLE") == 0 && strcmp(Component->FirstChild("TYPE")->ToElement()->GetText(), "FULLDATE") == 0)
						{

							if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), nameDate.c_str()) == 0)
							{
								dateString = Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
								dateQ = this->eff_convert_date(dateString);
							}
						}
						Component = Component->NextSiblingElement();
					}

				}
				Trade = Trade->NextSiblingElement();
			}




		}
	}

	//attributs

	string dateString;
	Date dateQ;


};

#endif