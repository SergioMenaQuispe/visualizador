#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
using namespace std;

struct Arista;

struct Vertice{
    char nombre;
    Vertice *sig;
    Arista *ady;
    bool taken;
};

struct Arista{
    Vertice *dest;
    Arista *sig;
    int peso;
};


class Graph {
    private:
        Vertice *grafo;
    public:
        Graph(){grafo = NULL;}
        void insertarVertice(char nombre)
        {
            Vertice *aux,*nuevo = new Vertice();
            nuevo->nombre = nombre;
            nuevo->sig = NULL;
            nuevo->ady = NULL;

            if(grafo == NULL)
                grafo = nuevo;
            else{
                aux = grafo;
                while(aux->sig != NULL)
                    aux = aux->sig;
                aux->sig = nuevo;
            }
            cout<<nuevo->nombre<<" Ingresado al grafo "<<endl;

        }

        void agregarArista(Vertice *&aux1, Vertice *&aux2, int peso, Arista *&nueva_arista)
        {
            Arista *ari;
            if(aux1->ady == NULL)
            {
                aux1->ady = nueva_arista;
                nueva_arista->dest = aux2;
                nueva_arista->peso = peso;
            }
            else{
                ari = aux1->ady;
                while(ari->sig != NULL)
                    ari = ari->sig;
                nueva_arista->dest = aux2;
                ari->sig = nueva_arista;
                nueva_arista->peso = peso;
            }

        }

        void insertarArista(char orig, char dest, int peso)
        {
            Arista *nueva_arista = new Arista();
            Vertice *aux1, *aux2;

            if(grafo == NULL)
            {
                cout<<"No hay grafo"<<endl;
                return;
            }
            nueva_arista->sig = NULL;
            aux1 = grafo;
            aux2 = grafo;

            while(aux2 != NULL)
            {
                if(aux2->nombre == dest)
                    break;
                aux2 = aux2->sig;
            }
            while(aux1 != NULL)
            {
                if(aux1->nombre == orig)
                {
                    agregarArista(aux1,aux2,peso,nueva_arista);
                    return;
                }
                aux1 = aux1->sig;
            }

        }

        void eliminarVertice(char n)
        {
            // si el grafo no esta vacio
            if(grafo != NULL)
            {
                Vertice *aux_borrar;
                Vertice *anterior = NULL;

                // aux borrar señalara el primer valor del grafo
                aux_borrar = grafo;

                // recorrer el grafo
                while((aux_borrar != NULL)&&(aux_borrar->nombre != n))
                {
                    anterior = aux_borrar;
                    aux_borrar = aux_borrar->sig;
                }

                // el vertice no fue encontrado
                if(aux_borrar == NULL)
                    cout<<"El elemento no ha sido encontrado"<<endl;
                
                // el primer vertice es el que vamos a eliminar
                else if(anterior == NULL)
                {
                    Vertice * punt = grafo;
                    while (punt)
                    {
                        eliminarArista(punt,n);
                        punt = punt->sig;
                    }
                    
                    grafo = grafo->sig;
                    delete aux_borrar;

                    
                }

                // si el vertice a borrar no es el primero
                else
                {
                    
                    Vertice * punt = grafo;
                    while (punt)
                    {
                        eliminarArista(punt,n);
                        punt = punt->sig;
                    }

                    anterior->sig = aux_borrar->sig;
                    delete aux_borrar;

                }
            }
        }

        void eliminarArista(Vertice *&orig, char dest)
        {
            
            // la arita a borrar que toma el valor ady a origen
            Arista *borrar = orig->ady, *anterior = NULL;

            // recorremos el grafo
            while((borrar != NULL)&&(borrar->dest->nombre != dest))
            {
                anterior = borrar;
                borrar = borrar->sig;
            }
            
            if(borrar == NULL)
                cout<<"Elemento no encontrado"<<endl;

            // la arista es la primera de la lista de aristas del origen
            else if(anterior == NULL)
            {
                orig->ady = orig->ady->sig;
                delete borrar; 
            }

            else
            {
                anterior->sig = borrar->sig;
                delete borrar;
            }
        }

        // recorremos todo el grafo y vamos eliminando
        void eliminarGrafo(Vertice *&grafo, char &n)
        {
            Vertice *aux = grafo;
            n = aux->nombre;
            grafo = aux->sig;
            delete aux;
        }

        void mostrarGrafo()
        {
            Vertice *punt;
            Arista *ari;
            punt = grafo;
            cout<<"Nodo: Adyacencia"<<endl;
            while(punt != NULL)
            {
                cout<<"   "<<punt->nombre<<"->";
                if(punt->ady != NULL)
                {
                    ari = punt->ady;
                    while(ari != NULL)
                    {
                        cout<<" "<<ari->dest->nombre;
                        ari = ari->sig;
                    }
                }
                punt = punt->sig;
                cout<<endl;
            }
        }

        Vertice *getVertice(char nombre)
        {
            Vertice *vert, *aux = grafo;
            while(aux != NULL)
            {
                if(aux->nombre == nombre)
                    vert = aux;
                aux = aux->sig;
            }
            return vert;
        }


        /*
        
        ALGORITMO DE PRIM

        */

       bool todosTomados(Vertice *grafo)
        {
            bool band = true;
            Vertice *aux = grafo;
            while(aux != NULL)
            {
                if(aux->taken == false)
                    band = false;
                aux = aux->sig;
            }
            return band;
        }

