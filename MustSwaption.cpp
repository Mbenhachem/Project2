#include <ql/quantlib.hpp>
#include "SwapFixedLeg.h"
#include "SwapFloatingLeg.h"
#include "MustSwaption.h"
#include "SwaptionVolatility.hpp"


MustSwaption::MustSwaption(ComponentPrincipalMust principal, ComponentCashFlowMust fixedLeg, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust maturity, DateMust tenor, RateMust fixed_Rate)
:principal(principal), fixed_LegFlow(fixedLeg), floating_LegFlow(floatingLeg), index(index), maturity(maturity), tenor(tenor), fixed_Rate(fixed_Rate)
{

}
boost::shared_ptr< PricingEngine >  MustSwaption::SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure){
	if (pricingEngineName == "LMMModèle"){
		//-----------------------------------LMM Engine -----------------------------------------------------
		boost::shared_ptr<IborIndex> index(new Euribor6M(discountingTermStructure));
		index->fixingCalendar().adjust(Date(6, October, 2014));
		const Size size = 20;
		boost::shared_ptr<LiborForwardModelProcess> process(
			new LiborForwardModelProcess(size, index));

		// set-up the model
		const Real a = 0.02;
		const Real b = 0.4;
		const Real c = 0.12;
		const Real d = 0.01;

		boost::shared_ptr<LmVolatilityModel> volaModel(
			new LmLinearExponentialVolatilityModel(process->fixingTimes(), a, b, c, d));
		boost::shared_ptr<LmCorrelationModel> corrModel(
			new LmLinearExponentialCorrelationModel(size, 0.1, 0.1));

		boost::shared_ptr<LiborForwardModel>
			liborModel(new LiborForwardModel(process, volaModel, corrModel));

		boost::shared_ptr<PricingEngine> engine(
			new LfmSwaptionEngine(liborModel,
			index->forwardingTermStructure()));
		return engine;
	}
	else{
		SwaptionVolatility vol;
		vol.termStructure.linkTo(discountingTermStructure.currentLink());
		Handle<SwaptionVolatilityStructure> volatility = vol.atmVolMatrix;
		return boost::shared_ptr<PricingEngine>(
			new BlackSwaptionEngine(discountingTermStructure, volatility));
	}
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
	VanillaSwap::Type swapType = VanillaSwap::Payer;
	Settlement::Type settlementType = Settlement::Cash;
	//Swap swap(fixedLeg, floatingLeg);
	boost::shared_ptr<VanillaSwap> swap = constructVanillaSwap(myIndex);

	
	boost::shared_ptr<Swaption> swaption(new Swaption(swap,
		boost::shared_ptr<Exercise>(
		new EuropeanExercise(maturity.dateQ)),
		settlementType));
	swaption->setPricingEngine(SetPricingEngine(pricingEngineName, discountingTermStructure, forwardingTermStructure));

	return swaption->NPV();
}


