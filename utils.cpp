#ifndef UTILS
#define UTILS
#include<iostream>
#include<fstream>
using namespace std;


string read(string name){
    ifstream file(name);
    if(!file.is_open()) {
        cout<<"Error al abrir el file";
        return "";
    }

    string text = "", linea;
    while (!file.eof())
    {
        getline(file,linea);
        text += linea + "\n";
    }

    file.close();
    return text;
}

void write(string name, string text){
    ofstream file;
    file.open(name, fstream::out);

    if(!file.is_open()) {
        cout<<"Error al abrir el file";
        return;
    }

    file << text;
    file.close();
}

#endif
