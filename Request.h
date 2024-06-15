#ifndef REQUEST
#define REQUEST

#include <string>
#include <iostream>

using namespace std;

/// @brief Holds important data of each request
class Request
{
private:
    string ip_out;  /*! IP address the request came from */
    string ip_in;   /*! IP address the finished request should be sent */

public:
    int id; /*! Unique ID of the request */
    int time;   /*! Time it will take the request to be fulfilled */

    /// @brief Default constructor
    Request();
    /// @brief Initializes a request with the given parameters
    /// @param num Unique id
    /// @param ip_o out IP address
    /// @param ip_i in IP address
    /// @param t time to complete
    Request(int num, string ip_o, string ip_i, int t);
    /// @brief Deconstructor
    ~Request();

    /// @brief Overloaded Operator << to print request id 
    /// @param os 
    /// @param obj 
    /// @return formatted request ID
    friend ostream& operator<<(ostream &os, const Request &obj) {
        os << "Request #" << obj.id;
        return os;
    };
};


#endif