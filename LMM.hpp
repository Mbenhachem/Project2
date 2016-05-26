#ifndef LMM_H
#define LMM_H

#include <boost/format.hpp>
#include <conio.h> 
#include <stdio.h> 
#include <math.h> 
#include <iostream> 
#include <ql/quantlib.hpp>
#include <ql/math/matrix.hpp>
#include <random>
#include <cmath>


using namespace QuantLib;
/*Fonction qui donne la matrice des taux forwards(tspot=tauxZC initiaux,
delta= écart entre 2 maturités successives,
v=liste des matrices de vol)*/

struct LMM{
public:


	std::vector<Rate> Frate(std::vector<Rate> zeroRates, std::vector<Date> dates);//Calcul des taux forward initiaux à partir des taux zeros coupons entrée à la main
	std::vector<float> volForward(std::vector<float> volBlack, std::vector<Date> dates);//Génerer le vecteur de la volatilité forward pour creer la matrice
	Matrix mat(const std::vector<float>& volF);//Génerer la matrice de volatilité cas de constante par morceaux
	Matrix matRebonato(float a, float b, float c, float d, std::vector<Date> dates);//Génerer la matrice de volatilité cas de Rebonato

	std::vector<float> drift(std::vector<Rate> &forwardRate, Matrix volMat, std::vector<Date> &dates, int indicetemps); //Calculer le drift du LMM
	double normaldistribution();
	
	Matrix matforwardLMM(std::vector<Rate> &forwardRate, Matrix volMat, std::vector<Date> &dates);//Génerer la matrice des taux forwards 
};

std::vector<Rate> Frate(std::vector<Rate> zeroRates, std::vector<Date> dates)
{


	int n = zeroRates.size();
	
	int i = 0;
	std::vector<Time> D(n);
	std::vector<Rate> F(n);
	
	

	F[0] = zeroRates[1];// il faut s'arranger sur une convention 
	for (i = 1; i < n; i++){
		
		D[i] = daysBetween(Date(6, October, 2014), dates[i])/360 ;

		//std::cout << "Temps :"<<D[i] << std::endl;
		//F[i] = (exp(zeroRates[i + 1] * D[i + 1] - zeroRates[i] * D[i]) - 1) / (D[i + 1] - D[i]);

		  F[i] = (zeroRates[i ] * D[i ] - zeroRates[i-1] * D[i-1]) / (D[i ] - D[i-1]);

	}


	return F;
}

float somme(std::vector<float> V, int initial, int fin){

	float R = 0.00;

	for (int i = initial; i < fin-1 ; i++){

		R = R + V[i]*V[i];

	}

	return R;
}


//volatilité constante par morceaux 
std::vector<float> volForward(std::vector<float> volBlack, std::vector<Date> dates){

	int n = volBlack.size();
	int i = 0;
	std::vector<float> sigma(n);
	std::vector<Time> D(n);
	std::vector<Time> delta(n);

	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
	}

	for (int j = 0; j < n - 1; j++){
		delta[j] = D[j + 1] - D[j];
	}
	delta[n - 1] = delta[n - 2];
	


	
	for (i = 0; i < n-1; i++){
		//std::cout << (((volBlack[i] * D[i]) / (delta[i])) - somme(volBlack, 1, i)) << std::endl;

		if ((((volBlack[i] * D[i]) / (delta[i])) - somme(volBlack, 1, i))>0)
			sigma[i] = sqrt(((volBlack[i] * D[i]) / (delta[i])) - somme(volBlack, 1, i));
		else  sigma[i] = 0;

	}

		return sigma;
	
}

