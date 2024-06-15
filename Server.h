#ifndef SERVER
#define SERVER

#include "Request.h"
#include <queue>
#include <iostream>

using namespace std;

class Server
{
private:
    queue<Request> requests;
    int time = 0;

public:
    bool active;
    int id;

    Server();
    Server(int num);
    ~Server();
    
    void add_request(Request r);

    void run(); // runs a server for one clock cycle

    friend ostream& operator<<(ostream &os, const Server &obj) { 
        os << "Server #" << obj.id;
        return os;
    }
};

#endif