        Vertice *getVertice(Vertice *grafo, char nombre)
        {
            Vertice *vert, *aux = grafo;
            while(aux != NULL)
            {
                // recorremos hasta que el aux tome el valor que queremos
                if(aux->nombre == nombre)
                    vert = aux;
                aux = aux->sig;
            }
            // retornamos el vertice
            return vert;
        }

        bool existe(vector<char> T, char a)
        {
            for(int i = 0; i < T.size(); i++)
                if(T[i] == a)
                    return true;

            return false;
        }

        bool existeArista(Vertice *grafo, char orig, char dest, int peso)
        {
            Vertice *aux = grafo;
            Arista *ari;
            while(aux != NULL)
            {
                if(aux->nombre == orig)
                {
                    ari = aux->ady;
                    while(ari != NULL)
                    {
                        if(ari->dest->nombre == dest && ari->peso == peso)
                            return true;
                        ari = ari->sig;
                    }
                }
                aux = aux->sig;
            }

            return false;
        }


        // segunda parte de prim
        void algoritmoPrim(Graph *&arbol)
        {
            Vertice *aux = grafo;
            Arista *ari;

            // contadores de vertices y aristas
            int cantVertices = 0;
            int cantAristas = 0;

            // incializamos a todo el arbol y el aux en taken false
            while(aux != NULL)
            {
                arbol->insertarVertice(aux->nombre);
                cantVertices++;
                aux->taken = false;
                aux = aux->sig;
            }

            aux = grafo;
            char destino;
            vector<char> T; // vector T para leer los vertices ya tomado

            Vertice *aux2; // otro auxiliar para tomar el vertice con arista del menor peso

            while(cantAristas != cantVertices-1) // cuando la cantidad de arista llegue a cantidad de vertices -1 termina el bucle
            {
                int menorPeso = 11; // inicializamos el peso como el maximo valor que alcanzan los pesos en el programa

                if(arbol->existe(T,aux->nombre) == false) // si el vertice no exite, lo insertamos en el vector
                T.push_back(aux->nombre);

                for(int i = 0; i < T.size(); i++) // analizamos el menor peso con todos los valores del vector
                {
                    aux = getVertice(grafo,T[i]);  // aux toma cada valor
                    recursionPrim(aux,arbol,menorPeso,destino);   // ejecutamos el algoritmo     

                    if(existeArista(grafo,aux->nombre,destino,menorPeso)) // si existe la arista, aux2 referencia al camino indicado
                        aux2 = aux;
                }
                
                Vertice *vert = getVertice(grafo,destino); // hace referencia a destino
                if(aux2->nombre != destino && vert->taken == false)  // si no es un lazo y además no fue tomado
                {
                    arbol->insertarArista(aux2->nombre,destino,menorPeso); // insertamos la arita
                    cantAristas++;
                }

                aux = getVertice(grafo,destino); // aux toma ahora el valor de destino

            }
        }

        // este es una primera parte del algoritmo
        void recursionPrim(Vertice *&aux, Graph *&arbol, int &menorPeso, char &destino)
        {
            Arista *ari;
            ari = aux->ady;
            aux->taken = true; // aux ya fue tomado

            while(ari != NULL)
            {
                // si el peso es menor y ademas el destino no fue tomado
                if(ari->peso < menorPeso && !(ari->dest->taken))
                {
                    menorPeso = ari->peso;
                    destino = ari->dest->nombre;
                }
                ari = ari->sig;
            }
        }

        
        // graficar el grafo con graphviz
        string instruccionGrafo()
        {
            Vertice *punt;
            Arista *ari;
            punt = grafo;

            string texto;

            while(punt != NULL)
            {
                texto += punt->nombre;
                texto += "\n";
                if(punt->ady != NULL)
                {

                    ari = punt->ady;
                    while(ari != NULL)
                    {
                        texto += "\t";
                        texto += punt->nombre;
                        texto += " -- ";
                        texto += ari->dest->nombre;
                        texto += "[label=";
                        texto += to_string(ari->peso);
                        texto += "]";
                        texto += ";\n"; 
                        ari = ari->sig;
                    }
                } 

                punt = punt->sig;
            }

            return texto;
        }


        void show()
        {
            
            ofstream archivo;
            archivo.open("graph.dot",ios::out);

            if(archivo.fail())
            {
                cout<<"Ocurrio un error";
                exit(1);
            }
            archivo<<"graph A {\n"
            <<instruccionGrafo()
            <<"}";

            archivo.close();
        }


};




// funcion menu

int main()
{
    Graph g;
    g.insertarVertice('A');
    g.insertarVertice('B');
    g.insertarVertice('C');
    g.insertarVertice('D');
    g.insertarVertice('E');
    g.insertarVertice('F');
    g.insertarVertice('G');
    g.insertarVertice('H');

    g.insertarArista('A','C',6);
    g.insertarArista('C','B',3);
    g.insertarArista('C','E',7);
    g.insertarArista('B','G',7);
    g.insertarArista('A','D',9);
    g.insertarArista('D','F',8);
    g.insertarArista('F','H',2);

    g.insertarArista('B','D',10);

    g.show();

    Graph * prim = new Graph;
    g.algoritmoPrim(prim);

    prim->show();


    return 0;
}