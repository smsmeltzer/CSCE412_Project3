#ifndef SERVER
#define SERVER

#include "Request.h"
#include <queue>
#include <iostream>

using namespace std;

/// @brief Represents a Server taking in requests and fulfilling them 
class Server
{
private:
    queue<Request> requests;    /*! queue of requests assigned to the server to complete */
    int time = 0;

public:
    bool active;    /*! keeps track if the server is active, handling requests, or inactive, no requests assigned */
    int id; /*! unique ID of the server */

    /// @brief Default constructor
    Server();
    /// @brief Initializes a server 
    /// @param num assigns ID to the server
    Server(int num);
    /// @brief Deconstructor
    ~Server();
    
    /// @brief Adds a request to the server's request queue, if the server was inactive, sets to active
    /// @param r Request
    void add_request(Request r);

    /// @brief Runs the server for one clock cycle, keeps track of the request that is being handled and if it's finished
    // If the request queue is empty and all requests are finished, sets the server as inactive
    void run();

    /// @brief Operator overload of << to easily print the Server's ID in a specific format
    /// @param os 
    /// @param obj 
    /// @return formatted server ID
    friend ostream& operator<<(ostream &os, const Server &obj) { 
        os << "Server #" << obj.id;
        return os;
    }
};

#endif