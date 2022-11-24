#include<iostream>
#include<fstream>
#include"utils.cpp"
using namespace std;


// Node
template<class T>
struct Node
{
    T val;
    Node * ant;

    Node(T val){
        this->val = val;
        ant = 0;
    }
};

template<class T>
class Stack
{
private:
    Node<T> * top;
public:
    Stack(){
        top = 0;
    }
    ~Stack(){
        
        Node<T> * aux;
        while (top)
        {
            aux = top;
            top = top->ant;
            delete aux;
        }
    }

    
    void push(T val){
        if(!top){
            top = new Node(val);
            return;
        }

        Node<T> * new_node = new Node<T>(val);
        new_node->ant = top;
        top = new_node;
    }

    
    T pop(){
        Node<T> * aux;
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
        Node<T> * aux = top;
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
        write("input.dot",output);
        
    }

    void print(){
        if(!top) return;
        Node<T> * aux = top;

        while (aux)
        {
            cout<<aux->val;
            aux = aux->ant;
        }
    }


};

int main(){

    Stack<int> s;

    s.push(5);
    s.push(6);
    s.push(16);
    s.push(63);
    s.push(61);
    s.push(67);
    s.push(56);
    s.pop();
    s.pop();
    s.push(5);

    s.show();
    //s.print();

    return 0;
}