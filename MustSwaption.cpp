#include <ql/quantlib.hpp>
#include "SwapFixedLeg.h"
#include "SwapFloatingLeg.h"
#include "MustSwaption.h"




MustSwaption::MustSwaption(ComponentPrincipalMust principal, ComponentCashFlowMust fixedLeg, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust maturity, DateMust tenor, RateMust fixed_Rate)
:principal(principal), fixed_LegFlow(fixedLeg), floating_LegFlow(floatingLeg), index(index), maturity(maturity), tenor(tenor), fixed_Rate(fixed_Rate)
{

}
boost::shared_ptr< PricingEngine >  MustSwaption::SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure){
	return 0;
}

double MustSwaption::Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName)
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
		fixedLeg = fixed_Leg->constructLeg(maturity.dateQ, tenor.dateQ, principal.nominal);
		floatingLeg = floating_leg->ConstructLeg(maturity.dateQ, tenor.dateQ, principal.nominal);
	}
	else
	{
		fixedLeg = fixed_Leg->constructLeg(maturity.dateQ, tenor.dateQ, principal.nominal);
		floatingLeg = floating_leg->ConstructLeg(maturity.dateQ, tenor.dateQ, principal.nominal, index.matrixSpread);
	}


	//SwapType
	//VanillaSwap::Type swapType = VanillaSwap::Payer;
	Settlement::Type settlementType = Settlement::Cash;
	Swap swap(fixedLeg, floatingLeg);

	/*Swaption swaption(new Swaption(swap,
		boost::shared_ptr<Exercise>(
		new EuropeanExercise(maturity.dateQ)), settlementType));*/

	return 0;
}