Matrix mat(const std::vector<float>& volF){

	int n = volF.size();
	Matrix M(n, n);
	
	int i = 0;
	int j = 0;

	for (j = 0; j < n; j++){

		for (i = 0; i < j; i++){
			M[i][j] = 0;
		}
		for (i = j; i < n; i++){
			M[i][j] = volF[i-j];
		}
	}
				return M ;
}
float sommedrift(std::vector<Rate> &forwardRate,Matrix &volMat ,std::vector<Date> &dates,int initial,int final ,int indice){

	float R = 0;
	int n = forwardRate.size();
	std::vector<Time> D(n);
	int i = 0;
	std::vector<float> delta(n);
	Matrix matforwardR(n, n);
	//Remarque : indice =0 car on connait les forwards rates à l'instant initial t=0 seulement 

	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
	}

	for (int j = 0; j < n - 1; j++){
		delta[j] = D[j + 1] - D[j];
	}
	delta[n - 1] = delta[n - 2];


	for (i = initial; i < final; i++){
		
		matforwardR[i][indice] = forwardRate[i];
		R = R + ((delta[i] * matforwardR[i][indice] * volMat[i][indice]) / (1 + delta[i] * forwardRate[i]));
	}

	return R;
}

//Calcul de drift
std::vector<float> drift(std::vector<Rate> &forwardRate, Matrix &volMat, std::vector<Date> &dates,int indicetemps){

	int n = forwardRate.size();
	Matrix M(n,n);
	std::vector<float> R(n);
	int i= 0;
	int k = 0;
	for (i = 0; i < n; i++){
		M[i][indicetemps] = volMat[i][indicetemps] * sommedrift(forwardRate, volMat, dates, k, i, indicetemps);
		k = indicetemps + 1;

		R[i] = M[i][indicetemps];
	}
	
	return R;
}

std::vector<float> Rebonato(float a, float b, float c, float d, std::vector<Date> &dates, float t){
	int n = dates.size();
	std::vector<float> sigma(n);
	int i = 0;
	std::vector<Time> D(n);
	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
	}
	//sigma[0] = c;
	for (i = 0; i < n; i++){

		sigma[i] = (a*(D[i] - t) + d) * exp(-b*(D[i] - t)) + c;
	}


	return sigma;
}

Matrix matRebonato(float a, float b, float c, float d, std::vector<Date> &dates){
	int n = dates.size();
	Matrix M(n, n);

	int i = 0;
	int j = 0;
	std::vector<Time> D(n);
	std::vector<float> sigma(n);
	float t = 0;
	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
	}

	for (j = 0; j < n; j++){

		for (i = 0; i < j; i++){
			M[i][j] = 0;
		}
		for (i = j; i < n; i++){
			t = D[j];
			sigma = Rebonato(a, b, c, d, dates, t);

			M[i][j] = sigma[i];
		}
	}
	return M;
}

//////////////////////////////////////////////////
double randomUniform()
{
	return rand() / (double)RAND_MAX;

}

double randomUniform2(double a, double b)
{
	return (b - a)*randomUniform() + a;
}


double randomloinormal(){
	double x1 = randomUniform2(0, 1);
	double x2 = randomUniform2(0, 1);
	double Pi = 3.14159265358979323846;

	double x;
	x = std::cos(2 * Pi*x1)*std::sqrt(-2 * std::log10(x2));
	return x;
}
double NormalDistributionlmm(double mu, double sigma)
{


	return (mu + sigma*randomloinormal());

}
//calcul de la matrice des taux forward 
Matrix matforwardLMM(std::vector<Rate> &forwardRate, Matrix &volMat, std::vector<Date> &dates){

	int n = forwardRate.size();
	Matrix matF(n, n);
	std::vector<float> mu(n);
	std::vector<float> muvec(n);
	std::vector<float> volMatvec(n);
	std::vector<float> volMatvec2(n);
	std::vector<float> MU(n);
	std::vector<float> MU2(n);
	std::vector<float> MU3(n);
	std::vector<Rate> FR(n);
	std::vector<Time> D(n);
	std::vector<float> delta(n);
	//float z = 0.7;
	
	std::vector<float> z(n);

	for (int i = 0; i < n; i++){
		z[i] = randomloinormal();
	}


	int j = 0;
	int i = 0;
	
	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
		//std::cout << "d" << i << "" << D[i] << std::endl;
	}
	for (j = 0; j < n - 1; j++){
		delta[j] = D[j + 1] - D[j];
		//std::cout << "delta " << delta[j] << std::endl;
	}
	delta[n - 1] = delta[n - 2];
	//std::cout << delta[n - 1] << std::endl;
	

	FR = forwardRate;


	for ( i = 0; i < n ;i++){

		for (j = 0; j < i; j++){
			matF[j][i] = 0;
		}

		for (j = i; j < n; j++){
		

		mu = drift(FR, volMat, dates,i);
		muvec[j] = mu[j] * D[i];

		volMatvec[j] = volMat[j][i];
		volMatvec2[j] = (volMatvec[j] * volMatvec[j])/2;
		
		MU[j] = (muvec[j] - volMatvec2[j] )* delta[i];
		MU2[j] = std::sqrt(delta[i])*volMatvec[j] * z[i];
		MU3[j] = exp(MU[j] + MU2[j]);

		FR[j] = FR[j]*MU3[j];//L'equation du LMM

		matF[j][i] = FR[j];


	}
	}
	

	return matF;

}

