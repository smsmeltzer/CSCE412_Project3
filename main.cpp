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

string generate_IP() {
    return to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + '.' 
        + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + '.' 
        + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./ <# of server> <time in seconds>" << endl;
        return -1;
    }

    int numServers = atoi(argv[1]);
    int time = atoi(argv[2]);
    int currTime = 0;
    queue<Request> requestQueue;
    LoadBalancer load_balancer(make_shared<queue<Request>>(requestQueue), numServers);

    // filling queue with requests
    for (int i = 0; i < numServers * 100; i++) {
        Request newRequest(i + 1, generate_IP(), generate_IP(), rand() % 10 + 1);
        requestQueue.push(newRequest);
    }

    // adding random requests while load balancer is running
    int i = 1;
    while (currTime < time) {
        int num = rand() % 10 + 1;  // get random number from 1 to 10
        sleep(num); // sleep for random # of seconds
        
        Request newRequest(i, generate_IP(), generate_IP(), rand() % 10 + 1);

        requestQueue.push(newRequest);

        cout << "New Request #" << newRequest.id << ": " << newRequest.get_ip_in() << " to " << newRequest.get_ip_out() 
                << " for " << newRequest.get_time() << " seconds." << endl;

        // run load balancer and servers for x amount of time

        i++;
        currTime += num;
    }

    return 0;
};