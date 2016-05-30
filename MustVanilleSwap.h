#pragma once
#include "ComponentPrincipalMust.h"
#include "ComponentCashFlowMust.h"
#include"ComponentIndexMust.h"
#include"DateMust.h"
#include"RateMust.h"
#include"MustProduct.h"
using namespace QuantLib;






class MustVanilleSwap : public MustProduct
{
public:
	MustVanilleSwap(ComponentPrincipalMust principal, ComponentCashFlowMust fixedLeg, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust startDate, DateMust endDate, RateMust fixe_dRate);

	/*MustVanilleSwap(Real nominal, Date settlementDate, Date maturity, Frequency fixedLegFrequency, DayCounter fixedLegDayCounter, Rate fixedRate, DayCounter floatingLegDayCounter, Frequency floatingLegFrequency);
	MustVanilleSwap(std::vector<Real> nominals, Date settlementDate, Date maturity, Frequency fixedLegFrequency, DayCounter fixedLegDayCounter, Rate fixedRate, DayCounter floatingLegDayCounter, Frequency floatingLegFrequency);
	*/
	double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName) override;
	boost::shared_ptr< PricingEngine >  SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) override;



#pragma region"Swap Vanille's Parametres"
	/*
	//Notionnel
	std::vector<Real> nominals;
	Real nominal;
	Date settlementDate;
	Date maturity;
	//FixedLeg
	Frequency fixedLegFrequency;
	DayCounter fixedLegDayCounter;
	Rate fixedRate;
	//FloatingLeg
	DayCounter floatingLegDayCounter;
	Frequency floatingLegFrequency;
	*/

	ComponentCashFlowMust fixed_LegFlow;
	ComponentCashFlowMust floating_LegFlow;
	ComponentPrincipalMust principal;
	ComponentIndexMust index;
	DateMust startDate;
	DateMust endDate;
	RateMust fixed_Rate;
#pragma endregion 

};
