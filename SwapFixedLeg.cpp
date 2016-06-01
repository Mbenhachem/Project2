
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include "SwapFixedLeg.h"
#include <ql/quantlib.hpp>
using namespace QuantLib;



SwapFixedLeg::SwapFixedLeg(std::vector<std::tuple<Date, Date, Real>>  FixedRates, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency)
: fixedRates(FixedRates), fixedLegDayCounter(FixedLegDayCounter), fixedLegFrequency(FixedLegFrequency)
{
}



#pragma region"Get&Set"
//void SwapFixedLeg::setfixedRate(Real fixedRate)
//{
//	this->fixedRate = fixedRate;
//}

void SwapFixedLeg::setfixedRates(std::vector<std::tuple<Date, Date, Real>>  fixedRates)
{
	this->fixedRates = fixedRates;
}

void SwapFixedLeg::setfixedLegDayCounter(DayCounter fixedLegDayCounter)
{
	this->fixedLegDayCounter = fixedLegDayCounter;
}

//double SwapFixedLeg::getfixedRate() const
//{
//	return this->fixedRate;
//}

std::vector<std::tuple<Date, Date, Real>> SwapFixedLeg::getfixedRates() const
{
	return this->fixedRates;
}

DayCounter SwapFixedLeg::getfixedLegDayCounter() const
{
	return this->fixedLegDayCounter;
}

Frequency SwapFixedLeg::getfixedLegFrequency() const
{
	return this->fixedLegFrequency;
}

void SwapFixedLeg::setfixedLegFrequency(Frequency fixedLegFrequency)
{
	this->fixedLegFrequency;
}
#pragma endregion


//Fonctions
Schedule SwapFixedLeg::fixedSchedule(Date settlementDate, Date maturity) const
{
	return Schedule(settlementDate, maturity, Period(fixedLegFrequency),
		TARGET(), ModifiedFollowing, ModifiedFollowing,
		DateGeneration::Forward, false);
}


