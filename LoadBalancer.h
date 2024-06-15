#ifndef LB
#define LB

#include "Request.h"
#include "Server.h"
#include <iostream>
#include <queue>

class LoadBalancer
{
private:
    queue<Request> requestQueue;
    vector<Server> servers;

    string generate_IP();
    
    int numServers;
    int time;
    int newId;

public:
    LoadBalancer();
    LoadBalancer(int s, int t);
    ~LoadBalancer();

    void run();
};


#endif