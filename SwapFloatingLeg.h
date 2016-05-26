
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/schedule.hpp>
#include <ql/quantlib.hpp>


using namespace QuantLib;



class SwapFloatingLeg
{
public:
	SwapFloatingLeg(boost::shared_ptr<IborIndex> floating_index, DayCounter floatingLegDayCounter, Frequency floatingLegFrequency);
	/*SwapFloatingLeg(boost::shared_ptr<IborIndex> Floating_index, DayCounter FloatingLegDayCounter, Frequency FloatingLegFrequency, Spread Spread);
	SwapFloatingLeg(boost::shared_ptr<IborIndex> Floating_index, DayCounter FloatingLegDayCounter, Frequency FloatingLegFrequency, std::vector<Spread>  Spreads);
	*/
#pragma region"Get & Set Fonctions"
	void setfloating_index(boost::shared_ptr<IborIndex> floating_index);
	void setfloatingLegDayCounter(DayCounter floatingLegDayCounter);
	void setfloatingLegFrequency(Frequency floatingLegFrequency);

	boost::shared_ptr<IborIndex> getfloating_index() const;
	DayCounter getfloatingLegDayCounter() const;
	Frequency getfloatingLegFrequency() const;
#pragma endregion

	Schedule floatSchedule(Date settlementDate, Date maturity) const;

	Leg ConstructLeg(Date settlementDate, Date maturity, std::vector<double> nominals){
		Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
			TARGET(), ModifiedFollowing, ModifiedFollowing,
			DateGeneration::Forward, false);
		return IborLeg(schedule, floating_index)
			//.withNotionals(vectorAdaptFreq(nominals, settlementDate, maturity, floatingLegFrequency))
			.withNotionals(nominals)
			.withPaymentDayCounter(Actual360())
			.withPaymentAdjustment(ModifiedFollowing)
			.withFixingDays(2);

	}
	//Leg ConstructLeg(Date startDate, Date endDate, double nominals) const;
	Leg ConstructLeg(Date settlementDate, Date maturity, std::vector<double> nominals, std::vector<std::tuple<Date, Date, Real>>  Spreads){
		Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
			TARGET(), ModifiedFollowing, ModifiedFollowing,
			DateGeneration::Forward, false);

		return IborLeg(schedule, floating_index)
			//.withNotionals(vectorAdaptFreq(nominals, settlementDate, maturity, floatingLegFrequency))
			.withNotionals(nominals)
			.withPaymentDayCounter(floatingLegDayCounter)
			.withPaymentAdjustment(ModifiedFollowing)
			.withFixingDays(2)
			.withSpreads(vectorAdaptFreq(Spreads, settlementDate, maturity, floatingLegFrequency));
	}


	std::vector<Real> vectorAdaptFreq(std::vector<std::tuple<Date, Date, Real>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency)
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





	//Leg ConstructLeg(Date startDate, Date endDate, double nominals, std::vector<Spread>  Spreads) const;
	//Leg ConstructLeg(Date startDate, Date endDate, std::vector<double> nominals, Spread  Spread) const;
	//Leg ConstructLeg(Date startDate, Date endDate, double nominals, Spread  Spread) const;
	//Spread  spread;
	//std::vector<Spread>  spreads;
private:
	boost::shared_ptr<IborIndex> floating_index;
	DayCounter floatingLegDayCounter;
	Frequency floatingLegFrequency;

};
