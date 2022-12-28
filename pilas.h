#ifndef PILAS_H
#define PILAS_H


#include<iostream>
#include<fstream>
using namespace std;


// Node
template<class T>
struct NodeP
{
    T val;
    NodeP * ant;

    NodeP(T val){
        this->val = val;
        ant = 0;
    }
};

template<class T>
class Stack
{
private:
    NodeP<T> * top;
public:
    Stack(){
        top = 0;
    }
    ~Stack(){

        NodeP<T> * aux;
        while (top)
        {
            aux = top;
            top = top->ant;
            delete aux;
        }
    }


    void push(T val){
        if(!top){
            top = new NodeP<T>(val);
            return;
        }

        NodeP<T> * new_node = new NodeP<T>(val);
        new_node->ant = top;
        top = new_node;
    }


    T pop(){
        NodeP<T> * aux;
        aux = top;
        T val = aux->val;
        top = top->ant;
        delete aux;

        return val;
    }

    T get_top(){
        return this->top->val;
    }


    // mostrar en el .dot
    void show(){
        string output = "digraph { \n\tgraph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"2\", splines=\"ortho\"]; \n\tnode [shape=plain] \n\trankdir=LR; \n\tFoo [label=<\n\t<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">";

        if(!top) return;
        NodeP<T> * aux = top;
        while (aux->ant)
        {
            if(aux == top)
                output += "\t<tr><td bgcolor=\"red\">" + to_string(aux->val) +"</td></tr>\n";
            else
                output += "\t<tr><td>" + to_string(aux->val) + "</td></tr>\n";

            cout<<aux->val<<endl;
            aux = aux->ant;
        }

        output += "\t<tr><td>" + to_string(aux->val) + "</td></tr>\n";
        output += "</table>>\n];\n}";
        write("stack.dot",output);

    }

    void print(){
        if(!top) return;
        NodeP<T> * aux = top;

        while (aux)
        {
            cout<<aux->val;
            aux = aux->ant;
        }
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


};


#endif // PILAS_H
