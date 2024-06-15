#ifndef LB
#define LB

#include "Request.h"
#include "Server.h"
#include <iostream>
#include <queue>

/// @brief Load Balancer manages the incoming requests in a Request Queue. During each clock cycle
/// assigns a request to a Server using Round Robin method.
class LoadBalancer
{
private:
    queue<Request> requestQueue; /*! stores requests before assigned to a server*/
    vector<Server> servers; /*! stores all the servers whether active or inactive*/

    int numServers; /*! stores num of servers */
    int time;   /*! stores amount of time/clock cycles the load balancer will run */
    int newId;  /*! stores the next unique ID for a request */

    /// @brief Generates a random Ip 
    /// @return XXX.XXX.XXX IP format
    string generate_IP();

public:
    /// @brief Default constructor
    LoadBalancer();
    /// @brief Initializes the Load Balancer, fills the request queue and initializes all the servers
    /// @param s number of servers the Loadbalancer can have
    /// @param t amount of clock cycles/time the load balancer will run
    LoadBalancer(int s, int t);
    /// @brief Deconstructor
    ~LoadBalancer();

    /// @brief Starts the LoadBalancer. Processes requests and keeps track of the clock cycles.
    void run();
};


#endif