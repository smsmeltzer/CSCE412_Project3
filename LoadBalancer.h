using namespace  std;
class LoadBalancer
{
private:
    shared_ptr<queue<Request>> requestQueue;
    vector<Server> servers;

    int numServers;

public:
    LoadBalancer(/* args */);
    LoadBalancer(shared_ptr<queue<Request>> rq, int s);
    ~LoadBalancer();

    void run(int time);
};

LoadBalancer::LoadBalancer(/* args */)
{
    requestQueue = nullptr;
}

LoadBalancer::LoadBalancer(shared_ptr<queue<Request>> rq, int s) {
    requestQueue = rq;
    numServers = s;
}

LoadBalancer::~LoadBalancer()
{
}

void LoadBalancer::run(int time) {
    // for each server
    // call run on them to run x amount of time

    // do load balancing stuff
}
