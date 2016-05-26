
using namespace QuantLib;
#include "CurveData.hpp"
#include "SwapFixedLeg.h"
#include "SwapFloatingLeg.h"
//#include "Volatility.hpp"

class MustPricer
{

public:
	double Price(MustProduct* must_Product, int i,string modelName)
	{

		//MustCurve
		CurveData curveData;
		// Fill out with some sample market data
		fillMktData(curveData);
		boost::shared_ptr<YieldTermStructure> ocurve = boostrapCurve(curveData);

		RelinkableHandle<YieldTermStructure> discountingTermStructure;
		// the one used for forward rate forecasting
		RelinkableHandle<YieldTermStructure> forecastingTermStructure;

		forecastingTermStructure.linkTo(ocurve);
		discountingTermStructure.linkTo(ocurve);


		return must_Product->Price(discountingTermStructure, forecastingTermStructure, i, modelName);
		//return must_Product->PriceNada_Imane(discountingTermStructure, forecastingTermStructure, i);

		//PriceNada_Imane
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////  Test /////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	

		void Test(){
		Real nominal = 1000000;
		Date settlementDate(18, January, 2016);
		Date maturity(20, January, 2020);
		Date startDate(20, January, 2016);
		startDate.operator+=(13*Period(Monthly));

		Frequency fixedLegFrequency = Semiannual;
		Frequency floatingLegFrequency = Semiannual;
		std::vector<Real> fixedRate; 
		fixedRate.push_back(0.0319378);
		
		DayCounter floatingLegDayCounter = Actual360();
		DayCounter fixedLegDayCounter = Actual365Fixed();
		
		std::vector<Real> nominals;
		double temps = 1000000;
		nominals.push_back(temps);
		/*nominals.push_back(temps+15000);
		nominals.push_back(temps + 30000);
		nominals.push_back(temps + 45000);
		nominals.push_back(temps + 60000);
		nominals.push_back(temps + 75000);
		nominals.push_back(temps + 90000);
		nominals.push_back(temps + 105000);
		nominals.push_back(temps + 120000);
		nominals.push_back(temps + 130000);*/
		int size = nominals.size();
		
		std::vector<Real> fixedRates;
		fixedRates.push_back(0.02);
	/*	fixedRates.push_back(0.0319378);
		fixedRates.push_back(0.0319378);
		fixedRates.push_back(0.0319378);
		fixedRates.push_back(0.0319378);*/
	
		

		std::vector <Date > dates;
		dates.push_back(Date(8, October, 2015));
		dates.push_back(Date(8, October, 2016));
		dates.push_back(Date(8, October, 2017));
		dates.push_back(Date(8, October, 2018));
		dates.push_back(Date(8, October, 2024));



		std::vector<std::tuple<Date, Date, Real>> matrixRate;
		matrixRate.push_back(std::make_tuple(dates[4], dates[4],fixedRates[0]));
	/*	matrixRate.push_back(std::make_tuple(dates[1], dates[1], fixedRates[1]));
		matrixRate.push_back(std::make_tuple(dates[2], dates[2], fixedRates[2]));
		matrixRate.push_back(std::make_tuple(dates[3], dates[3], fixedRates[3]));
		matrixRate.push_back(std::make_tuple(dates[4], dates[4],fixedRates[4]));*/

	/*	fixedRates.push_back(0.0319378);
		fixedRates.push_back(0.0319378);
		fixedRates.push_back(0.0319378);
		fixedRates.push_back(0.0319378);
		fixedRates.push_back(0.0319378);*/
		//fixedRates.push_back(0.0319378);
		/*fixedRates.push_back(0.0219378);
		fixedRates.push_back(0.0119378);
		fixedRates.push_back(0.0019378);
		fixedRates.push_back(0.0319378);*/

#pragma region"old"
		//MustCurve
		CurveData curveData;
		// Fill out with some sample market data
		fillMktData(curveData);
		boost::shared_ptr<YieldTermStructure> ocurve = boostrapCurve(curveData);

		RelinkableHandle<YieldTermStructure> discountingTermStructure;
		// the one used for forward rate forecasting
		RelinkableHandle<YieldTermStructure> forecastingTermStructure;

		forecastingTermStructure.linkTo(ocurve);
		discountingTermStructure.linkTo(ocurve);

		//index
		//boost::shared_ptr<IborIndex> euribor(new Euribor6M(forecastingTermStructure));
		//boost::shared_ptr<IborIndex> euribor(new Euribor(6 * Months, forecastingTermStructure));

		boost::shared_ptr<IborIndex> euribor(new IborIndex("Euribor", 6 * Months, 2, EURCurrency(), TARGET(), ModifiedFollowing, 1, Actual360(), forecastingTermStructure));

		//euribor->addFixing(euribor->fixingDate(settlementDate), 0.01, true);
		//SwapType
		//VanillaSwap::Type swapType = VanillaSwap::Payer;
		//FixedLeg
		SwapFixedLeg* fixed_Leg = new SwapFixedLeg(matrixRate, fixedLegDayCounter, fixedLegFrequency);
		//FloatingLeg
	
		SwapFloatingLeg* floating_leg = new SwapFloatingLeg(euribor, floatingLegDayCounter, floatingLegFrequency);


		Spread myspread = 0.02;
		std::vector<Spread> spreads;
		spreads.push_back(0.02);
	/*	spreads.push_back(0.02);
		spreads.push_back(0.018);
		spreads.push_back(0.016);
		spreads.push_back(0.014);*/
	/*	spreads.push_back(0.012);
		spreads.push_back(0.010);
		spreads.push_back(0.008);
		spreads.push_back(0.006);
		spreads.push_back(0.004);
		spreads.push_back(0.002);*/
		std::vector<std::tuple<Date, Date, Real>> matrixSpread;
		matrixSpread.push_back(std::make_tuple(dates[4], dates[4], spreads[0]));
		/*matrixRate.push_back(std::make_tuple(dates[1], dates[1], fixedRates[1]));
		matrixRate.push_back(std::make_tuple(dates[2], dates[2], fixedRates[2]));
		matrixRate.push_back(std::make_tuple(dates[3], dates[3], fixedRates[3]));
		matrixRate.push_back(std::make_tuple(dates[4], dates[4], fixedRates[4]));*/
	


		Leg floatingLeg = floating_leg->ConstructLeg(settlementDate, maturity, nominals, matrixSpread);
		Leg fixedLeg = fixed_Leg->constructLeg(settlementDate, maturity, nominals);
		
		/*
		int a = fixedLeg.size();
		boost::shared_ptr<CashFlow> btemp = fixedLeg[2];*/

		Swap must_Swap(fixedLeg, floatingLeg);
		Swap must_Swap2(floatingLeg, fixedLeg);
		boost::shared_ptr<PricingEngine> swapEngine(new DiscountingSwapEngine(discountingTermStructure));
		must_Swap.setPricingEngine(swapEngine);
		must_Swap2.setPricingEngine(swapEngine);
		double NPV = must_Swap.NPV();
		double NPV2 = must_Swap2.NPV();
		double FixedLEgNPV = must_Swap.legNPV(0);
		double FloatingLegNPV = must_Swap.legNPV(1);


	/*	HullWhite model(discountingTermStructure, 0.1, 0.01);
		Time mat = fixedLegDayCounter.yearFraction(settlementDate,
			maturity);
		Real disc = model.discount(mat);
		Real disc2 = discountingTermStructure->discount(mat);*/


		/*boost::shared_ptr<NormalDistribution> NormalLaw(0,1);
		Real *a = NormalLaw->operator();
		Real *b = NormalLaw->operator();*/

		
		




		////////////////////////TEst Pour CapFLoor ///////////////////////////////////////:


		//Leg
		Leg capfloatingLeg;
		SwapFloatingLeg* Capfloating_leg = new SwapFloatingLeg(euribor, floatingLegDayCounter, floatingLegFrequency);
		
			capfloatingLeg = Capfloating_leg->ConstructLeg(settlementDate, maturity, nominals);
	

			Rate Strike = 0.018;
		std:vector<Rate> Strikes;
			Strikes.push_back(0.01);
			Strikes.push_back(0.018);
	/*		Strikes.push_back(0.019);
			Strikes.push_back(0.021);
			Strikes.push_back(0.021);
			Strikes.push_back(0.021);
			Strikes.push_back(0.021);
			Strikes.push_back(0.021);*/


			boost::shared_ptr<CapFloor> CapFloor(new Cap(capfloatingLeg, std::vector<Rate>(1, Strike)));


		//////vol
		//CapFloorVolatility capfloorVol;
		//capfloorVol.termStructure.linkTo(ocurve);
		//Handle<OptionletVolatilityStructure> capletsVolatilies;

		//capletsVolatilies = buildFlatCurveVol(capfloorVol);
		////capletsVolatilies = buildCurveOptionletAtmVol(capfloorVol);
		////capletsVolatilies = buildOptionletSurfaceVol(capfloorVol);
		////capletsVolatilies = buildOptionletCurveVol(cVol);


		///*capletsVolatilies->enableExtrapolation();*/
		Volatility vol = 0.1;
		//boost::shared_ptr<BlackCapFloorEngine> strippedVolEngine(new BlackCapFloorEngine(discountingTermStructure, capletsVolatilies));
		boost::shared_ptr<BlackCapFloorEngine> strippedVolEngine(new BlackCapFloorEngine(discountingTermStructure, vol));
		CapFloor->setPricingEngine(strippedVolEngine);

		double capNPV = CapFloor->NPV();


#pragma endregion



	}

	



	std::vector<Real> fixedRatesFreq(std::vector<std::tuple<Real, Date>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency) {
		std::vector<Real> fixedRateFreq;
		//int nmbrofPeriode = 12 * Actual360().yearFraction(settlementDate, maturity);

		//int i = 1;


		Date startDate = settlementDate;
		startDate.operator+=(Period(fixedLegFrequency));
		int j = 0;
		while (startDate < maturity){

			while (startDate > std::get<1>(matrixRate[j])) { j++; }

			fixedRateFreq.push_back(std::get<0>(matrixRate[j]));
			startDate.operator+=(Period(fixedLegFrequency));
		}
		return fixedRateFreq;

	}
};

