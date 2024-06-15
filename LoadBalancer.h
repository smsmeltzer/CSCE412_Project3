#ifndef LB
#define LB
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
    LoadBalancer(/* args */);
    LoadBalancer(int s, int t);
    ~LoadBalancer();

    void run();
};

LoadBalancer::LoadBalancer() : numServers(0), time(0), newId(0)
{
}

LoadBalancer::LoadBalancer(int s, int t) {
    numServers = s;
    time = t;

    cout << "Generating initial requests: " << endl;
    int numId = 0;
    // filling queue with requests
    for (int i = 0; i < numServers; i++) {
        Request newRequest(numId, generate_IP(), generate_IP(), rand() % 10 + 5);
        requestQueue.push(newRequest);

        numId++;
    }
    newId = numId;
    cout << endl;

    // initializing servers
    for(int i = 0; i < s; i++) {
        servers.push_back(Server(i));
    }
}

LoadBalancer::~LoadBalancer()
{
}

void LoadBalancer::run() {
    int currServer = 0;
    int currTime = 0;

    int randNum = rand() % 10;
    while (currTime < time) {
        cout << "Elapsed Time: " << currTime << endl;
        // Check queue for request
        if (!requestQueue.empty()) {
            cout << "Sending request #" << requestQueue.front().id << " to Server #" << servers.at(currServer).id << endl;
            servers.at(currServer).add_request(requestQueue.front());
            requestQueue.pop();
            currServer = (currServer + 1) % numServers;
        }
        else {
            cout << "Request Queue empty..." << endl;
        }

        // run each server for one clock cycle
        for (int i = 0; i < numServers; i++) {
            servers.at(i).run();
        }

        if (randNum == 0) {
            requestQueue.push(Request(newId, generate_IP(), generate_IP(), rand() % 10 + 5));
            newId++;
            randNum = rand() % 10;
        }
        else {
            randNum--;
        }


        currTime++;
        cout << endl;
    }
}


string LoadBalancer::generate_IP() {
    return to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + '.' 
        + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + '.' 
        + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
}

#endif