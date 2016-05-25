
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/schedule.hpp>
#include <ql/quantlib.hpp>


using namespace QuantLib;



class SwapFixedLeg
{
public:
	//SwapFixedLeg(Real FixedRate, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency);
	SwapFixedLeg(std::vector<std::tuple<Date, Date, Real>>  FixedRates, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency);

#pragma region"Get & Set Fonctions"
	//void setfixedRate(Real fixedRate);
	void setfixedRates(std::vector<std::tuple<Date, Date, Real>>  fixedRates);
	void setfixedLegDayCounter(DayCounter fixedLegDayCounter);
	void setfixedLegFrequency(Frequency fixedLegFrequency);
	//Real getfixedRate() const;
	std::vector<std::tuple<Date, Date, Real>> getfixedRates() const;
	DayCounter getfixedLegDayCounter() const;
	Frequency getfixedLegFrequency() const;
#pragma endregion 

	Schedule fixedSchedule(Date settlementDate, Date maturity) const;
	//Leg constructLeg(Date startDate, Date endDate, std::vector<double> nominals) const;
	//Leg constructLeg(Date startDate, Date endDate, double nominals) const;
	//std::vector<Real> fixedRatesFreq(std::vector<std::tuple<Date, Date, Real>> matrixRateDate, Date maturity, Date settlementDate, Frequency fixedLegFrequency)const;
	Leg SwapFixedLeg::constructLeg(Date settlementDate, Date maturity, std::vector<double> nominals) 
	{
		Schedule  schedule(settlementDate, maturity, Period(fixedLegFrequency),
			TARGET(), ModifiedFollowing, ModifiedFollowing,
			DateGeneration::Forward, false);
		return FixedRateLeg(schedule)
			.withNotionals(nominals)
			.withCouponRates(this->fixedRatesFreq(fixedRates, settlementDate, maturity, fixedLegFrequency), fixedLegDayCounter, Simple, fixedLegFrequency)
			.withPaymentAdjustment(ModifiedFollowing);
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



private:
	//Real fixedRate;

	std::vector<std::tuple<Date, Date, Real>> fixedRates;
	DayCounter fixedLegDayCounter;
	Frequency fixedLegFrequency;

};
