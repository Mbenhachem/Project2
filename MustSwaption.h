#pragma once
#include"MustProduct.h"
#include "SwaptionVolatility.hpp"

using namespace QuantLib;






class MustSwaption : public MustProduct
{
public:
	MustSwaption(ComponentPrincipalMust principal, ComponentCashFlowMust fixedLeg, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust maturity, DateMust tenor, RateMust fixed_Rate);
	
	void  SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) override;

	double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName) override;
	boost::shared_ptr< VanillaSwap >  constructVanillaSwap(boost::shared_ptr<IborIndex> myIndex){
		//FixedLeg
		SwapFixedLeg* fixed_Leg = new SwapFixedLeg(fixed_Rate.matrixRate, fixed_LegFlow.basisQ, fixed_LegFlow.freqQ);

		//FloatingLeg
		SwapFloatingLeg* floating_leg = new SwapFloatingLeg(myIndex, floating_LegFlow.basisQ, floating_LegFlow.freqQ);

			VanillaSwap::Type swapType = VanillaSwap::Payer;
			Settlement::Type settlementType = Settlement::Cash;


			Real fixedrate = fixedRatesFreq(fixed_Rate.matrixRate, maturity.dateQ, tenor.dateQ, fixed_LegFlow.freqQ)[0];
			//Real fixedSpread = fixedRatesFreq(index.matrixSpread, maturity.dateQ, tenor.dateQ, floating_LegFlow.freqQ)[0];
			boost::shared_ptr<VanillaSwap> swap(
			new VanillaSwap(swapType, principal.nominal[0],
			fixed_Leg->fixedSchedule(maturity.dateQ, tenor.dateQ), fixedrate, fixed_LegFlow.basisQ,
			floating_leg->floatSchedule(maturity.dateQ, tenor.dateQ), myIndex, 0.0,
			floating_LegFlow.basisQ));
			return swap;
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
	boost::shared_ptr< PricingEngine > swapquantlibEngine;
	boost::shared_ptr< PricingEngine > swaptionquantlibEngine;
	ComponentCashFlowMust fixed_LegFlow;
	ComponentCashFlowMust floating_LegFlow;
	ComponentPrincipalMust principal;
	ComponentIndexMust index;
	DateMust maturity;
	DateMust tenor;
	RateMust fixed_Rate;
#pragma endregion



	boost::shared_ptr<YieldTermStructure>   termStructureforLMM(){

#pragma region Vetor of Dates
		std::vector <Date > dates;
		//dates.push_back(Date(6, October, 2014));
		dates.push_back(Date(8, October, 2014));
		dates.push_back(Date(15, October, 2014)); dates.push_back(Date(22, October, 2014)); dates.push_back(Date(29, October, 2014));
		dates.push_back(Date(10, November, 2014)); dates.push_back(Date(8, December, 2014)); dates.push_back(Date(8, January, 2015));
		dates.push_back(Date(9, Feb, 2015)); dates.push_back(Date(9, March, 2015)); dates.push_back(Date(8, April, 2015));
		dates.push_back(Date(8, July, 2015));
		dates.push_back(Date(8, October, 2015));


		dates.push_back(Date(8, April, 2016)); dates.push_back(Date(10, October, 2016)); dates.push_back(Date(10, April, 2017));
		dates.push_back(Date(9, October, 2017)); dates.push_back(Date(9, April, 2018)); dates.push_back(Date(8, October, 2018));
		dates.push_back(Date(8, April, 2019)); dates.push_back(Date(8, October, 2019)); dates.push_back(Date(8, April, 2020));
		dates.push_back(Date(8, October, 2020));


		dates.push_back(Date(8, April, 2021)); dates.push_back(Date(8, October, 2021)); dates.push_back(Date(8, April, 2022));
		dates.push_back(Date(10, October, 2022)); dates.push_back(Date(10, April, 2023)); dates.push_back(Date(9, October, 2023));
		dates.push_back(Date(8, April, 2024)); dates.push_back(Date(8, October, 2024)); dates.push_back(Date(8, April, 2025));
		dates.push_back(Date(8, October, 2025));

		dates.push_back(Date(8, April, 2026)); dates.push_back(Date(8, October, 2026)); dates.push_back(Date(8, April, 2027));
		dates.push_back(Date(8, October, 2027)); dates.push_back(Date(10, April, 2028)); dates.push_back(Date(9, October, 2028));
		dates.push_back(Date(9, April, 2029)); dates.push_back(Date(8, October, 2029)); dates.push_back(Date(8, April, 2030));
		dates.push_back(Date(8, October, 2030));

		dates.push_back(Date(8, April, 2031)); dates.push_back(Date(8, October, 2031)); dates.push_back(Date(8, April, 2032));
		dates.push_back(Date(8, October, 2032)); dates.push_back(Date(8, April, 2033)); dates.push_back(Date(10, October, 2033));
		dates.push_back(Date(10, April, 2034)); dates.push_back(Date(9, October, 2034)); dates.push_back(Date(9, April, 2035));
		dates.push_back(Date(8, October, 2035));


		dates.push_back(Date(8, April, 2036)); dates.push_back(Date(8, October, 2036)); dates.push_back(Date(8, April, 2037));
		dates.push_back(Date(8, October, 2037)); dates.push_back(Date(8, April, 2038)); dates.push_back(Date(10, October, 2038));
		dates.push_back(Date(8, April, 2039)); dates.push_back(Date(10, October, 2039)); dates.push_back(Date(9, April, 2040));
		dates.push_back(Date(8, October, 2040));

		dates.push_back(Date(8, April, 2041)); dates.push_back(Date(8, October, 2041)); dates.push_back(Date(8, April, 2042));
		dates.push_back(Date(8, October, 2042)); dates.push_back(Date(8, April, 2043)); dates.push_back(Date(8, October, 2043));
		dates.push_back(Date(8, April, 2044)); dates.push_back(Date(10, October, 2044)); dates.push_back(Date(10, April, 2045));
		dates.push_back(Date(9, October, 2045));

		dates.push_back(Date(9, April, 2046)); dates.push_back(Date(8, October, 2046)); dates.push_back(Date(8, April, 2047));
		dates.push_back(Date(8, October, 2047)); dates.push_back(Date(8, April, 2048)); dates.push_back(Date(8, October, 2048));
		dates.push_back(Date(8, April, 2049)); dates.push_back(Date(8, October, 2049)); dates.push_back(Date(8, April, 2050));
		dates.push_back(Date(10, October, 2050));

		dates.push_back(Date(10, April, 2051)); dates.push_back(Date(9, October, 2051)); dates.push_back(Date(8, April, 2052));
		dates.push_back(Date(8, October, 2052)); dates.push_back(Date(8, April, 2053)); dates.push_back(Date(8, October, 2053));
		dates.push_back(Date(8, April, 2054)); dates.push_back(Date(8, October, 2054)); dates.push_back(Date(8, April, 2055));
		dates.push_back(Date(8, October, 2055));

		dates.push_back(Date(10, April, 2056)); dates.push_back(Date(9, October, 2056)); dates.push_back(Date(9, April, 2057));
		dates.push_back(Date(8, October, 2057));	dates.push_back(Date(8, April, 2058)); dates.push_back(Date(8, October, 2058));
		dates.push_back(Date(8, April, 2059)); dates.push_back(Date(8, October, 2059)); dates.push_back(Date(8, April, 2060));
		dates.push_back(Date(8, October, 2060));

		dates.push_back(Date(8, April, 2061)); dates.push_back(Date(10, October, 2061)); dates.push_back(Date(10, April, 2062));
		dates.push_back(Date(9, October, 2062)); dates.push_back(Date(9, April, 2063));	dates.push_back(Date(8, October, 2063));
		dates.push_back(Date(8, April, 2064)); dates.push_back(Date(8, October, 2064));
#pragma endregion
#pragma region Vetor of Zero Rates
		std::vector <Rate> rates;
		//rates.push_back(0.0010443);
		rates.push_back(0.0010443);
		rates.push_back(0.0010362); rates.push_back(0.0010974); rates.push_back(0.0011738);
		rates.push_back(0.0012927); rates.push_back(0.0017803); rates.push_back(0.002284);
		rates.push_back(0.0026595); rates.push_back(0.0030738); rates.push_back(0.0032179);
		rates.push_back(0.0035759);
		rates.push_back(0.0041893);


		rates.push_back(0.0048391); rates.push_back(0.0054949); rates.push_back(0.0063631);
		rates.push_back(0.0072329); rates.push_back(0.008357); rates.push_back(0.009485);
		rates.push_back(0.0105954); rates.push_back(0.0117163); rates.push_back(0.012785);
		rates.push_back(0.013861);


		rates.push_back(0.0148198); rates.push_back(0.01579); rates.push_back(0.016666);
		rates.push_back(0.0175575); rates.push_back(0.0183587); rates.push_back(0.0191663);
		rates.push_back(0.0198951); rates.push_back(0.020634); rates.push_back(0.0212737);
		rates.push_back(0.0219226);

		rates.push_back(0.024871); rates.push_back(0.02354); rates.push_back(0.024029);
		rates.push_back(0.024439); rates.push_back(0.0248467); rates.push_back(0.025188);
		rates.push_back(0.0255331); rates.push_back(0.0257927); rates.push_back(0.026058);
		rates.push_back(0.0262584);

		rates.push_back(0.0264638); rates.push_back(0.0266057); rates.push_back(0.0267497);
		rates.push_back(0.0268551); rates.push_back(0.0268641); rates.push_back(0.0268515);
		rates.push_back(0.0267405); rates.push_back(0.0269932); rates.push_back(0.0272895);
		rates.push_back(0.027331);


		rates.push_back(0.02736848); rates.push_back(0.024064); rates.push_back(0.0274328);
		rates.push_back(0.027442); rates.push_back(0.0274546); rates.push_back(0.0274679);
		rates.push_back(0.0272456); rates.push_back(0.0270252); rates.push_back(0.0272445);
		rates.push_back(0.0274675);

		rates.push_back(0.0274549); rates.push_back(0.027443); rates.push_back(0.0274397);
		rates.push_back(0.0274369); rates.push_back(0.0272012); rates.push_back(0.0269648);
		rates.push_back(0.0270072); rates.push_back(0.0270501); rates.push_back(0.0270936);
		rates.push_back(0.0271378);

		rates.push_back(0.0271825); rates.push_back(0.027228); rates.push_back(0.072745);
		rates.push_back(0.0273209); rates.push_back(0.0273679); rates.push_back(0.074158);
		rates.push_back(0.0274386); rates.push_back(0.027622); rates.push_back(0.0274859);
		rates.push_back(0.0275101);

		rates.push_back(0.0275347); rates.push_back(0.027559); rates.push_back(0.0275854);
		rates.push_back(0.0276115); rates.push_back(0.0276376); rates.push_back(0.0276648);
		rates.push_back(0.0276857); rates.push_back(0.027707); rates.push_back(0.027729);
		rates.push_back(0.0277511);

		rates.push_back(0.0277736); rates.push_back(0.0277964); rates.push_back(0.0278196);
		rates.push_back(0.0278434);	rates.push_back(0.0278674); rates.push_back(0.0278919);
		rates.push_back(0.02792222); rates.push_back(0.0279528); rates.push_back(0.0279837);
		rates.push_back(0.0280156);

		rates.push_back(0.0280473); rates.push_back(0.0280795); rates.push_back(0.0281121);
		rates.push_back(0.0281451); rates.push_back(0.0281788);	rates.push_back(0.028219);
		rates.push_back(0.028219); rates.push_back(0.028219);
#pragma endregion
		RelinkableHandle<YieldTermStructure> termStructure;
		DayCounter termStructureDayCounter = Actual360();
		boost::shared_ptr<YieldTermStructure> termstructure(new ZeroCurve(dates, rates, termStructureDayCounter));
		return termstructure;

	}
};

