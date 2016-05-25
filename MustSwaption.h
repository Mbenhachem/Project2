#pragma once
#include "ComponentPrincipalMust.h"
#include "ComponentCashFlowMust.h"
#include"ComponentIndexMust.h"
#include"DateMust.h"
#include"RateMust.h"
#include"MustProduct.h"
using namespace QuantLib;





class MustSwaption : public MustProduct
{
public:
	MustSwaption(ComponentPrincipalMust principal, ComponentCashFlowMust fixedLeg, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust maturity, DateMust tenor, RateMust fixed_Rate);
	
	boost::shared_ptr< PricingEngine >  SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) override;

	double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName) override;

#pragma region"Swaption's Parametres"
	ComponentCashFlowMust fixed_LegFlow;
	ComponentCashFlowMust floating_LegFlow;
	ComponentPrincipalMust principal;
	ComponentIndexMust index;
	DateMust maturity;
	DateMust tenor;
	RateMust fixed_Rate;
#pragma endregion
};

