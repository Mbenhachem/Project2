#include <ql/quantlib.hpp>
#include "MustSwaption.h"



MustSwaption::MustSwaption(ComponentPrincipalMust principal, ComponentCashFlowMust fixedLeg, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust maturity, DateMust tenor, RateMust fixed_Rate)
:principal(principal), fixed_LegFlow(fixedLeg), floating_LegFlow(floatingLeg), index(index), maturity(maturity), tenor(tenor), fixed_Rate(fixed_Rate)
{

}
void MustSwaption::SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure)
{

	RelinkableHandle<YieldTermStructure> termStructure;	
	termStructure.linkTo(termStructureforLMM());
	boost::shared_ptr<IborIndex> index2(new Euribor6M(termStructure));
	//index2->fixingCalendar().adjust(Date(6, October, 2014));


	const Size size = 2 * Actual360().yearFraction(maturity.dateQ, tenor.dateQ);
	boost::shared_ptr<LiborForwardModelProcess> process(
		new LiborForwardModelProcess(size, index2));
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


	if (pricingEngineName == "LMM_QuantLib"){
		boost::shared_ptr<PricingEngine> engine(
			new LfmSwaptionEngine(liborModel,
			index2->forwardingTermStructure()));
		swaptionquantlibEngine= engine;
	}
	else{
		if (pricingEngineName == "SwapLMMEngine"){
			boost::shared_ptr<PricingEngine> engine(new DiscountingSwapEngine(index2->forwardingTermStructure()));
			swapquantlibEngine= engine;
		}
		
		
		else {
			SwaptionVolatility vol;
			vol.termStructure.linkTo(discountingTermStructure.currentLink());
			Handle<SwaptionVolatilityStructure> volatility = vol.atmVolMatrix;
			swaptionquantlibEngine= boost::shared_ptr<PricingEngine>(
				new BlackSwaptionEngine(discountingTermStructure, volatility));
		}
	}
}

double MustSwaption::Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName)
{
	RelinkableHandle<YieldTermStructure> termStructure;
	termStructure.linkTo(termStructureforLMM());
	//index
	boost::shared_ptr<IborIndex> myIndex = index.ConstructIndex(termStructure);


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
	Settlement::Type settlementType = Settlement::Physical;
	//Swap swap(fixedLeg, floatingLeg);
	boost::shared_ptr<VanillaSwap> swap = constructVanillaSwap(myIndex);

	if (pricingEngineName != "LMM_QuantLib") swapquantlibEngine = boost::shared_ptr<PricingEngine>(new DiscountingSwapEngine(discountingTermStructure));
	else {
		 SetPricingEngine("SwapLMMEngine", discountingTermStructure, forwardingTermStructure);
	}

	swap->setPricingEngine(swapquantlibEngine);
	Real a = swap->NPV();
	Date maturityDate = TARGET().advance(maturity.dateQ, -2, Days);
	boost::shared_ptr<Swaption> swaption(new Swaption(swap,
		boost::shared_ptr<Exercise>(
		new EuropeanExercise(maturity.dateQ)),
		settlementType));
	swaption->setPricingEngine(swaptionquantlibEngine);
	Real b = swaption->NPV();

	
	return b;
}


