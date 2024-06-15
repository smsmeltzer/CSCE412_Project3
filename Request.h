#ifndef REQUEST
#define REQUEST

using namespace std;
class Request
{
private:
    string ip_out;
    string ip_in;

public:
    int id;
    int time;

    Request();
    Request(int num, string ip_o, string ip_i, int t) {
        ip_out = ip_o;
        ip_in = ip_i;
        time = t; 
        id = num;

        cout << "Request #" << id << " created: " << ip_in << " to " << ip_out << " for " << time << " sec" << endl;
    };
    ~Request();

    string get_ip_out();
    string get_ip_in();
    int get_time();

    friend ostream& operator<<(ostream &os, const Request &obj) {
        os << "Request #" << obj.id;
        return os;
    }
};

Request::Request() : ip_out(""), ip_in(""), time(0)
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

#endif