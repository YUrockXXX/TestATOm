#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <system_error>

using namespace std;

string AskTimeServer() {

}

class TimeServer {
public:
    string GetCurrentTime() {
        try
        {
            std::string temp = AskTimeServer();
            last_fetched_time = temp;
        }
        catch (system_error& exc)
        {
            cout << exc.what() << endl;
        }
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
