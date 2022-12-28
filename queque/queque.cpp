#include<iostream>
#include"../utils.cpp"
using namespace std;

// Node
template<class T>
struct Node
{
    T val;
    Node * sig;

    Node(T val){
        this->val = val;
        sig = 0;
    }
};

template<class T>
class Queque
{
private:
    Node<T> * back;
    Node<T> * front;
public:
    Queque(){
        back = front = 0;
    }
    ~Queque(){
        Node<T> * aux;
        while (front)
        {
            aux = front;
            front = front->sig;
            delete aux;
        }
    }

    void insert(T val){
        if(!back){
            back = new Node<T>(val);
            front = back;
            return;
        }

        Node<T> * new_node = new Node<T>(val);
        back->sig = new_node;
        back = new_node;
    }

    void remove(){
        Node<T> * aux;
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

        Node<T> * current = front;
        Node<T> * before;

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
        Node<T> * aux = front;
        while (aux)
        {
            cout<<aux->val<<" -> ";
            aux = aux->sig;
        }
        
    }


};


int main(){

    Queque<int> q;
    q.insert(5);
    q.insert(3);
    q.print();
    q.show();


    return 0;
}