#ifndef MAXSAT_H
#define MAXSAT_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class MaxSat {

public:
    // constructor/destructor
    MaxSat(vector< vector<int> > clauses, int individuals, double posRate, double negRate, double pM, double mutAmnt, int generations, int numVariables);
	MaxSat(vector< vector<int> > clauses, int individuals, string selection, string crossover, double pC, double pM, int generations, int numVariables);
    ~MaxSat();
    void initPV();
	void initPopulation();
    
    // fitness
    int countSatClauses(int* solution);
    void evalFitness();
    int findMaxFitness();
    int findMinFitness();
	
	// selection
	int** selectRanking();
	int** selectTournament();
	int** selectBoltzman();
	
	// crossover
	void onePCross(int** breedingPool);
	void uniformCross(int** breedingPool);
    
    // mutation
    void mutatePV();
	void mutateOffspring();
    
    // child selection
    void select(vector< vector<int> > clauses, int method, int individuals); // method is int rather than parsing char*
    
    // printing
    void printSolution(int* solution);
    void printPopulation();
    void printPV();
    void printClauses();
    
    void solvePBIL();
    void solveGA();

private:
    // class variables
    vector < vector<int> > clauses;
    vector<double> PV;
    int individuals;
    double posRate;
    double negRate;
	double pC;
    double pM;
    double mutAmnt;
	string selection;
	string crossover;
    int generations;
    int numVariables;
    int* fitnessList;
    int** population;

};


#endif
