# Lotka-Volterra Prey-Predator Model

This repository implements a numerical simulation of a classic prey-predator population model using Euler's method for numerical integration.

### Functionality

* Models changes in prey and predator populations over time based on key parameters:
    * `ALPHA`: Prey growth rate (positive)
    * `BETA`: Predation rate (positive; impact of predators on prey)
    * `GAMMA`: Predator death rate (positive)
    * `DELTA`: Predator growth rate due to consuming prey (positive)
* Employs Euler's method for numerical integration to track population changes over discrete time steps.
* Generates time series data of prey and predator populations for the specified simulation duration.
* Saves simulation results in a comma-separated values (CSV) file named `prey_predator_data.csv` for easy import into spreadsheet software or analysis tools.

### Running the Simulation

1. **Compile the code:** Use a C++ compiler (e.g., `g++ prey_predator_model.cpp -o prey_predator_model`).
2. **Execute the program:** Run the compiled program (e.g., `./prey_predator_model`).
3. The simulation will run and save the results to `prey_predator_data.csv`.

### Customization

The code uses the following initial values (modify in `main` function):

* `preyInitial`: Initial prey population (50.0)
* `predatorInitial`: Initial predator population (10.0)
* `dt`: Time step (0.01)
* `totalTime`: Total simulation time (100.0)

Experiment with different values to explore various scenarios and population dynamics.

### Further Exploration

This code serves as a foundation for prey-predator model simulations. You can extend it by:

* Implementing more complex population dynamics equations.
* Introducing environmental factors influencing prey or predator populations.
* Visualizing simulation results using plotting libraries.

Feel free to modify and experiment with this code to gain insights into prey-predator population interactions!
