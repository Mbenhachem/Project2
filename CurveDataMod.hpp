#ifndef CURVEDATAMOD_H
#define CURVEDATAMOD_H

#include <boost/format.hpp>
#include <boost/foreach.hpp>
#include <boost/timer.hpp>
#include <iostream> 
#include <ql/quantlib.hpp>
#include <ql/math/matrix.hpp>
#include "Volatility.hpp"
/*
Permet de construire les courbes de taux
Utilisation des instruments RateHelper
Donnée d'entrée pour les interpolations
*/



using namespace QuantLib;


/// A structure to hold all the market quotes for a single curve
/// together
struct CurveData2{
public:
	std::vector<float> Calcul_Fwd(); // Retourne les taux forward initiaux calculé par les données de Must .
	void Test_Affichage();// Affiche les taux forward initiaux

#pragma region SWAP Rate
	boost::shared_ptr<SimpleQuote>  s1yRate;
	boost::shared_ptr<SimpleQuote>  s2yRate;
	boost::shared_ptr<SimpleQuote>  s3yRate;
	boost::shared_ptr<SimpleQuote>  s4yRate;
	boost::shared_ptr<SimpleQuote>  s5yRate;
	boost::shared_ptr<SimpleQuote>  s6yRate;
	boost::shared_ptr<SimpleQuote>  s7yRate;
	boost::shared_ptr<SimpleQuote>  s8yRate;
	boost::shared_ptr<SimpleQuote>  s9yRate;
	boost::shared_ptr<SimpleQuote>  s10yRate;
	boost::shared_ptr<SimpleQuote>  s11yRate;
	boost::shared_ptr<SimpleQuote>  s12yRate;
	boost::shared_ptr<SimpleQuote>  s13yRate;
	boost::shared_ptr<SimpleQuote>  s14yRate;
	boost::shared_ptr<SimpleQuote>  s15yRate;
	boost::shared_ptr<SimpleQuote>  s16yRate;
	boost::shared_ptr<SimpleQuote>  s17yRate;
	boost::shared_ptr<SimpleQuote>  s18yRate;
	boost::shared_ptr<SimpleQuote>  s19yRate;
	boost::shared_ptr<SimpleQuote>  s20yRate;
	boost::shared_ptr<SimpleQuote>  s21yRate;
	boost::shared_ptr<SimpleQuote>  s22yRate;
	boost::shared_ptr<SimpleQuote>  s23yRate;
	boost::shared_ptr<SimpleQuote>  s24yRate;
	boost::shared_ptr<SimpleQuote>  s25yRate;
	boost::shared_ptr<SimpleQuote>  s26yRate;
	boost::shared_ptr<SimpleQuote>  s27yRate;
	boost::shared_ptr<SimpleQuote>  s28yRate;
	boost::shared_ptr<SimpleQuote>  s29yRate;
	boost::shared_ptr<SimpleQuote>  s30yRate;
	boost::shared_ptr<SimpleQuote>  s35yRate;
	boost::shared_ptr<SimpleQuote>  s40yRate;
	boost::shared_ptr<SimpleQuote>  s45yRate;
	boost::shared_ptr<SimpleQuote>  s50yRate;
#pragma endregion 

#pragma region Money Market Rate
	boost::shared_ptr<SimpleQuote>  Mm1dRate;
	boost::shared_ptr<SimpleQuote>  Mm1wRate;
	boost::shared_ptr<SimpleQuote>  Mm2wRate;
	boost::shared_ptr<SimpleQuote>  Mm3wRate;
	boost::shared_ptr<SimpleQuote>  Mm1mRate;
	boost::shared_ptr<SimpleQuote>  Mm2mRate;
	boost::shared_ptr<SimpleQuote>  Mm3mRate;
	boost::shared_ptr<SimpleQuote>  Mm4mRate;
	boost::shared_ptr<SimpleQuote>  Mm5mRate;
	boost::shared_ptr<SimpleQuote>  Mm6mRate;
	boost::shared_ptr<SimpleQuote>  Mm9mRate;
	boost::shared_ptr<SimpleQuote>  Mm12mRate;
#pragma endregion 

#pragma region Simple Quote Definition
	CurveData2() :

