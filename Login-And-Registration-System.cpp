#include <iostream>   
#include <vector>     
#include <string>    
#include <fstream>    // for ifstream / ofstream (file reading & writing)
#include <limits>     // for numeric_limits, used to clear bad input
using namespace std;

// These two vectors act like an in-memory database of all users.
vector <string> usernames;
vector <string> passwords;

/*Reads any previously registered users from User.txt into the vectors
so the program remembers accounts from earlier runs.*/ 

void PreviousUsers(){
   string u, p;
   ifstream in("User.txt");     // open the file for reading

   // Each loop reads one "username password" pair from a line.
   // The loop stops automatically when there's nothing left to read.
   while(in>>u>>p){
    usernames.push_back(u);     
    passwords.push_back(p);    
   }

   in.close();                  // file closed
}

// Checks whether a given username is already taken.
bool usernameExist(string username){
   for(int i=0; i<usernames.size(); i++){   
    if(usernames[i]==username){
        return 1;   // match found -> username is taken
    }
   }
   return 0;        // no match -> username is unique
}

// Handles creating a new account.
bool Registration(){
   string username;
   string password;

    cout<<"ENTER USERNAME ";
    cin>>username;

    cout<<"ENTER PASSWORD ";
    cin>>password;

    // Reject registration if the username is already in use.
    if(usernameExist(username)){
        cout<<"USERNAME ALREADY EXIST, TRY ANOTHER ONE!"<<endl;
        return 0;
    }

    // Save the new user permanently to the file.
    // ios::app = append mode, so old users are NOT erased.
    ofstream out("User.txt", ios::app);
    out<<username<<" "<<password<<endl;   // endl puts each user on a new line
    out.close();

    // Also add the new user to the in-memory vectors,
    usernames.push_back(username);
    passwords.push_back(password);

    cout<<"REGISTRATION SUCCESSFUL!"<<endl;
    return 1;
}

// Handles logging in an existing user.
bool login(){
    string username;
    string password;

    cout<<"ENTER USERNAME ";
    cin>>username;

    cout<<"ENTER PASSWORD ";
    cin>>password;

    // Look through every stored user for a matching username AND password.
    for(int i=0; i<usernames.size(); i++){
        if(usernames[i]==username && passwords[i]==password){
            cout << "LOGIN SUCCESFULL!!" << endl;
            cout << "WELCOME" << endl;
            return 1;   // exact match found -> login succeeds
        }
    }

    // If the loop finishes without returning, no match was found.
    cout<<"INCORRECT USERNAME OR PASSWORD"<<endl;
    return 0;
}


int main(){
    PreviousUsers();   // load existing users from the file before the menu starts

    int choice;

    // do-while runs the menu at least once, and repeats until the user exits (choice == 3)
    do{
        cout<< "====LOGIN AND REGISTRATION SYSTEM===="<<endl;
        cout<<"1. REGISTER USER"<<endl;
        cout<<"2. LOGIN TO AN EXISTING ACCOUNT"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"ENTER CHOICE: ";
        cin>>choice;

        /*If the user typed something that isn't a number,
        cin>>choice fails and gets "stuck". This block fixes that:*/ 
        if(cin.fail()){
            cin.clear();     // remove the fail flag so cin can be used again
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // throw away the bad input left in the buffer
            cout<<"INVALID INPUT, PLEASE ENTER A NUMBER."<<endl;
            continue;        // go back to the menu
        }

        else if(choice==1){
            Registration();
        }
        else if(choice==2){
            login();
        }
        else if(choice==3){
            cout<<"EXITING..."<<endl;
        }
        else {
            // Choice was a valid number, but not 1, 2, or 3
            cout<<"INCORRECT CHOICE, TRY AGAIN!!"<<endl;
        }

    } while(choice!=3);   // keep looping until the user chooses to exit

    return 0;
}