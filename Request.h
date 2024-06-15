#ifndef REQUEST
#define REQUEST

#include <string>
#include <iostream>

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
    Request(int num, string ip_o, string ip_i, int t);
    ~Request();

    string get_ip_out();
    string get_ip_in();
    int get_time();

    friend ostream& operator<<(ostream &os, const Request &obj) {
        os << "Request #" << obj.id;
        return os;
    };
};


#endif