#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <exception>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Date {
public:
    int GetYear() const{
        return year;
    }
    int GetMonth() const{
        return month;
    }
    int GetDay() const{
        return day;
    }
    Date(const int& new_year, const int& new_month, const int& new_day){
        year = new_year;
        month = new_month;
        day = new_day;
    }
    Date():year(0),month(0),day(0){}
private:
    int year;
    int month;
    int day;
};

istream& operator>>(istream& input, Date& date){
    int new_year = 0;
    int new_month = 0;
    int new_day = 0;

    char sign1 = ' ';
    char sign2 = ' ';
    stringstream ss;
    string sscopy;
    input >> sscopy ;
    ss.str(sscopy);
    if(ss >> new_year && ss >> sign1 && ss >> new_month
                      && ss >> sign2 && ss >> new_day && (sign1 == '-' && sign2 == '-')){
        if (new_month < 1 || new_month > 12)
        {
            string exc = "Month value is invalid: " + to_string(new_month);
            throw domain_error(exc);
        }
        else if (new_day < 1 || new_day > 31)
        {
            string exc = "Day value is invalid: " + to_string(new_day);
            throw domain_error(exc);
        }else{
            Date temp(new_year,new_month,new_day);
            date = temp;
        }
    }else{
        string exc = "Wrong date format: " + sscopy;
        throw domain_error(exc);
    }



    return input;
}

ostream& operator<<(ostream& out, const Date& date){
    out << setfill('0');
    out << setw(4) << date.GetYear()  << "-"
        << setw(2) << date.GetMonth() << "-"
        << setw(2) << date.GetDay();
    return out;
}
bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetYear() < rhs.GetYear())
    {
        return true;
    }
    else if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() < rhs.GetMonth())
        {
            return true;
        }
        else if(lhs.GetMonth() == rhs.GetMonth()){
            if (lhs.GetDay() < rhs.GetDay())
            {
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

class Database {
public:
    void AddEvent(const Date& date, const string& event);//Done
    bool DeleteEvent(const Date& date, const string& event);//Done
    int  DeleteDate(const Date& date);//Done

    void Find(const Date& date) const;//done
    void Print() const;//Done

private:
    map<Date, set<string>> name;
};

void Database::AddEvent(const Date& date, const string& event){
    name[date].insert(event);
}
bool Database::DeleteEvent(const Date& date, const string& event){


    if(name.find(date) != name.end()){
        set<string> temp = name.at(date);
        if (temp.find(event) != temp.end()){
            temp.erase(event);
            name[date] = temp;
            cout << "Deleted successfully" << endl;
            return true;
        }
        else{
            cout << "Event not found" << endl;
            return false;
        }
    }
    else
    {
        cout << "Event not found" << endl;
        return false;
    }

}
int Database::DeleteDate(const Date& date){
    if(name.find(date) != name.end()){
        set<string> temp = name.at(date);
        int num_of_events = temp.size();
        cout << "Deleted "  << num_of_events << " events" << endl;
        name.erase(date);
        return num_of_events;
    }
    else
    {
        cout << "Deleted 0 events" << endl;
    }


}
void Database::Find(const Date& date) const{

    if(name.find(date) != name.end()){
        set<string> temp = name.at(date);
        int num_of_events = temp.size();
        if (num_of_events == 0)
        {
            cout << "Empty date" << endl;
        }

        else{
            for(auto& item : temp){
                cout << item << endl;
            }
        }
    }
    else
    {
        cout << "Empty date" << endl;
    }



}
void Database::Print() const{
    map<Date, set<string>> temp = name;
    // sort(temp.begin(),temp.end());?
    for(auto& item: temp){
        cout << item.first;
        for(auto& second_item : item.second){
            cout  << " " << second_item;
        }
        cout << endl;
    }
}


int main() {
  Database db;

  string command;
  try
  {
      while (getline(cin, command)) {
          stringstream ss(command);
          string com;
          ss >> com;
          if (com == "Add")
          {
              string event;
              Date temp;
              ss >> temp;
              if (ss >> event)
              {
                  db.AddEvent(temp,event);
              }
              else{
                  string exc = "Event value is invalid: " + event;
                  throw domain_error(exc);
              }

          }
          else if (com == "Del")
          {
              string event;
              Date temp;
              ss >> temp;
              if (ss >> event)
              {
                  db.DeleteEvent(temp,event);
              }
              else{
                  if(event == ""){
                      db.DeleteDate(temp);
                  }else{
                      string exc = "Event value is invalid: " + event;
                      throw domain_error(exc);
                  }
              }
          }
          else if (com == "Find")
          {
              Date temp;
              ss >> temp;
              db.Find(temp);
          }
          else if (com == "Print")
          {
             db.Print();
          }
          else
          {
          }

      }
  }
  catch (exception& exc)
  {
      cout << exc.what() << endl;
  }

  return 0;
}
