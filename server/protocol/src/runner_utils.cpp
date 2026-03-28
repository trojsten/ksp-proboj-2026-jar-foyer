#include "runner_utils.h"
#include <iostream>

using namespace std;
using namespace runner;

stringstream runner::read(Status &s){
    string status;
    getline(cin, status);
    if(status == "OK"){
        s = Status::Ok;
    }else if(status == "DIED"){
        s = Status::Died;
    }else{
        s = Status::Error;
    }

    stringstream out;
    string tmp;

    while(getline(cin, tmp) && tmp != dot){
        out << tmp << "\n";
    }

    return out;
}

void runner::sendCommand(const string command){
    cout << command << "\n" << dot << endl;
}

void runner::sendCommand(const string command, const string &payload){
    cout << command << "\n" << payload << "\n" << dot << endl;
}

void runner::sendCommand(const string command,const vector<string> &args, const string &payload){
    cout << command;
    for(string s : args)
        cout << " " << s;
    cout << "\n";
    if(payload != "")
        cout << payload;
    cout << dot << endl;
}

Status runner::read_status() {
    Status status;
    read(status);
    return status;
}
