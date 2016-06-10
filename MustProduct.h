#pragma once
#include <ql/quantlib.hpp>
#include "SwapFixedLeg.h"
#include "SwapFloatingLeg.h"
#include "ComponentPrincipalMust.h"
#include "ComponentCashFlowMust.h"
#include"ComponentIndexMust.h"
#include"DateMust.h"
#include"RateMust.h"


using namespace QuantLib;


class MustProduct
{

public:
	MustProduct();

	virtual ~MustProduct()
	{
	}


	virtual void  SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure)=0;
	//Paramètres

	virtual double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName) = 0;
};

