#ifndef GENETIC_POPULATION_HPP
#define GENETIC_POPULATION_HPP

#include "../Candidate/Candidate.hpp"
#include <vector>
#include <iterator>
class Population {
    std::vector<Candidate*> candidates{};
    int populationSize;
public:
    Population(int populationSize_, bool init) : populationSize(populationSize_) {
        if(init) {
            for (int i = 0; i < populationSize; i++) {
                Candidate *newCandidate = new Candidate();
                newCandidate->generateGenes();
                candidates.push_back(newCandidate);
            }
        }
    }

    Candidate *getCandidate(int index) {
        return candidates[index];
    }

    Candidate *getCandidate(std::vector<Candidate*>::iterator it) {
        return *it;
    }

//    Candidate getFittest() {
//        Candidate *fittest = candidates.front();
//
//        for(std::vector<Candidate*>::iterator it = candidates.begin(); it != candidates.end(); ++it) {
//            if(fittest->getFitness() <= getCandidate(it)->getFitness()) {
//                fittest = getCandidate(it);
//            }
//        }
//        return *fittest;
//    }

    Candidate getFittest() {
        Candidate *fittest = candidates.front();

        for(int i = 0; i < size(); i++) {
            if(fittest->getFitness() <= getCandidate(i)->getFitness()) {
                fittest = getCandidate(i);
            }
        }
        return *fittest;
    }

    int size() {
        return candidates.size();
    }

    void saveCandidateAtIndex(int index, Candidate *candidate) {
        candidates[index] = candidate;
    }

};


#endif //GENETIC_POPULATION_HPP