Matrix matForwardmontecarlo(std::vector<Rate> &forwardRate, Matrix &volMat, std::vector<Date> &dates,int nbsimulation){
	
	int n = forwardRate.size();
	
	Matrix M(n,n);
	Matrix S(n,n);
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			S[i][j] = 0;
		}
	}

	
	for (int i = 0; i < nbsimulation; i++){

		
		M = matforwardLMM(forwardRate, volMat, dates);
		S = S+ M;
	}

	S = S / nbsimulation;

	return S;
}


Matrix PrixZCForward(Matrix &matForward, std::vector<Date> &dates){
	int n = dates.size();
	std::vector<Time> delta(n);
	std::vector<Time> D(n);
	Matrix ZC(n, n);
	int i ,j;
	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;

	}
	for (int j = 0; j < n - 1; j++){
		delta[j] = D[j + 1] - D[j];
	}
	delta[n - 1] = delta[n - 2];



	for (j = 0; j < n; j++){
		for (i = 0; i < j; i++){
			ZC[i][j] = 0;
		}

		for (i = j; i < n; i++){
			
			ZC[i][j] = 1/ float (1+ delta[j] * matForward[i][j]);

		}
	}

	return ZC;
}



	float Relationindirectsup(int indice, Matrix &ZC, int strikeindice, float strikeprice, int fin){
		//Calcul du prix relatif à partir du prix strike du cap (cas superieur) ;
		float Prelatif=0;
		float produitzerocoupon = 1;

		for (int i = strikeindice; i < fin + 1; i++){

			produitzerocoupon = produitzerocoupon*ZC[i][i];

		}

	Prelatif =float (strikeprice / produitzerocoupon);

	return Prelatif;
}


	
	float Relationindirectinf(int indice, Matrix &ZC, int strikeindice, float strikeprice, int fin){
		//Calcul du prix relatif à partir du prix strike du cap (cas inferieur)
		float Prelatifinf=0;
		float produitzerocoupon = 1 / ZC[fin][indice];

		for (int i = indice; i < strikeindice + 1; i++){
			produitzerocoupon = produitzerocoupon*(float)ZC[i][i] ;
		}

		Prelatifinf = float(strikeprice * produitzerocoupon);

		return Prelatifinf;
	}


	float calculprixrelatifmaturity(int indice, Matrix &ZC, int strikeindice, float strikeprice, int fin,std::vector<Time> &delta){
		float Prelatif=0;
		float produitzerocoupon = 1 / ZC[strikeindice][strikeindice];

		for (int i = indice; i < fin; i++){
			produitzerocoupon = produitzerocoupon*(float)(1 + delta[i+1] * ZC[i + 1][i + 1]) ;
		}

		Prelatif = float(strikeprice * produitzerocoupon);

		return Prelatif;
	}

