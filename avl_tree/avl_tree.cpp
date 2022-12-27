#include <iostream>
using namespace std;

template<class T>
class Nodo
{
   public:
        T m_Dato;
        Nodo<T> * m_pSon[2];
        int height;

        Nodo(T d)
        {
            m_Dato=d;
            m_pSon[0]=0;
            m_pSon[1]=0;
            height = 0;
        }  
};

template<class T>
class Arbol_AVL{
    private:
        Nodo<T> * m_pRoot;
    public:
        Arbol_AVL():m_pRoot(0){};

        int height(Nodo<T> * p){
            if(!p) return 0;
            return p->height;
        }

        int factorEquilibrio(Nodo<T> * p){
            if(!p) return 0;
            return height(p->m_pSon[0]) - height(p->m_pSon[1]);
        }

        void actualizarHeight(Nodo<T> * p){
            if(height(p->m_pSon[0]) > height(p->m_pSon[1])){
                p->height = height(p->m_pSon[0]) + 1;
                return;
            }

            p->height = height(p->m_pSon[1]) + 1;
        }

        // rotaciones
        void rotacionSimple(Nodo<T> * p, bool direccion){
            /*
                direccion (true) -> izq
                direccion (false) -> der
            */
            Nodo<T> * new_p = p->m_pSon[direccion];
            p->m_pSon[direccion] = p->m_pSon[!direccion];
            new_p->m_pSon[!direccion] = p;

            actualizarHeight(p);
            actualizarHeight(new_p);
        }

        void balanceo(Nodo<T> * p){
            actualizarHeight(p);

            int FE = factorEquilibrio(p);

            if(FE == 2){
                if(factorEquilibrio(p->m_pSon[0]) < 0){
                    rotacionSimple(p->m_pSon[0], true);
                }
                rotacionSimple(p, false);
                return;
            } else if(FE == -2){
                if(factorEquilibrio(p->m_pSon[1]) > 0){
                    rotacionSimple(p->m_pSon[1], false);
                }
                rotacionSimple(p, true);
                return;
            }
        }

        void Add(T d)
        {
            Nodo<T> * pTmp = m_pRoot;
            if(!pTmp) {m_pRoot = new Nodo<T>(d);  return;}

            while(!(pTmp->m_pSon[0]==0 && pTmp->m_pSon[1]==0))
                pTmp = pTmp->m_pSon[pTmp->m_Dato < d];

            Nodo<T> * newNodo = pTmp->m_pSon[pTmp->m_Dato < d];
            newNodo = new Nodo<T>(d);
            balanceo(newNodo);
        }

        
        void pre_order(Nodo<T> * r)
        {
            if(!r) return;
            cout<<r->m_Dato<<endl;
            pre_order(r->m_pSon[0]);
            pre_order(r->m_pSon[1]);
        }

        void pre_order(){
            pre_order(m_pRoot);
        }


};

int main(){

    Arbol_AVL<int> A;
    A.Add(5);
    A.Add(3);
    A.Add(7);
    A.Add(2);
    A.Add(4);
    A.Add(6);
    A.Add(8);

    A.pre_order();

    return 0;
}