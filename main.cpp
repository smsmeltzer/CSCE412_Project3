#include <iostream>

#include "LoadBalancer.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./ <# of server> <time in seconds>" << endl;
        return -1;
    }

    freopen("myfile.txt", "w", stdout);

    int numServers = atoi(argv[1]);
    int time = atoi(argv[2]);

    LoadBalancer load_balancer(numServers, time);
    load_balancer.run();
    
    fclose(stdout);
    return 0;
};