float CalculPrixRelatifCap(float strike ,Matrix &matForward,std::vector<Date> &dates,Date debut,Date fin,Date datedecalcul){
	int n = dates.size();
	std::vector<Time> D(n);
	float ret = 0;
	std::vector<Time> delta(n);
	int i = 0;
	int j=0;
	int initial=0;
	int finale=0;
	int M = 0;
	int datecalcul = 0;
	float strikeprice = 0;
	
	float prixducap=0;
	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
	}

	for (int j = 0; j < n - 1; j++){
		delta[j] = D[j + 1] - D[j];
	}
	delta[n - 1] = delta[n - 2];

	for (i = 0; i < n; i++){

		if (dates[i] == debut) {
			initial = i;
			//std::cout <<"la valeur initial"<< initial << std::endl;
		}
	
		if (dates[i] == fin) {
		   finale = i;
		   //std::cout << "la valeur final "<<finale << std::endl;
		}

		if (dates[i] == datedecalcul){

		  datecalcul = i;
		  //std::cout << "la valeur du debut"<<datecalcul << std::endl;
		}
	}

	Matrix ZC = PrixZCForward(matForward, dates);

	M = finale - initial + 2;
	std::vector<float> price(M);
	std::vector<float> pricefinal(M);

	for (i = initial ; i<finale+1; i++){
		
		if (matForward[i][i]>strike) {
			//std::cout << "le taux superieur au strike :" << matForward[i][i] << std::endl;
			strikeprice = float((matForward[i][i] - strike)*delta[i] * ZC[i][i]);//la relation des caplets
			for (j = initial; j < i; j++){
				price[j] = Relationindirectinf(j, ZC, i, strikeprice, finale);
				
			}

			price[i] = strikeprice / ZC[finale][i];

			for (j = i + 1; j < finale; j++){
				price[j] = Relationindirectsup(j, ZC, i, strikeprice, finale);
			}

			price[finale] = calculprixrelatifmaturity(j, ZC, i, strikeprice, finale, delta);

			for (j = initial; j < finale+1 ; j++){
				prixducap = prixducap + price[j];
			}

			prixducap = prixducap*ZC[finale][datecalcul] / M;
			pricefinal[i] = prixducap;
			//std::cout << "Prix du caplet à l'instant T" <<i<<":"<< pricefinal[i] << std::endl;

		}
		else { 
			pricefinal[i] = 0; 
			//std::cout << "Prix du caplet à l'instant T" << i << ":" << pricefinal[i] << std::endl;

		}
	}

	for (i = initial; i < finale+1 ; i++){
		ret = ret + pricefinal[i];
	}

 return ret;
}


float PricingsimulationCap(std::vector<Rate> &forwardRate, Matrix &volMat,float strike, std::vector<Date> &dates, Date debut, Date fin, Date datedecalcul, int nbdesimulation){


	Matrix M;
	float price;
	float pricefinal = 0.0;

	for (int i =0; i < nbdesimulation; i++){

	Matrix matForward = matforwardLMM(forwardRate,volMat,dates);
	price = CalculPrixRelatifCap(strike, matForward, dates, debut, fin, datedecalcul);
	pricefinal = pricefinal + price / nbdesimulation;

	}


	return pricefinal;
}

float calculdeA(int indicetemps, int S, int N, Matrix matForward,std::vector<Date> dates){

	Matrix ZC = PrixZCForward(matForward,dates);
	int n = dates.size();
	std::vector<Time> D(n);
	std::vector<Time> delta(n);
	int i = 0;
	int j = 0;
	float A = 0;
	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
	}
	for ( j = 0; j < n - 1; j++){
		delta[j] = D[j + 1] - D[j];
	}
	delta[n - 1] = delta[n - 2];

	for (i = S+1; i < N+1; i++){
		A = A +float (delta[i] * ZC[i][indicetemps]);
	}


	return A;

}
float SR(int indicetemps, int S, int N, Matrix matForward, std::vector<Date> dates){


	Matrix ZC = PrixZCForward(matForward, dates);
	float SR = 0;

	float A = calculdeA(indicetemps,S, N, matForward, dates);

	SR = (ZC[S][indicetemps] - ZC[N][indicetemps]) / A;


	return SR;
}