		s1yRate(new SimpleQuote()),
		s2yRate(new SimpleQuote()),
		s3yRate(new SimpleQuote()),
		s4yRate(new SimpleQuote()),
		s5yRate(new SimpleQuote()),
		s6yRate(new SimpleQuote()),
		s7yRate(new SimpleQuote()),
		s8yRate(new SimpleQuote()),
		s9yRate(new SimpleQuote()),
		s10yRate(new SimpleQuote()),
		s11yRate(new SimpleQuote()),
		s12yRate(new SimpleQuote()),
		s13yRate(new SimpleQuote()),
		s14yRate(new SimpleQuote()),
		s15yRate(new SimpleQuote()),
		s16yRate(new SimpleQuote()),
		s17yRate(new SimpleQuote()),
		s18yRate(new SimpleQuote()),
		s19yRate(new SimpleQuote()),
		s20yRate(new SimpleQuote()),
		s21yRate(new SimpleQuote()),
		s22yRate(new SimpleQuote()),
		s23yRate(new SimpleQuote()),
		s24yRate(new SimpleQuote()),
		s25yRate(new SimpleQuote()),
		s26yRate(new SimpleQuote()),
		s27yRate(new SimpleQuote()),
		s28yRate(new SimpleQuote()),
		s29yRate(new SimpleQuote()),
		s30yRate(new SimpleQuote()),
		s35yRate(new SimpleQuote()),
		s40yRate(new SimpleQuote()),
		s45yRate(new SimpleQuote()),
		s50yRate(new SimpleQuote()),
		Mm1dRate(new SimpleQuote()),
		Mm1wRate(new SimpleQuote()),
		Mm2wRate(new SimpleQuote()),
		Mm3wRate(new SimpleQuote()),
		Mm1mRate(new SimpleQuote()),
		Mm2mRate(new SimpleQuote()),
		Mm3mRate(new SimpleQuote()),
		Mm4mRate(new SimpleQuote()),
		Mm5mRate(new SimpleQuote()),
		Mm6mRate(new SimpleQuote()),
		Mm9mRate(new SimpleQuote()),
		Mm12mRate(new SimpleQuote())
	{}
#pragma endregion 

	void sampleMktData2(CurveData2 &cd);

};


void sampleMktData2(CurveData2 &cd)
{
	// taux swaps
#pragma region SWAP RATE data

	(*cd.s1yRate) = 0.00421;
	(*cd.s2yRate) = 0.00551;
	(*cd.s3yRate) = 0.00724;
	(*cd.s4yRate) = 0.00947;
	(*cd.s5yRate) = 0.01166;
	(*cd.s6yRate) = 0.013745;
	(*cd.s7yRate) = 0.0156;
	(*cd.s8yRate) = 0.01728;
	(*cd.s9yRate) = 0.01879;
	(*cd.s10yRate) = 0.02015;
	(*cd.s11yRate) = 0.02133;
	(*cd.s12yRate) = 0.02236;
	(*cd.s13yRate) = 0.02323;
	(*cd.s14yRate) = 0.02396;
	(*cd.s15yRate) = 0.02457;
	(*cd.s16yRate) = 0.02504;
	(*cd.s17yRate) = 0.02541;
	(*cd.s18yRate) = 0.02568;
	(*cd.s19yRate) = 0.02589;
	(*cd.s20yRate) = 0.02577;
	(*cd.s21yRate) = 0.02618;
	(*cd.s22yRate) = 0.02628;
	(*cd.s23yRate) = 0.02637;
	(*cd.s24yRate) = 0.02643;
	(*cd.s25yRate) = 0.02648;
	(*cd.s26yRate) = 0.02621;
	(*cd.s27yRate) = 0.02653;
	(*cd.s28yRate) = 0.02654;
	(*cd.s29yRate) = 0.02656;
	(*cd.s30yRate) = 0.02628;
	(*cd.s35yRate) = 0.026639;
	(*cd.s40yRate) = 0.02685;
	(*cd.s45yRate) = 0.027027;
	(*cd.s50yRate) = 0.02723;
#pragma endregion 
#pragma region Money Market RATE data
	//Money Market
	(*cd.Mm1dRate) = 0.00103;
	(*cd.Mm1wRate) = 0.00102;
	(*cd.Mm2wRate) = 0.00109;
	(*cd.Mm3wRate) = 0.00117;
	(*cd.Mm1mRate) = 0.00129;
	(*cd.Mm2mRate) = 0.00178;
	(*cd.Mm3mRate) = 0.00228;
	(*cd.Mm4mRate) = 0.00265;
	(*cd.Mm5mRate) = 0.00306;
	(*cd.Mm6mRate) = 0.0032;
	(*cd.Mm9mRate) = 0.00355;
	(*cd.Mm12mRate) = 0.0037;
#pragma endregion 


}

