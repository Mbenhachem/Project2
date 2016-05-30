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
	boost::shared_ptr< VanillaSwap >  constructVanillaSwap(boost::shared_ptr<IborIndex> myIndex){
		//FixedLeg
		SwapFixedLeg* fixed_Leg = new SwapFixedLeg(fixed_Rate.matrixRate, fixed_LegFlow.basisQ, fixed_LegFlow.freqQ);

		//FloatingLeg
		SwapFloatingLeg* floating_leg = new SwapFloatingLeg(myIndex, floating_LegFlow.basisQ, floating_LegFlow.freqQ);

			VanillaSwap::Type swapType = VanillaSwap::Payer;
			Settlement::Type settlementType = Settlement::Cash;

			boost::shared_ptr<VanillaSwap> swap(
			new VanillaSwap(swapType, principal.nominal[0],
			fixed_Leg->fixedSchedule(maturity.dateQ, tenor.dateQ), fixedRatesFreq(fixed_Rate.matrixRate, maturity.dateQ, tenor.dateQ, fixed_LegFlow.freqQ)[0], fixed_LegFlow.basisQ,
			floating_leg->floatSchedule(maturity.dateQ, tenor.dateQ), myIndex, fixedRatesFreq(index.matrixSpread, maturity.dateQ, tenor.dateQ, floating_LegFlow.freqQ)[0],
			floating_LegFlow.basisQ));
			return 0;
	}

	std::vector<Real> fixedRatesFreq(std::vector<std::tuple<Date, Date, Real>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency)
	{
		std::vector<Real> fixedRateFreq;
		//int nmbrofPeriode = 12 * Actual360().yearFraction(settlementDate, maturity);

		//int i = 1;


		Date startDate = settlementDate;
		startDate.operator+=(Period(fixedLegFrequency));
		int j = 0;
		while (startDate < maturity){

			while (startDate > std::get<1>(matrixRate[j])) { j++; }

			fixedRateFreq.push_back(std::get<2>(matrixRate[j]));
			startDate.operator+=(Period(fixedLegFrequency));
		}
		return fixedRateFreq;

	}

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

