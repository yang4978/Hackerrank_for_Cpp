//https://www.hackerrank.com/challenges/inherited-code/problem

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

// class BadLengthException{
//     private:
//         int n;
//     public:
//         BadLengthException(int num):n(num){};
//         const char* what() const throw(){
//             stringstream ss;
//             ss<<n;
//             return ss.str().c_str();
//         }
// };

class BadLengthException: public exception{
    private:
        char* msg;
    public:
        BadLengthException(int len){
            msg = new char[2];
            msg[0] = '0'+len;
            msg[1] = '\0';
        }
        virtual const char* what() const throw(){
            return msg;
        }
};



bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
