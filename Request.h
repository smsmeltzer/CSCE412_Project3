
using namespace std;
class Request
{
private:
    string ip_out;
    string ip_in;
    int time;

public:
    int id;

    Request();
    Request(int num, string ip_o, string ip_i, int t) {
        ip_out = ip_o;
        ip_in = ip_i;
        time = t; 
        id = num;
    };
    ~Request();

    string get_ip_out();
    string get_ip_in();
    int get_time();
};

Request::Request()
{
}

Request::~Request()
{
}

string Request::get_ip_in() {
    return ip_in;
}

string Request::get_ip_out() {
    return ip_out;
}

int Request::get_time() {
    return time;
}
