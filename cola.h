#ifndef COLA_H
#define COLA_H


#include<iostream>
#include<fstream>
using namespace std;

// Node
template<class T>
struct NodeC
{
    T val;
    NodeC * sig;

    NodeC(T val){
        this->val = val;
        sig = 0;
    }
};

template<class T>
class Queque
{
private:
    NodeC<T> * back;
    NodeC<T> * front;
public:
    Queque(){
        back = front = 0;
    }
    ~Queque(){
        NodeC<T> * aux;
        while (front)
        {
            aux = front;
            front = front->sig;
            delete aux;
        }
    }

    void insert(T val){
        if(!back){
            back = new NodeC<T>(val);
            front = back;
            return;
        }

        NodeC<T> * new_node = new NodeC<T>(val);
        back->sig = new_node;
        back = new_node;
    }

    void remove(){
        NodeC<T> * aux;
        aux = front;
        front = front->sig;
        delete aux;
    }

    T get_back(){
        return back->val;
    }

    T get_front(){
        return front->val;
    }

    void show(){

            if(!front) return;

            string output = "digraph g{ \n\trankdir=\"LR\"";

            NodeC<T> * current = front;
            NodeC<T> * before;

            if(current == back)
                output += "\t" + to_string(current->val) + "\n";

            while (current->sig)
            {

                before = current;
                if(current == front) output += "\t" + to_string(current->val) + " [color=red]\n";

                current = current->sig;

                if(current == back) output += "\t" + to_string(current->val) + " [color=blue]\n";

                output += "\t" + to_string(before->val) + " -> " + to_string(current->val) + "\n";
            }

            output += "}";

            write("queque.dot",output);
        }

    void print(){
        NodeC<T> * aux = front;
        while (aux)
        {
            cout<<aux->val<<" -> ";
            aux = aux->sig;
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



#endif // COLA_H
