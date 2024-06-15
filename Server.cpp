#include "Server.h"

using namespace std;

Server::Server()
{
    active = false;
}

Server::Server(int num)
{
    active = false;
    id = num;
}

Server::~Server()
{
}

void Server::add_request(Request r) {
    if (!active) {
        active = true;
        cout << "Server #" << id << ": Turning on" << endl;
    }
    requests.push(r);
    cout << "Server #" << id << ": Recieved " << r << endl;
};

void Server::run() {
    if (active && !requests.empty()) {
        time++;
        if (time == requests.front().time) {  // request is complete
            cout << "Server #" << id << ": "<< requests.front() << " is finished" << endl;
            requests.pop();
            time = 0;

            if (requests.empty()) {
                active = false;
                cout << "Server #" << id << ": Turning off, all requests finished" << endl;
            }
        }
        
    }
}
