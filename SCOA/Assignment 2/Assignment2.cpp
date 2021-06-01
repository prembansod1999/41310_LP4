#include<bits/stdc++.h>
using namespace std;
class Individual {
    public:

    int fitness = 0;
    int genes[8];
    int geneLength = 8;

    Individual()
    {
    	for(int i = 0;i<geneLength;i++)
    	{
    		genes[i] = abs(rand())%2;
    	}
    	fitness = 0;
    }
    
    void printGenes()
    {
    	for(int i = 0;i<geneLength;i++)
    	{
    		cout<<genes[i];
    	}
    	cout<<'\n';
    }
    void calcFitness() {

        fitness = 0;
        for (int i = 0; i <geneLength; i++) {
            if (genes[i] == 1) {
                ++fitness;
            }
        }
    }
};
class Population {

    public:

    int popSize = 10;
    Individual individuals[10];
    int fittest = 0;

    Individual getFittest() 
    {
        int maxFit = INT_MIN;
        int maxFitIndex = 0;
        for (int i = 0; i < popSize; i++) {
            if (maxFit <= individuals[i].fitness) {
                maxFit = individuals[i].fitness;
                maxFitIndex = i;
            }
        }
        fittest = individuals[maxFitIndex].fitness;
        return individuals[maxFitIndex];
    }

    Individual getSecondFittest() 
    {
        int maxFit1 = 0;
        int maxFit2 = 0;
        for (int i = 0; i < popSize; i++) {
            if (individuals[i].fitness > individuals[maxFit1].fitness) {
                maxFit2 = maxFit1;
                maxFit1 = i;
            } else if (individuals[i].fitness > individuals[maxFit2].fitness) {
                maxFit2 = i;
            }
        }
        return individuals[maxFit2];
    }

    int getLeastFittestIndex() {
        int minFitVal = INT_MAX;
        int minFitIndex = 0;
        for (int i = 0; i < popSize; i++) {
            if (minFitVal >= individuals[i].fitness) {
                minFitVal = individuals[i].fitness;
                minFitIndex = i;
            }
        }
        return minFitIndex;
    }
    void calculateFitness() {

        for (int i = 0; i < popSize; i++) {
            individuals[i].calcFitness();
            cout<<"Genes "<<i<<":";
            individuals[i].printGenes();
        }
        getFittest();
    }

};
class GA 
{
    public:
    
    Population population;
    Individual fittest;
    Individual secondFittest;
    int generationCount = 0;

    void selection() {
        fittest = population.getFittest();
        secondFittest = population.getSecondFittest();
    }
    void crossover() {
        int crossOverPoint = abs(rand())%population.individuals[0].geneLength;
        for (int i = 0; i < crossOverPoint; i++) {
            int temp = fittest.genes[i];
            fittest.genes[i] = secondFittest.genes[i];
            secondFittest.genes[i] = temp;

        }

    }

    void mutation() {
        int mutationPoint = abs(rand())%population.individuals[0].geneLength;
        if (fittest.genes[mutationPoint] == 0) {
            fittest.genes[mutationPoint] = 1;
        } else {
            fittest.genes[mutationPoint] = 0;
        }

        mutationPoint = abs(rand())%population.individuals[0].geneLength;

        if (secondFittest.genes[mutationPoint] == 0) {
            secondFittest.genes[mutationPoint] = 1;
        } else {
            secondFittest.genes[mutationPoint] = 0;
        }
    }
    Individual getFittestOffspring() {
        if (fittest.fitness > secondFittest.fitness) {
            return fittest;
        }
        return secondFittest;
    }
    void addFittestOffspring() {
        fittest.calcFitness();
        secondFittest.calcFitness();
        int leastFittestIndex = population.getLeastFittestIndex();
        population.individuals[leastFittestIndex] = getFittestOffspring();
    }
};
int main()
{
        GA ga;

        ga.population.calculateFitness();

        cout<<"Generation: "<<ga.generationCount<<" Fittest: "<< ga.population.fittest<<"\n";

        while (ga.population.fittest < ga.population.individuals[0].geneLength) {
            ++ga.generationCount;

            ga.selection();

            ga.crossover();

            if (abs(rand())% ga.population.individuals[0].geneLength+2< ga.population.individuals[0].geneLength) {
                ga.mutation();
            }
            ga.addFittestOffspring();
            ga.population.calculateFitness();

            cout<<"Generation: "<<ga.generationCount<<" Fittest: "<< ga.population.fittest<<"\n";
        }

        cout<<"\nSolution found in generation: "<<ga.generationCount<<'\n';
        cout<<"Fitness: "<<ga.population.getFittest().fitness<<'\n';
        cout<<"Genes: ";
        for (int i = 0; i < ga.population.individuals[0].geneLength; i++) {
            cout<<ga.population.getFittest().genes[i];
        }
        cout<<"\n";
	return 0;
}
