#include "Request.h"

Request::Request() : ip_out(""), ip_in(""), time(0)
{
}

Request::Request(int num, string ip_o, string ip_i, int t) {
    ip_out = ip_o;
    ip_in = ip_i;
    time = t; 
    id = num;

    cout << "Request #" << id << " created: " << ip_in << " to " << ip_out << " for " << time << " sec" << endl;
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
