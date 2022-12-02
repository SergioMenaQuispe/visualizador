#include"../utils.cpp"
#include<iostream>
using namespace std;

// Node
template<class T>
struct Node
{
    T val;
    Node * sig, * ant;

    Node(T val){
        this->val = val;
        sig = 0;
        ant = 0;
    }
};


// lista
template<class T>
class Double_Linked_List
{
private:
    Node<T> * begin;
    Node<T> * last;
    int lenght;
public:
    Double_Linked_List(){
        begin = 0;
        lenght = 0;
    }
    ~Double_Linked_List(){
        Node<T> * aux;
        while (begin)
        {
            aux = begin;
            begin = begin->sig;
            delete aux;
        }
    }

    void insert_at(T val, int index){
        lenght++;

        if(!begin){
            begin = new Node(val);
            last = begin;
            return;
        }

        Node<T> * new_node = new Node<T>(val);


        if(index == lenght-1){
            last->sig = new_node;
            new_node->ant = last;
            last = new_node;
        }
        
        else if(index == 0){
            begin->ant = new_node;
            new_node->sig = begin;
            begin = new_node;
        }

        
        else{
            Node<T> * curr = find(index);
            Node<T> * prev = curr->ant;

            new_node->sig = curr;
            new_node->ant = curr->ant;

            prev->sig = new_node;
            curr->ant = new_node;
        }

    }

    void delete_at(int index){
        if(!begin) return;

        if(index == lenght-1){
            Node<T> * aux = last;
            last = last->ant;
            delete aux;
            last->sig = 0;
        }
        
        else if(index == 0){
            Node<T> * aux = begin;
            begin = begin->sig;
            delete aux;
            begin->ant = 0;
        }

        else{
            Node<T> * curr = find(index);
            curr->ant->sig = curr->sig;
            curr->sig->ant = curr->ant;

            delete curr;
        }


    }


    Node<T> * find(T index){
        Node<T> * curr;

        int i;
        if(index >= lenght / 2){
            i = lenght - 1;
            curr = last;
            while (i != index)
            {
                curr = curr->ant;
                i--;
            }
        }else{
            i = 0;
            curr = begin;
            while (i != index)
            {
                curr = curr->sig;
                i++;
            }
        }

        return curr;
    }

    
    void show(){
        string output = "digraph \"Doubly Linked List\" {\n\trankdir=LR; \n\tnode [shape=record]; \n\ta [label=\"null\" shape=circle];";

        
        output += "b [label=\"null\" shape=circle];";

        Node<T> * aux = begin;

        int iter = 0;
        while (aux)
        {
            output += "\t" + to_string(iter) + "[label=\"{ <ref1> | <data> " + to_string(aux->val) + " | <ref2>  }\"]\n"; 

            if(!aux->ant) output += "\ta -> " + to_string(iter) + ":ref1:c      [arrowhead=dot, arrowtail=vee, dir=both, headclip=false]\n";
            else output += "\t" + to_string(iter) + ":ref1:c -> " + to_string(iter - 1) + ":data:s [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false]\n";

            if(!aux->sig) output += "\t" +to_string(iter) + ":ref2:c -> " + "b      [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false]";
            else output += "\t" + to_string(iter)  + ":ref2:c -> " + to_string(iter + 1) + ":data:n [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false]\n";

            iter++;
            aux = aux->sig;
        }
        
        output += "}";
        write("./double_linked_list/double_linked_list.dot",output);        
    }

    void print(){
        Node<T> * aux = begin;

        while (aux)
        {
            cout<<aux->val<<endl;
            aux = aux->sig;
        }
        
    }

};



int main(){

    Double_Linked_List<int> l;
    l.insert_at(5,0);
    l.insert_at(1,0);
    l.insert_at(7,2);

    l.insert_at(90,1);

    l.delete_at(3);

    l.insert_at(11,0);

    l.print();
    l.show();

    return 0;
}