#ifndef ARBOLB_H
#define ARBOLB_H


#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

template<class T>
class NodoAB
{
   public:
     T m_Dato;
     NodoAB<T> * m_pSon[2];

     NodoAB(T d)
     {
        m_Dato=d;
        m_pSon[0]=0;
        m_pSon[1]=0;
     }
};


template<class T>
class Tree
{
   private:
      NodoAB<T> * m_pRoot;
   public:
      Tree():m_pRoot(0){};

      void Add_r(T d, NodoAB<T> *  & p)
      {
        if(!p)
        {
           p = new NodoAB<T>(d); return;
        }
        Add_r(d,p->m_pSon[p->m_Dato < d]);
      }
      void Add_r(T d){
               Add_r(d, m_pRoot);
            }

      Tree<T> & operator<<(T d)
      {
            Add_r(d,m_pRoot);
            //Add(d);
            return *this;
      }

      friend ostream & operator<<(ostream & os , Tree<T> & arb)
      {
           arb.Print(arb.m_pRoot,os);
           return os;
      }

      void Print(NodoAB<T> * r, ostream & os)
      {
         if(!r) return;
         os<<r->m_Dato<<endl;
         Print(r->m_pSon[0],os);
         Print(r->m_pSon[1],os);
      }

      void Add(T d)
      {
        NodoAB<T> * pTmp = m_pRoot;
        if(!pTmp) {m_pRoot = new NodoAB<T>(d); return;}
        while(!(pTmp->m_pSon[0]==0 && pTmp->m_pSon[1]==0))
           pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
        pTmp->m_pSon[pTmp->m_Dato < d]= new NodoAB<T>(d);
      }

      // si tiene un solo hijo lo elimino
      void Delete_one_Son(NodoAB<T> *& pTmp){
         if(pTmp->m_pSon[0]) {
            delete pTmp->m_pSon[0];
            pTmp->m_pSon[0] = NULL;
         }

         else{
            delete pTmp->m_pSon[1];
            pTmp->m_pSon[1] = NULL;
         }
      }

      // si tiene los dos hijos
      void Delete_2_Son(NodoAB<T> *& pTmp){
         delete pTmp->m_pSon[0];
         pTmp->m_pSon[0] = NULL;
         delete pTmp->m_pSon[1];
         pTmp->m_pSon[1] = NULL;
      }

      // si no tiene hijos
      void Delete_Hoja(NodoAB<T> *& pTmp, NodoAB<T> *& pAnt){
         if(pAnt->m_pSon[0] == pTmp) pAnt->m_pSon[0] = 0;
         else if(pAnt->m_pSon[1] == pTmp) pAnt->m_pSon[1] = 0;
         delete pTmp;
      }

      // llama las funciones anteriores
      void Delete(T d){
         NodoAB<T> * pTmp = m_pRoot;
         NodoAB<T> * pAnt;
         if(!pTmp){
            cout<<"Error: el arbol esta vacio"<<endl;
            return;
         }

         while (pTmp->m_Dato != d){
            pAnt = pTmp;
            pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
         }


         // es hoja
         if(!(pTmp->m_pSon[0] && pTmp->m_pSon[1])) {
            Delete_Hoja(pTmp,pAnt);
         }

         // tiene dos hijo
         else if(pTmp->m_pSon[0] && pTmp->m_pSon[1]){
            Delete_2_Son(pTmp);
         }

         // tien un solo hijo
         else{
            Delete_one_Son(pTmp);
         }

      }

      bool find_r(T d, NodoAB<T> * p){
         if(!p)
         {
            return false;
         }

         if(p->m_Dato == d)
         {
            return true;
         }

         return find_r(d,p->m_pSon[p->m_Dato < d]);
      }

      bool find_r(T d){
         return find_r(d,m_pRoot);
      }

      NodoAB<T> * find(T d){
        NodoAB<T> * pTmp = m_pRoot;
        if(!pTmp) {return nullptr;}
        while(pTmp){
         if(pTmp->m_Dato == d) {return pTmp;}
         pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
        }
         return nullptr;
      }


      void pre_order(NodoAB<T> * r)
      {
         if(!r) return;
         cout<<r->m_Dato<<endl;
         pre_order(r->m_pSon[0]);
         pre_order(r->m_pSon[1]);
      }

      void pre_order(){ pre_order(this->m_pRoot); }

      void post_order(NodoAB<T> * r)
      {
         if(!r) return;
         post_order(r->m_pSon[0]);
         post_order(r->m_pSon[1]);
         cout<<r->m_Dato<<endl;
      }

      void post_order(){ post_order(this->m_pRoot); }


      void in_order(NodoAB<T> * r)
      {
         if(!r) return;
         in_order(r->m_pSon[0]);
         cout<<r->m_Dato<<endl;
         in_order(r->m_pSon[1]);
      }

      void in_order(){ in_order(this->m_pRoot); }

      // Print (sin usar recursión)
      void Print_Iterativo(){
         stack<NodoAB<T>*> stack;
         NodoAB<T> * pTmp = m_pRoot;

         while (!stack.empty() || pTmp != NULL)
         {
            if(pTmp != NULL){
               stack.push(pTmp);
               pTmp = pTmp->m_pSon[0];
            }else{
               pTmp = stack.top();
               stack.pop();
               cout<< pTmp->m_Dato <<endl;
               pTmp = pTmp->m_pSon[1];
            }
         }
      }

      NodoAB<T> *    Max(NodoAB<T> * p){

               while (p->m_pSon[1])
               {
                  p = p->m_pSon[1];
               }

               return p;
            }

            NodoAB<T> * Max(){
               return Max(m_pRoot);
            }

            NodoAB<T> *    Min(NodoAB<T> * p){

               while (p->m_pSon[0])
               {
                  p = p->m_pSon[0];
               }

               return p;
            }

            NodoAB<T> * Min(){
               return Min(m_pRoot);
            }

    void generate_output(NodoAB<T> * r, string & s){

         if(!r) return;
         s += "\n\t" + to_string(r->m_Dato) + "\n";
         if(r->m_pSon[0]){
            NodoAB<T> * aux = r->m_pSon[0];
            s += "\n\t" + to_string(r->m_Dato) + " -> " + to_string(aux->m_Dato) + "[label=\"0\"]";
            generate_output(r->m_pSon[0], s);
         }

         if(r->m_pSon[1]){
            NodoAB<T> * aux = r->m_pSon[1];
            s += "\n\t" + to_string(r->m_Dato) + " -> " + to_string(aux->m_Dato) + "[label=\"1\"]";
            generate_output(r->m_pSon[1], s);
         }
    }

    void show(){
         string output = "digraph BST {\n\tnode [fontname=\"Arial\"];";
         NodoAB<T> * aux = m_pRoot;
         generate_output(m_pRoot,output);
         output += "\n}";
         write("tree.dot",output);
    }

    void show(NodoAB<T> * d){
         string output = "digraph BST {\n\tnode [fontname=\"Arial\"];";
         NodoAB<T> * aux = m_pRoot;
         generate_output(m_pRoot,output);
         output += "\n\t" + to_string(d->m_Dato) + "[color=red]\n";
         output += "\n}";
         write("tree.dot",output);
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



#endif // ARBOLB_H
