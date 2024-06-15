#include <iostream>
#include <queue>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <memory>
#include <vector>

#include "Server.h"
#include "Request.h"
#include "LoadBalancer.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./ <# of server> <time in seconds>" << endl;
        return -1;
    }

    int numServers = atoi(argv[1]);
    int time = atoi(argv[2]);

    LoadBalancer load_balancer(numServers, time);
    load_balancer.run();
    
    return 0;
};