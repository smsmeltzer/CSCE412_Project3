#include <iostream>

#include "LoadBalancer.h"

using namespace std;

/// @brief Main function that initializes the Load Balancer
/// @param argc number of user inputs
/// @param argv user input
/// @return 
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./ <# of server> <time in seconds>" << endl;
        return -1;
    }

    freopen("log.txt", "w", stdout);

    int numServers = atoi(argv[1]);
    int time = atoi(argv[2]);

    LoadBalancer load_balancer(numServers, time);
    load_balancer.run();
    
    fclose(stdout);
    return 0;
};