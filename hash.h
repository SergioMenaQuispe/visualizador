#ifndef HASH_H
#define HASH_H


#include<iostream>
#include<list>
#include<fstream>


using namespace std;

template<class Obj, int size = 6>
class Hash
{
    private:
       list<Obj> m_Tablal[size];
    private:


    public:
    Hash(){};
    void Insert(string key, Obj obj)
    {
        int pos =FD1(key);
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
    int find(string key){
             int pos = FD1(key);
             return pos;
          }

          // delete
          void delete_key(string key){
             int pos = FD1(key);
             while (m_Tablal[pos].size() != 0)
             {
                m_Tablal[pos].pop_back();
             }
          }
     void show(){
        typedef typename list<Obj>::iterator ITERADOR;
        string output = "digraph Hash { \n \trankdir=\"LR\" \n \tnode [shape=record,width=.1,height=.1]\n \n node [shape=record,width=1.1,height=.1];\n";

         for (int i = size; i >= 0; i--)
            {
                output+="\nnode"+ to_string(i)+"[label ="+to_string(i)+"];\n";
            }
         for (int  j = 0; j < size ; j++)
            {
               ITERADOR it = m_Tablal[j].begin();

               {
                output+="\nnode"+ to_string(j);
                for(;it!=m_Tablal[j].end();++it)
                {
                    output+="->"+to_string(*it);
                }

               }




            }

         output+="\nnode [width = 1.5];}\n";

         write("hash.dot",output);}


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
     void show(int pos){
             typedef typename list<Obj>::iterator ITERADOR;
             string output = "digraph Hash { \n \trankdir=\"LR\" \n \tnode [shape=record,width=.1,height=.1]\n \n node [shape=record,width=1.1,height=.1];\n";

              for (int i = size; i >= 0; i--)
                 {
                    if(i == pos)
                        output+="\nnode"+ to_string(i)+"[label ="+to_string(i)+", color=\"red\"];\n";
                    else
                     output+="\nnode"+ to_string(i)+"[label ="+to_string(i)+"];\n";
                 }
              for (int  j = 0; j < size ; j++)
                 {
                    ITERADOR it = m_Tablal[j].begin();

                    {
                     output+="\nnode"+ to_string(j);
                     for(;it!=m_Tablal[j].end();++it)
                     {
                         output+="->"+to_string(*it);
                     }

                    }
                 }

              output+="\nnode [width = 1.5];}\n";

              write("hash.dot",output);
           }

         int FD1(string key)
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

        int FD2(string key)
              {
                   int s = key.size();
                   if (s<2) return (key[0]*key[0])%size;
                   return  (key[s/2]*key[s/2+1])%size;

              }




};

// Estas son funciones de disperciÃ³n creadas por el usuario

#endif // HASH_H
