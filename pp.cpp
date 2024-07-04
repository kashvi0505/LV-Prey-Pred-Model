
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

// Parameters
const double ALPHA = 0.1; // Prey growth rate
const double BETA = 0.02; // Predation rate
const double GAMMA = 0.3; // Predator death rate
const double DELTA = 0.02; // Predator growth rate

// Prey-Predator model using Euler's method for numerical integration
std::vector<std::pair<double, std::pair<double, double> > > preyPredatorModel(double preyInitial, double predatorInitial, double dt, double totalTime) {
    std::vector<std::pair<double, std::pair<double, double> > > result;

    double prey = preyInitial;
    double predator = predatorInitial;
    double time = 0.0;

    while (time <= totalTime) {
        double preyNext = prey + dt * (ALPHA * prey - BETA * prey * predator);
        double predatorNext = predator + dt * (-GAMMA * predator + DELTA * prey * predator);

        result.push_back(std::make_pair(time, std::make_pair(prey, predator)));

        prey = preyNext;
        predator = predatorNext;

        time += dt;
    }

    return result;
}

int main() {
    double preyInitial = 50.0; // Initial prey population
    double predatorInitial = 10.0; // Initial predator population
    double dt = 0.01; // Time step
    double totalTime = 100.0; // Total simulation time

    std::vector<std::pair<double, std::pair<double, double > > > simulationData = preyPredatorModel(preyInitial, predatorInitial, dt, totalTime);

    std::ofstream outFile("prey_predator_data.csv");
    outFile << "Time,Prey,Predator\n";
    for (auto dataPoint : simulationData) {
        outFile << dataPoint.first << "," << dataPoint.second.first << "," << dataPoint.second.second << "\n";
    }
    outFile.close();

    std::cout << "Simulation completed. Data saved to 'prey_predator_data.csv'\n";

    return 0;
}
