#ifndef GENETIC_CANDIDATE_HPP
#define GENETIC_CANDIDATE_HPP
#include <array>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "../Algorithm/FitnessCalc.hpp"

class Candidate {
    const int id;
    int fitness = 0; // works as a cache
    static int genesLength = 50;
    friend std::ostream & operator<<(std::ostream &os, const Candidate& candidate);
public:
    std::array<bool, genesLength> genesArray{};
    void generateGenes() {
        for(int i = 0; i < genesArray.size(); i++) {
            genesArray[i] = (rand() % 2 == 0);
        }
    }

    static void setGenesLength(int &length) {
        genesLength = length;
    }

    bool getGeneAtIndex(int &index) {
        return genesArray[index];
    }

    void setGeneAtIndex(int &index, const bool &value) {
        genesArray[index] = value;
        fitness = 0;
    }

    int size() {
        return genesArray.size();
    }

    int getId() {
        return id;
    }

    int getFitness() {
        if (fitness == 0) {
            FitnessCalc fitnessCalc;
            return fitnessCalc.getFitness(nullptr);
        }
        return fitness;
    }

    std::string const& to_string() const {
        std::stringstream gene_stream;
        gene_stream << "Gene " << id << ": ";
        std::string gene_data;
        for(int i = 0; i < genesArray.size(); i++) {
            gene_data += genesArray[i];
        }
        std::string gene_string = gene_stream.str();
        gene_string += gene_data;
        return gene_string;
    }
};

std::ostream & operator<<(std::ostream &os, const Candidate& candidate) {
    return os << candidate.to_string();
}

#endif //GENETIC_CANDIDATE_HPP
