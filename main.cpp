#include <iostream>
#include <vector>

using namespace std;

void check_range (int start, int end, int value) {
  if(value < start || value > end){
    throw runtime_error ("VALUE IS INVALID");
  }
}

void check_vector (vector <string> vector1) {
  if(vector1.size () == 0){
    throw runtime_error ("NO EVENTS SCHEDULED");      

  }
}

int main () { 
  vector <string> vector1;

  while (true) {
    int question1;
    cout << "\n1) view all event\n2) add an event \n3) exit\n";
    cin >> question1;
    
    try { 
      check_range (1, 3, question1);
      
      if(question1 == 1){
        try{
          check_vector (vector1);
  
          cout << "\nhere are the events:\n";
          for(int i = 0; i < vector1.size(); i++){
            cout << vector1[i] << "\n";
          }  
        } catch (runtime_error e) {
          cout << e.what ( ) << "\n";
        }
      }
  
      if(question1 == 2){
        int day;
        cout << "what day do you wanna set ur event? ";
        cin >> day;
        
        try{
          check_range (1,31,day);
          
          int month;
          cout << "what month do you wanna set ur event? ";
          cin >> month;
  
          try{
            check_range (1,12,month);
  
            int year;
            cout << "what year do you wanna set ur event? ";
            cin >> year;
  
            try{
              check_range (2024,214748364,year);
  
              int hour;
              cout << "what hour do you wanna set ur event(mil time)? ";
              cin >> hour;
  
              try{
                check_range (0,23,hour);
  
                int minute;
                cout << "what minute do you wanna set ur event? ";
                cin >> minute;
  
                try{
                  check_range (0,59,minute);
  
                  string name;
                  cout << "what name do you wanna set ur event? ";
                  cin >> name;
  
                  string event = "event '" + name + "' is on " + to_string (year) + "-" + to_string (month) + "-" + to_string (day) + " at " + to_string (hour) + ":" + to_string (minute);
                  vector1.push_back(event);
                } catch (runtime_error e) {
                  cout << e.what ( ) << "\n";
                }
              } catch (runtime_error e) {
                cout << e.what ( ) << "\n";
              }
            } catch (runtime_error e) {
              cout << e.what ( ) << "\n";
            }
          } catch (runtime_error e) {
            cout << e.what ( ) << "\n";
          }
        } catch (runtime_error e) {
          cout << e.what ( ) << "\n";
        }
      }
  
      if(question1 == 3){
        break;
      }
    } catch (runtime_error e) {
      cout << e.what ( ) << "\n";
    }
  }
}
