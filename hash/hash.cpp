#include<iostream>
#include<list>
#include "utils.cpp"

using namespace std;

template<class Obj, int (*fd)(string, int) , int size = 11>
class Hash
{
    private:
       list<Obj> m_Tablal[size];
    private:

     
    public:
    Hash(){};  
    void Insert(string key, Obj obj)
    {
        int pos =fd(key,size);
        cout<<"Lugar de insercion : "<<pos<<endl; 
        m_Tablal[pos].push_back(obj);
    }

    void Print()
    {
       typedef typename list<Obj>::iterator ITERADOR;

      for (int  i = 0; i < size ; i++)
      {
         ITERADOR it = m_Tablal[i].begin();
         cout<<"["<<i<<"]" ;
         for(;it!=m_Tablal[i].end();++it)
           cout<<*it<<"-->";
         cout<<endl;
      }
     
       
    }
    
     void show(){
        typedef typename list<Obj>::iterator ITERADOR;
        string output = "digraph Hash { \n \trankdir=\"RL\" \n \tnode [shape=record,width=.1,height=.1]\n \n node [shape=record,width=1.1,height=.1];\n";
        char aux='A';

        for (int  i = 0; i < size ; i++)
      {
         ITERADOR it = m_Tablal[i].begin();
         for(;it!=m_Tablal[i].end();++it)
         {
            output+="\tnode"+ to_string(i)+aux+"[label =  \" Lugar de insercion : "+ to_string(i)+" \" ,width=1.5]\n ";
            output+="node"+ to_string(i)+aux+ "->"+ to_string(*it)+"";   
         }
           
      }
      output+="\nnode [width = 1.5];}\n";
     
        write("hash.dot",output);} 
           
    
};

// Estas son funciones de disperciÃ³n creadas por el usuario
  int FD1(string key, int size)
       {
            char * p = (char*)key.c_str();
            int s =0;
            while (*p)
            {
              s+=*p;
              p++;
            }
            return s%size;
            
       } 

 int FD2(string key, int size)
       {
            int s = key.size();
            if (s<2) return (key[0]*key[0])%size;
            return  (key[s/2]*key[s/2+1])%size;
            
       } 


int main()
{
   Hash<int,FD2>  A;
   A.Insert("cuatro",4);
   A.Insert("ocho",34);
   A.Insert("nueve",44);
   A.Insert("treitaitres",54);
   A.Insert("noventa",64);
   A.Insert("xxxx",774);
   A.Print();
  A.show();
}

