#include<iostream>
#include<fstream>
#include"utils.cpp"
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
class List
{
private:
    Node<T> * head;
public:
    List(){
        head = 0;
    }
    ~List(){
        Node<T> * aux;
        while (head)
        {
            aux = head;
            head = head->sig;
            delete aux;
        }
        
    }

    // inserciones
    void insert_last(T val){
        if(!head){
            head = new Node(val);
            return;
        }

        Node<T> * before;
        Node<T> * current = head;

        while (current){
            before = current;
            current = current->sig;
        }

        current = new Node<T>(val);
        before->sig = current;
    }

    void insert_front(T val){
        if(!head){
            head = new Node<T>(val);
            return;
        }

        Node<T> * new_node = new Node<T>(val);
        new_node->sig = head;
        head = new_node;
    }

    void insert_at(T val, int position){
        Node<T> * current = head;
        int p = 0;

        if(position == 0) {
            insert_front(val);
            return;
        }

        while (p != position - 1)
        {
            current = current->sig;
            if(!current) return;
            ++p;
        }


        Node<T> * new_node = new Node(val);
        new_node->sig = current->sig;
        current->sig = new_node;        
    }

    // deletecions
    
    void delete_last(){
        Node<T> * current = head;
        Node<T> * before;
        while (current->sig)
        {
            before = current;
            current = current->sig;
        }

        before->sig = 0;
        delete current;        
    }

    void delete_front(){
        Node<T> * aux;
        aux = head;
        head = head->sig;
        delete aux;
    }

    
    void delete_at(int position){
        
        Node<T> * before;
        Node<T> * current = head;
        int p = 0;

        if(position == 0) {
            delete_front();
            return;
        }

        while (p != position)
        {
            before = current;
            current = current->sig;
            if(!current) return;
            ++p;
        }

        before->sig = current->sig;
        delete current;
    }

     

    // mostrar en el .dot
    void show(){
        
        Node<T> * before;
        Node<T> * current = head;
        string output = "digraph G { \n \trankdir=\"LR\" \n \tnode [shape=record]\n";
        
        int var = 0;
        while (current)
        {
            before = current;
            current = current->sig;

            output += "\t" + to_string(var) + "[label=\"{ <data> " + to_string(before->val) +" | <ref>  }\"]\n";
            if(current){
                output += "\t" + to_string(var) + ":ref:c -> " + to_string(var + 1) + ":data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false]" + "\n";
                ++var;
            }
        }

        output += "\tnull [shape=box]\n";
        output += "\t" + to_string(var) + ":ref:c -> null [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false]" + "\n";
        output += "}";

        write("input.dot",output);
        
    }

    /*
    void print(){
        Node * aux = head;
        while (aux)
        {
            cout<<aux->val<<" -> ";
            aux = aux->sig;
        }
        
    }*/

};

int main()
{
    List<int> l;
    l.insert_last(5);
    l.insert_last(6);
    l.insert_last(9);
    l.insert_last(19);

    l.show();
    return 0;
}
