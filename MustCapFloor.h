#pragma once
#include"MustProduct.h"

//#include "CurveDataMod.hpp"
#include <ql/quantlib.hpp>
using namespace QuantLib;


//****
using namespace QuantLib;




class MustCapFloor : public MustProduct
{
public:
	MustCapFloor(ComponentPrincipalMust principal, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust startDate, DateMust endDate, RateMust fixe_dRate);


	double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName) override;

	boost::shared_ptr< PricingEngine >  SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) override;



	//double PriceNada_Imane();


#pragma region"CapFloor s Parametres"
	ComponentCashFlowMust floating_LegFlow;
	ComponentPrincipalMust principal;
	ComponentIndexMust index;
	DateMust startDate;
	DateMust endDate;
	RateMust fixed_Rate;
#pragma endregion 
};