//La construction de la courbe des taux à partir des données de MUST

boost::shared_ptr<YieldTermStructure> buildCurve2(const CurveData2 &cd)
{
	Calendar calendar = TARGET();
	Date today(6, October, 2014);
	today = calendar.adjust(today);
	Settings::instance().evaluationDate() = today;
	Natural settlementDays = 2;
	Natural  fixingDays = 1;
	Date  settlementDate = calendar.adjust(today + 1 * Days);
	DayCounter depositDayCounter = Actual360();


	//calcul des ZC à partir des segments MoneyMarket

#pragma region Money Market RateHelper 
	boost::shared_ptr<RateHelper> Mm1d(new DepositRateHelper(Handle<Quote>(cd.Mm1dRate), 1 * Days, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm1w(new DepositRateHelper(Handle<Quote>(cd.Mm1wRate), 1 * Weeks, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm2w(new DepositRateHelper(Handle<Quote>(cd.Mm2wRate), 2 * Weeks, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm3w(new DepositRateHelper(Handle<Quote>(cd.Mm3wRate), 3 * Weeks, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm1m(new DepositRateHelper(Handle<Quote>(cd.Mm1mRate), 1 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm2m(new DepositRateHelper(Handle<Quote>(cd.Mm2mRate), 2 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm3m(new DepositRateHelper(Handle<Quote>(cd.Mm3mRate), 3 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm4m(new DepositRateHelper(Handle<Quote>(cd.Mm2mRate), 4 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm5m(new DepositRateHelper(Handle<Quote>(cd.Mm5mRate), 5 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm6m(new DepositRateHelper(Handle<Quote>(cd.Mm6mRate), 6 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm9m(new DepositRateHelper(Handle<Quote>(cd.Mm9mRate), 9 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
	boost::shared_ptr<RateHelper> Mm12m(new DepositRateHelper(Handle<Quote>(cd.Mm12mRate), 12 * Months, fixingDays, calendar, ModifiedFollowing, true, depositDayCounter));
#pragma endregion 

	// calcul des ZC à partir des segments 

#pragma region SWAP RateHelper 
	Frequency swFixedLegFrequency = Annual;
	BusinessDayConvention swFixedLegConvention = ModifiedFollowing;
	DayCounter swFixedLegDayCounter = Actual360();

	
	boost::shared_ptr<IborIndex> swFloatingLegIndex(new Euribor6M);

	//boost::shared_ptr<IborIndex> swFloatingLegIndex(new USDLibor(6 * Months));

	boost::shared_ptr<RateHelper> s1y(new SwapRateHelper(Handle<Quote>(cd.s2yRate), 1 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s2y(new SwapRateHelper(Handle<Quote>(cd.s2yRate), 2 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s3y(new SwapRateHelper(Handle<Quote>(cd.s3yRate), 3 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s4y(new SwapRateHelper(Handle<Quote>(cd.s4yRate), 4 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s5y(new SwapRateHelper(Handle<Quote>(cd.s5yRate), 5 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s6y(new SwapRateHelper(Handle<Quote>(cd.s6yRate), 6 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s7y(new SwapRateHelper(Handle<Quote>(cd.s7yRate), 7 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s8y(new SwapRateHelper(Handle<Quote>(cd.s8yRate), 8 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s9y(new SwapRateHelper(Handle<Quote>(cd.s9yRate), 9 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s10y(new SwapRateHelper(Handle<Quote>(cd.s10yRate), 10 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s11y(new SwapRateHelper(Handle<Quote>(cd.s11yRate), 11 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s12y(new SwapRateHelper(Handle<Quote>(cd.s12yRate), 12 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s13y(new SwapRateHelper(Handle<Quote>(cd.s13yRate), 13 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s14y(new SwapRateHelper(Handle<Quote>(cd.s14yRate), 14 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s15y(new SwapRateHelper(Handle<Quote>(cd.s15yRate), 15 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s16y(new SwapRateHelper(Handle<Quote>(cd.s16yRate), 16 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s17y(new SwapRateHelper(Handle<Quote>(cd.s17yRate), 17 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s18y(new SwapRateHelper(Handle<Quote>(cd.s18yRate), 18 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s19y(new SwapRateHelper(Handle<Quote>(cd.s19yRate), 19 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s20y(new SwapRateHelper(Handle<Quote>(cd.s20yRate), 20 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s21y(new SwapRateHelper(Handle<Quote>(cd.s21yRate), 21 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s22y(new SwapRateHelper(Handle<Quote>(cd.s22yRate), 22 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s23y(new SwapRateHelper(Handle<Quote>(cd.s23yRate), 23 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s24y(new SwapRateHelper(Handle<Quote>(cd.s24yRate), 24 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s25y(new SwapRateHelper(Handle<Quote>(cd.s25yRate), 25 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s26y(new SwapRateHelper(Handle<Quote>(cd.s26yRate), 26 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s27y(new SwapRateHelper(Handle<Quote>(cd.s27yRate), 27 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s28y(new SwapRateHelper(Handle<Quote>(cd.s28yRate), 28 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s29y(new SwapRateHelper(Handle<Quote>(cd.s29yRate), 29 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s30y(new SwapRateHelper(Handle<Quote>(cd.s30yRate), 30 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s35y(new SwapRateHelper(Handle<Quote>(cd.s35yRate), 35 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s40y(new SwapRateHelper(Handle<Quote>(cd.s40yRate), 40 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s45y(new SwapRateHelper(Handle<Quote>(cd.s45yRate), 45 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));
	boost::shared_ptr<RateHelper> s50y(new SwapRateHelper(Handle<Quote>(cd.s50yRate), 50 * Years, calendar, swFixedLegFrequency, swFixedLegConvention, swFixedLegDayCounter, swFloatingLegIndex));

#pragma endregion 


	/*********************
	**  Construction de la courbe **
	*********************/

	DayCounter termStructureDayCounter = Actual360();

	double tolerance = 1.0e-15;

#pragma region Money Market-swap curve
	std::vector<boost::shared_ptr<RateHelper> > FowSwapInstruments;
	FowSwapInstruments.push_back(Mm1d);
	FowSwapInstruments.push_back(Mm1w);
	FowSwapInstruments.push_back(Mm2w);
	FowSwapInstruments.push_back(Mm3w);
	FowSwapInstruments.push_back(Mm1m);
	FowSwapInstruments.push_back(Mm2m);
	FowSwapInstruments.push_back(Mm3m);
	FowSwapInstruments.push_back(Mm4m);
	FowSwapInstruments.push_back(Mm5m);
	FowSwapInstruments.push_back(Mm6m);
	FowSwapInstruments.push_back(Mm9m);
	FowSwapInstruments.push_back(s1y);
	FowSwapInstruments.push_back(s2y);
	FowSwapInstruments.push_back(s3y);
	FowSwapInstruments.push_back(s4y);
	FowSwapInstruments.push_back(s5y);
	FowSwapInstruments.push_back(s6y);
	FowSwapInstruments.push_back(s7y);
	FowSwapInstruments.push_back(s8y);
	FowSwapInstruments.push_back(s9y);
	FowSwapInstruments.push_back(s10y);
	FowSwapInstruments.push_back(s11y);
	FowSwapInstruments.push_back(s12y);
	FowSwapInstruments.push_back(s13y);
	FowSwapInstruments.push_back(s14y);
	FowSwapInstruments.push_back(s15y);
	FowSwapInstruments.push_back(s16y);
	FowSwapInstruments.push_back(s17y);
	FowSwapInstruments.push_back(s18y);
	FowSwapInstruments.push_back(s19y);
	FowSwapInstruments.push_back(s20y);
	FowSwapInstruments.push_back(s21y);
	FowSwapInstruments.push_back(s22y);
	FowSwapInstruments.push_back(s23y);
	FowSwapInstruments.push_back(s24y);
	FowSwapInstruments.push_back(s25y);
	FowSwapInstruments.push_back(s26y);
	FowSwapInstruments.push_back(s27y);
	FowSwapInstruments.push_back(s28y);
	FowSwapInstruments.push_back(s29y);
	FowSwapInstruments.push_back(s30y);
	FowSwapInstruments.push_back(s35y);
	FowSwapInstruments.push_back(s40y);
	FowSwapInstruments.push_back(s45y);
	FowSwapInstruments.push_back(s50y);


#pragma endregion
#pragma region Vetor of Rates
	std::vector <Rate > zeroRates;

	zeroRates.push_back(Rate(0.001044304061632));
	zeroRates.push_back(Rate(0.001036411444725)); zeroRates.push_back(Rate(0.001097514041109)); zeroRates.push_back(Rate(0.001173869915892));
	zeroRates.push_back(Rate(0.001292780183302)); zeroRates.push_back(Rate(0.001780318494062)); zeroRates.push_back(Rate(0.002284042624282));
	zeroRates.push_back(Rate(0.002659528072845)); zeroRates.push_back(Rate(0.003073793698613)); zeroRates.push_back(Rate(0.003217936802338));
	zeroRates.push_back(Rate(0.003575922760749));
	zeroRates.push_back(Rate(0.004190597870754));

	zeroRates.push_back(Rate(0.004838330424187)); zeroRates.push_back(Rate(0.005496390482674)); zeroRates.push_back(Rate(0.006381249290812));
	zeroRates.push_back(Rate(0.007259221936245)); zeroRates.push_back(Rate(0.008413330681908)); zeroRates.push_back(Rate(0.009562765144778));
	zeroRates.push_back(Rate(0.010711073870503)); zeroRates.push_back(Rate(0.011864496357034)); zeroRates.push_back(Rate(0.012964859557097));
	zeroRates.push_back(Rate(0.014069516515937));


	zeroRates.push_back(Rate(0.015060298966915)); zeroRates.push_back(Rate(0.016050351165853)); zeroRates.push_back(Rate(0.016950605381909));
	zeroRates.push_back(Rate(0.017861147602038)); zeroRates.push_back(Rate(0.018685953861522)); zeroRates.push_back(Rate(0.019506834570624));
	zeroRates.push_back(Rate(0.02024849877879)); zeroRates.push_back(Rate(0.021001432039675)); zeroRates.push_back(Rate(0.021655722015577));
	zeroRates.push_back(Rate(0.022308290110151));

	zeroRates.push_back(Rate(0.022880755075041)); zeroRates.push_back(Rate(0.023451739223635)); zeroRates.push_back(Rate(0.023934985628471));
	zeroRates.push_back(Rate(0.02441688071633)); zeroRates.push_back(Rate(0.024819783290477)); zeroRates.push_back(Rate(0.025219741830058));
	zeroRates.push_back(Rate(0.025557733151653)); zeroRates.push_back(Rate(0.025892481047139)); zeroRates.push_back(Rate(0.0261471031915));
	zeroRates.push_back(Rate(0.026400346215793));

	zeroRates.push_back(Rate(0.026596530005922)); zeroRates.push_back(Rate(0.02679125737495)); zeroRates.push_back(Rate(0.026923141497885));
	zeroRates.push_back(Rate(0.027057783373626)); zeroRates.push_back(Rate(0.027158141072475)); zeroRates.push_back(Rate(0.027258043053644));
	zeroRates.push_back(Rate(0.027138485720258)); zeroRates.push_back(Rate(0.027017580047159)); zeroRates.push_back(Rate(0.027269449628008));
	zeroRates.push_back(Rate(0.027518323106016));


	zeroRates.push_back(Rate(0.027552034060602)); zeroRates.push_back(Rate(0.027587532348745)); zeroRates.push_back(Rate(0.027620922629304));
	zeroRates.push_back(Rate(0.027652495807764)); zeroRates.push_back(Rate(0.027666958232574)); zeroRates.push_back(Rate(0.027679569914392));
	zeroRates.push_back(Rate(0.027689019104131)); zeroRates.push_back(Rate(0.02769675981137)); zeroRates.push_back(Rate(0.027463580083745));
	zeroRates.push_back(Rate(0.027231064056942));

	zeroRates.push_back(Rate(0.027455310117238)); zeroRates.push_back(Rate(0.0276780615923)); zeroRates.push_back(Rate(0.027663238921094));
	zeroRates.push_back(Rate(0.027646537819583)); zeroRates.push_back(Rate(0.027641334458101)); zeroRates.push_back(Rate(0.027634287422));
	zeroRates.push_back(Rate(0.027385357640917)); zeroRates.push_back(Rate(0.027133904388202)); zeroRates.push_back(Rate(0.027177615335957));
	zeroRates.push_back(Rate(0.02721931955244));

	zeroRates.push_back(Rate(0.027264357380307)); zeroRates.push_back(Rate(0.027307432791037)); zeroRates.push_back(Rate(0.0273537645067));
	zeroRates.push_back(Rate(0.027398448684701)); zeroRates.push_back(Rate(0.02744381314619)); zeroRates.push_back(Rate(0.02748985152686));
	zeroRates.push_back(Rate(0.027538736493664)); zeroRates.push_back(Rate(0.027586070926443)); zeroRates.push_back(Rate(0.027609426442927));
	zeroRates.push_back(Rate(0.027631488207556));

	zeroRates.push_back(Rate(0.027655909359154)); zeroRates.push_back(Rate(0.027678641362502)); zeroRates.push_back(Rate(0.02770191900666));
	zeroRates.push_back(Rate(0.027725888028773)); zeroRates.push_back(Rate(0.027752362589697)); zeroRates.push_back(Rate(0.027777369314148));
	zeroRates.push_back(Rate(0.027804822403951)); zeroRates.push_back(Rate(0.027830844148083)); zeroRates.push_back(Rate(0.027852530884437));
	zeroRates.push_back(Rate(0.027872799638113));

	zeroRates.push_back(Rate(0.02789381765702)); zeroRates.push_back(Rate(0.02791491118744)); zeroRates.push_back(Rate(0.027938405923999));
	zeroRates.push_back(Rate(0.027960406566285)); zeroRates.push_back(Rate(0.027984766360857)); zeroRates.push_back(Rate(0.028007805048407));
	zeroRates.push_back(Rate(0.028033020685146)); zeroRates.push_back(Rate(0.028056946720676)); zeroRates.push_back(Rate(0.028086974890996));
	zeroRates.push_back(Rate(0.028117470889357));

	zeroRates.push_back(Rate(0.028150087220487)); zeroRates.push_back(Rate(0.028181877896732)); zeroRates.push_back(Rate(0.028215379826266));
	zeroRates.push_back(Rate(0.028247511044296)); zeroRates.push_back(Rate(0.02828189344652)); zeroRates.push_back(Rate(0.028314930948799));
	zeroRates.push_back(Rate(0.028348632844448)); zeroRates.push_back(Rate(0.02838280203569));

#pragma endregion
#pragma region Vetor of Dates
	std::vector <Date > dates;

	dates.push_back(Date(7, October, 2014));
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

	boost::shared_ptr<YieldTermStructure> FowSwapTermStructure(new PiecewiseYieldCurve<ZeroYield, Linear>(settlementDate, FowSwapInstruments, termStructureDayCounter, tolerance));

	boost::shared_ptr<YieldTermStructure> zeroStructure(new InterpolatedZeroCurve<Linear>(dates, zeroRates, ActualActual(), calendar, QuantLib::Linear()));

	FowSwapTermStructure->enableExtrapolation();
	return FowSwapTermStructure;


}

void PrintCurve2()
{
	std::cout << " -------------------------Courbe des taux -------------------------            |" << std::endl;
	std::cout << std::endl;

	std::cout << "Date              |" << "IDays          |" << "Zero Rate:        |" << "Discount Rate       |" << "Forward Rate   " << std::endl;

#pragma region Vetor of Dates
	std::vector <Date > dates;

	dates.push_back(Date(7, October, 2014));
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

	Date startDate(6, October, 2014);
	Date endD = Date(8, October, 2064);
	Calendar calendar = TARGET();

	CurveData2 cData;
	sampleMktData2(cData);

	boost::shared_ptr<YieldTermStructure>TestCurve = buildCurve2(cData);
	std::vector<float> mon_vecteur;
	BOOST_FOREACH(Date d, dates)
	{

		DayCounter dc = ActualActual();
		Integer fixing = 2;
		Date FixingDate = calendar.advance(d, -fixing, Days);
		Period P(Semiannual);
		Time Idays = daysBetween(startDate, d);
		Date d1 = d + 6 * Months;


		std::cout << io::short_date(d) << "            ";
		std::cout << Idays << "            ";
		std::cout << 100 * TestCurve->zeroRate(d, dc, Continuous).rate() << "            ";
		mon_vecteur.push_back(100 * TestCurve->zeroRate(d, dc, Continuous).rate());
		std::cout << TestCurve->discount(d) << "            ";
		if (endD > d1)
			std::cout << 100 * TestCurve->forwardRate(d, P, dc, Continuous, Semiannual).rate() << std::endl;
		else
			std::cout << std::endl;



	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	/*	std::cout << "***************Le vecteur des taux zeros coupons initial*****************" << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < mon_vecteur.size(); i++)
	{
	std::cout << mon_vecteur[i] << std::endl;
	}
	*/
}

std::vector<Rate> Calcul_Fwd(std::vector <Date > date2)
{

#pragma region Vetor of Dates
	std::vector <Date > dates;

	dates.push_back(Date(7, October, 2014));
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

	Date startDate(6, October, 2014);
	Date endD = Date(8, October, 2064);
	Calendar calendar = TARGET();
	CurveData2 cData;
	sampleMktData2(cData);


	boost::shared_ptr<YieldTermStructure> TestCurve = buildCurve2(cData);
	std::vector<Rate> mon_vecteur;



	BOOST_FOREACH(Date d, date2)
	{
		DayCounter dc = ActualActual();
		//Integer fixing = 2;
		//Date FixingDate = calendar.advance(d, -fixing, Days);
		Period P(Semiannual);
		//Time Idays = daysBetween(startDate, d);
		//Date d1 = d + 6 * Months;

		//mon_vecteur.push_back(100 * TestCurve->zeroRate(d, dc, Continuous).rate());
		mon_vecteur.push_back(100 * TestCurve->forwardRate(d, P, dc, Continuous, Semiannual).rate());


	}
	return mon_vecteur;
}

//void Test_Affichage()
//{
//	//std::cout << "***************Le vecteur des taux forward initial*****************" << std::endl;
//	std::vector<Rate> mon_vecteur = Calcul_Fwd();
//
//	std::cout << std::endl;
//	std::cout << std::endl;
//	std::cout << std::endl;
//	for (int i = 0; i < mon_vecteur.size(); i++)
//	{
//		std::cout << mon_vecteur[i] << std::endl;
//	}
//}
#endif