float CalculPrixRelatifSwaptionEuroPayeuse(float strike, Matrix &matForward, std::vector<Date> &dates, Date debut, Date fin, Date datedecalcul){
	int n = dates.size();
	std::vector<Time> D(n);
	float ret = 0;
	std::vector<Time> delta(n);
	int i = 0;
	int j = 0;
	int initial = 0;
	int finale = 0;
	int M = 0;
	int datecalcul = 0;
	float strikeprice = 0;

	float prixswaption = 0;
	for (i = 0; i < n; i++){
		D[i] = daysBetween(Date(6, October, 2014), dates[i]) / 360;
	}

	for (int j = 0; j < n - 1; j++){
		delta[j] = D[j + 1] - D[j];
	}
	delta[n - 1] = delta[n - 2];

	for (i = 0; i < n; i++){

		if (dates[i] == debut) {
			initial = i;
			//std::cout <<"la valeur initial"<< initial << std::endl;
		}

		if (dates[i] == fin) {
			finale = i;
			//std::cout << "la valeur final "<<finale << std::endl;
		}

		if (dates[i] == datedecalcul){

			datecalcul = i;
			//std::cout << "la valeur du debut"<<datecalcul << std::endl;
		}
	}

	Matrix ZC = PrixZCForward(matForward, dates);

	M = finale - initial + 2;
	std::vector<float> price(100);
	std::vector<float> pricefinal(100);

	for (i = initial; i<finale + 1; i++){
		std::cout << "swaprate" << SR(initial, initial, finale, matForward, dates) << std::endl;

		if (SR(initial, initial, finale, matForward, dates) > strike) {

			std::cout << "sup au strik" <<SR(initial, initial, finale, matForward, dates) << std::endl;
			strikeprice = float((ZC[datecalcul][initial] * calculdeA(initial, initial, finale, matForward, dates)*(SR(initial, initial, finale, matForward, dates)) - strike));//la relation de swaptions euro payeuse
			for (j = initial; j < i; j++){
				price[j] = Relationindirectinf(j, ZC, i, strikeprice, finale);

			}

			price[i] = strikeprice / ZC[finale][i];

			for (j = i + 1; j < finale; j++){
				price[j] = Relationindirectsup(j, ZC, i, strikeprice, finale);
			}

			price[finale] = calculprixrelatifmaturity(j, ZC, i, strikeprice, finale, delta);

			for (j = initial; j < finale + 1; j++){
				prixswaption = prixswaption + price[j];
			}

			prixswaption = prixswaption*calculdeA(datecalcul, initial, finale, matForward, dates) / M;
			pricefinal[i] = prixswaption;
			

		}
		else {
			pricefinal[i] = 0;
			
		}
	}

	for (i = initial; i < finale + 1; i++){
		ret = ret + pricefinal[i];
	}

	return ret;
}


float PricingsimulationSwaptionPayeuse(std::vector<Rate> &forwardRate, Matrix &volMat, float strike, std::vector<Date> &dates, Date debut, Date fin, Date datedecalcul, int nbdesimulation){


	Matrix M;
	float price;
	float pricefinal = 0;

	for (int i = 0; i < nbdesimulation; i++){

		Matrix matForward = matforwardLMM(forwardRate, volMat, dates);
		price = CalculPrixRelatifSwaptionEuroPayeuse(strike, matForward, dates, debut, fin, datedecalcul);
		pricefinal = pricefinal + price;

	}
	pricefinal = pricefinal / nbdesimulation;

	return pricefinal;
}


std::vector <Date > vectorDates(Date startDate, Date endDate, Frequency frequency){
	std::vector <Date > result;
	int i = 0;
	Date starDatetemp = startDate;
	result.push_back(starDatetemp);
	while (result[i] < endDate){
		i++;
		starDatetemp.operator+=(Period(frequency));
		result.push_back(starDatetemp);
	}
	

	return result;
}

#endif