#include <ql/quantlib.hpp>
#include "SwapFixedLeg.h"
#include "SwapFloatingLeg.h"
#include "MustProduct.h"
#include "MustVanilleSwap.h"

using namespace std;
using namespace QuantLib;
using namespace boost;





MustVanilleSwap::MustVanilleSwap(ComponentPrincipalMust principal, ComponentCashFlowMust fixedLeg, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust starDate, DateMust endDate, RateMust fixed_Rate)
:principal(principal), fixed_LegFlow(fixedLeg), floating_LegFlow(floatingLeg), index(index), startDate(starDate), endDate(endDate), fixed_Rate(fixed_Rate)
{

}

boost::shared_ptr< PricingEngine >  MustVanilleSwap::SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure)
{
	boost::shared_ptr<PricingEngine> swapEngine(new DiscountingSwapEngine(discountingTermStructure));
	return swapEngine;
}
double MustVanilleSwap::Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName)
{
	//index
	boost::shared_ptr<IborIndex> myIndex = index.ConstructIndex(forwardingTermStructure);


	//FixedLeg
	SwapFixedLeg* fixed_Leg = new SwapFixedLeg(fixed_Rate.matrixRate, fixed_LegFlow.basisQ, fixed_LegFlow.freqQ);

	//FloatingLeg
	SwapFloatingLeg* floating_leg = new SwapFloatingLeg(myIndex, floating_LegFlow.basisQ, floating_LegFlow.freqQ);

	Leg fixedLeg;
	Leg floatingLeg;


	if (index.spreads.size()<1) //condition to check the Sread
	{
		fixedLeg = fixed_Leg->constructLeg(startDate.dateQ, endDate.dateQ, principal.nominal);
		floatingLeg = floating_leg->ConstructLeg(startDate.dateQ, endDate.dateQ, principal.nominal);
	}
	else
	{
		fixedLeg = fixed_Leg->constructLeg(startDate.dateQ, endDate.dateQ, principal.nominal);
		floatingLeg = floating_leg->ConstructLeg(startDate.dateQ, endDate.dateQ, principal.nominal, index.matrixSpread);
	}


	//SwapType
	//VanillaSwap::Type swapType = VanillaSwap::Payer;
	Swap swap(fixedLeg, floatingLeg);
	boost::shared_ptr<PricingEngine> swapEngine = SetPricingEngine(pricingEngineName, discountingTermStructure, forwardingTermStructure);
	swap.setPricingEngine(swapEngine);

	if (i == 1)
	{
		return swap.NPV();
	}
	else{
		if (i == 2){ return swap.legNPV(0); }
		else{ return swap.legNPV(1); }
	}

}
