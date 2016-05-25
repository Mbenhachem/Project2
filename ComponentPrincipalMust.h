#ifndef COMPONENTPRINCIPALMUST_H
#define COMPONENTPRINCIPALMUST_H

#include "tinyxml.h"
#include "ComponentMust.h"
#include "DateMust.h"
using namespace std;
using namespace QuantLib;

class ComponentPrincipalMust : ComponentMust
{
public:
	// Constructeurs
	ComponentPrincipalMust(char* path, string namePrincipal, string tradeId)
	{
		string nominalString;
		double nominalDouble;
		TiXmlDocument doc(path);
		if (doc.LoadFile())
		{
			TiXmlHandle docMUSTHandle(&doc);
			TiXmlElement *Component;

			TiXmlNode *Pointer;

			TiXmlElement *Trade = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").ToElement();

			while (Trade)
			{
				if (strcmp(Trade->FirstChild("TradeId")->ToElement()->GetText(), tradeId.c_str()) == 0)
				{

					Component = Trade->FirstChild("MPTradeData")
						->FirstChild("MPTRDATA")->FirstChild("MPTrDataXML")->FirstChild("MPTRDATAXML")->FirstChild("STRUCTURED_INSTRUMENT")->FirstChild("COMPONENT_LIST")->FirstChild("COMPONENT_PRINCIPAL")->ToElement();

					while (Component)
					{
						if (strcmp(Component->Value(), "COMPONENT_PRINCIPAL") == 0) // pour se limiter à la composante COMPONENT_PRINCIPAL
						{

							if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), namePrincipal.c_str()) == 0)
							{
								if (Component->FirstChild("NOTIONAL")->ToElement()->GetText())
								{
									// valeur du nominal
									nominalString = Component->FirstChild("NOTIONAL")->ToElement()->GetText();

									Pointer = Component->FirstChild("NTL_CCY");
									if (Pointer)
									{
										principalCcy = Pointer->FirstChild("CCY")->ToElement()->GetText();

									}

									// formule d'amortissement
									Pointer = Component->FirstChild("AMORT_FORMULA");
									if (Pointer)
									{
										formuleAmort = Pointer->FirstChild("FORMULA_STRING")->ToElement()->GetText();

									}

									//// Fréquence du notional

									//
									Pointer = Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ");
									if (Pointer && Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ")->ToElement()->GetText())
									{
										freq = Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("SCHED_DEF")->FirstChild("FREQ")->ToElement()->GetText();
									}


									////start date  du notional
									Pointer = Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("START_DATE")->FirstChild("DATE_FORMULA")->FirstChild("FORMULA_STRING");

									if (Pointer && Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("START_DATE")->FirstChild("DATE_FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText())
									{
										startDate = Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("START_DATE")->FirstChild("DATE_FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
									}
									//// end date  du notional
									Pointer = Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("END_DATE")->FirstChild("DATE_FORMULA")->FirstChild("FORMULA_STRING");
									if (Pointer &&  Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("END_DATE")->FirstChild("DATE_FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText())
									{
										endDate = Component->FirstChild("AMORT_SCHED")->FirstChild("BASIC_SCHED")->FirstChild("END_DATE")->FirstChild("DATE_FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
									}
								}
							}
						}
						Component = Component->NextSiblingElement();
					}


					//*****  Recherche de la condition d'amortissement

					Component = docMUSTHandle.FirstChild("BODY").FirstChild("TRADELIST").FirstChild("MUST_TR").FirstChild("MPTradeData")
						.FirstChild("MPTRDATA").FirstChild("MPTrDataXML").FirstChild("MPTRDATAXML").FirstChild("STRUCTURED_INSTRUMENT").FirstChild("VARIABLE_LIST").FirstChild("VARIABLE").ToElement();

					while (Component)
					{
						if (strcmp(Component->Value(), "VARIABLE") == 0) // pour se limiter à la composante COMPONENT_PRINCIPAL
						{
							//recherche de la variable AmortizeOrNot qui indique si le nominal est amorti ou pas
							if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), "AmortizeOrNot") == 0)
							{
								if (Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText())
								{
									amortYorN = "N";
									amortYorN = Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
									amortYorN = amortYorN.substr(1, 1);
								}
							}

							//recherche de la variable AmortPercent qui contient le taux d'amortissement
							if (strcmp(Component->FirstChild("NAME")->ToElement()->GetText(), "AmortPercent") == 0)
							{
								if (Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText())
								{
									tauxAmort = Component->FirstChild("FORMULA")->FirstChild("FORMULA_STRING")->ToElement()->GetText();
								}
							}



						}
						Component = Component->NextSiblingElement();
					} // fin de while (Component)

					//***  Gestion des exceptions

					if (nominalString != "")
					{
						nominalDouble = atof(nominalString.c_str());
						if (nominalDouble == 0) // si le nominal est nul
						{
							throw string("Erreur dans la composante NOTIONAL!");
						}
						nominal.push_back(nominalDouble);


						if (amortYorN == "Y" && tauxAmort != "" && freq != "" && startDate != "" && endDate != "" && formuleAmort != "") //si le nominal est amorti
						{
							//chercher la startDate et endDate, faire la différence * freq
							//pour avoir le nombre d'éléments du vecteur nominal


							amortRate = this->eff_convert_rate(tauxAmort);

							freqQ = this->eff_convert_frequency(freq[0]);
							int nombre_fois = this->eff_freq_int(freqQ);
							//*** Dates

							DateMust* startDateNominal = new DateMust(path, startDate, tradeId);
							DateMust* endDateNominal = new DateMust(path, endDate, tradeId);


							this->AmortNotional(startDateNominal->dateQ, endDateNominal->dateQ, nombre_fois, formuleAmort);
							// fin test

						}
						else
						{
							amortRate = 0;
						}


					} // fin de if (nominalString!=0)
					else // si le nominal n'existe pas
					{
						throw string("Erreur dans la composante NOTIONAL!");
					}
				}
				Trade = Trade->NextSiblingElement();
			} //fin de while(Trade)

		}

	}






	//attributs

	std::vector<Real> nominal;
	string principalCcy;
	string tauxAmort;
	Rate amortRate;


	string amortYorN;
	string freq;
	Frequency freqQ;

	string startDate;
	Date startDateQ;


	string endDate;
	Date endDateQ;

	string formuleAmort;


	//*** Méthode d'amortissement
private:
	void AmortNotional(Date startDate, Date endDate, int periodicite, string formule)
	{
		int duration = (endDate.year() - startDate.year()) * periodicite;

		if (duration > 0)
		{
			int signeFounder = formule.find("-");
			double signe;
			if (signeFounder != string::npos)	signe = -1;
			else  signe = 1;

			for (int i = 1; i < duration; i++)
			{

				Real valAmorti = this->nominal[i - 1] + signe * 0.01*this->amortRate* this->nominal[0];
				this->nominal.push_back(valAmorti);
			}
		}
		else
		{
			throw string("Erreur dans les dates");
		}

	}
};

#endif