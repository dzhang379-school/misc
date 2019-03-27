// Name: Davis Zhang
// Email: davis.zhang@vanderbilt.edu
// VUnetid: zhangd6
// Date: 12/07/2017
// Honor statement: I pledge my honor that I have neither given nor received unauthorized aid on this assignment.

#include <cstring>
#include <iostream>
#include <fstream>

/**
 * DEINE GLOBAL VARIABLES
 */

// Max signed int = 32767. It is possible that the fuel cost will exceed 32767 on trips of 100000 miles.
// Thus, we need a long int to cover that edge case.

long int windSpeed[10][1001];
long int memTable[10][1001];

int testCases, totalDist;

// Dynamic Top-down solution
long int fuel(int alt, int dist) {

    // check that we are in bounds
	if (dist > totalDist || alt < 0 || alt > 9) {
        return 1000000;
    // check that the destination is reachable
    } else if (alt > (totalDist - dist)) {
        return 1000000;
    }else if (dist == totalDist && alt == 0){
        return 0;
    // check if the fuel cost is already in the table
	} else if (memTable[alt][dist] != -1) {
        return memTable[alt][dist];
    // calculate the cheapest way to get to (alt, dist)
    } else {
        int minFuel = std::min(60 - windSpeed[alt][dist] + fuel(alt + 1, dist + 1),
                          std::min(30 - windSpeed[alt][dist] + fuel(alt, dist + 1),
                              20 - windSpeed[alt][dist] + fuel(alt - 1, dist + 1)));
        memTable[alt][dist] = minFuel;
        return minFuel;
    }
}

// initializes windSpeed with the contents of the file
// initializes memTable with values of -1
void initialize(std::ifstream &file){
    std::string line;
    getline(file, line);
    while (line.length() == 0){
        getline(file, line);
    }

    totalDist = std::stoi(line) / 100;

    memset(windSpeed, 0, sizeof(windSpeed));
    for (int j = 9; j >= 0; --j) {
        getline(file, line);
        int pos = 0;
        int ival = 0;
        for (int k = 0; k < totalDist; ++k){
            char val = line.at(pos);
            if (val == '-'){
                char val = line.at(++pos);
                ival = -(val - '0');

            } else {
                ival = val - '0';
            }
            windSpeed[j][k] = ival;
            pos += 2;
        }
    }

    memset(memTable, -1, sizeof(memTable));
}

int main(int argc, char *argv[]) {

    std::string fname, line;

    //takes a user-supplied input file.
    std::cout << "Please enter the file name: ";
    std::cin >> fname;
    std::ifstream file(fname.c_str());

    if (!file) {
        std::cout << "Invalid file name.";
        exit(1);
    }

    getline(file, line);
    testCases = std::stoi(line);

    for (int i = 0; i < testCases; ++i) {

        initialize(file);
        long int fuelCost = fuel(0, 0);
        std::cout << "\nTest Case " << i + 1 << std::endl;
        std::cout << "The minimum cost to reach the destination is: " << fuelCost << std::endl;
    }

	return 0;
}