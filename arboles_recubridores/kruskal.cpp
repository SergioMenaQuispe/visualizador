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


        bool existeArista(char orig, char dest, int peso)
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

        // ALGORITMO DE KRUSKAL

        // funcion que determina que si insertamos una arista, se generaria un ciclo
        bool esCiclo(char orig, char dest)
        {
            Vertice *aux = grafo;
            Arista *ari;
            char raiz1 = 'x', raiz2 = 'y';

            while(aux != NULL)
            {
                ari = aux->ady;
                while(ari != NULL)
                {
                    if(existeArista(aux->nombre,orig,ari->peso))
                        raiz1 = aux->nombre;
                    if(existeArista(aux->nombre,dest,ari->peso))
                        raiz2 = aux->nombre;
                    ari = ari->sig;
                }
                if(raiz1 == raiz2) // si la raiz de los dos es el mismo, entonces se haria un ciclo
                    return true;
                aux = aux->sig;
            }

            return false;
            
        }

        // la funcion del algoritmo
        void algoritmoKruskal(Graph *&arbol)
        {
            Vertice *aux = grafo;
            Arista *ari;
            
            char orig, dest;
            int cantAristas = 0, cantVertices = 0;
            while(aux != NULL)
            {
                arbol->insertarVertice(aux->nombre);
                aux->taken = false;
                aux = aux->sig;
                cantVertices++;
            }

            aux = grafo;

            // el menorpeso se inicializa en un valor mayor a todos, ultimo menor referencia al valor de arista en el que estamos
            int menorPeso = 11, ultimoMenor = 0;

            while(cantAristas != cantVertices-1) // hasta que la cantidad de aristas alcanza el minimo
            {
                // esta funcion no devuelve el origen, el destino y el menorPeso que deberia tomar la siguiente arista
                recursionKruskal(arbol, orig,dest,menorPeso,ultimoMenor);
                
                if(!arbol->esCiclo(orig,dest)) // si no es ciclo
                {
                    arbol->insertarArista(orig,dest,menorPeso); // insertamos arista en el arbol
                    cantAristas++; // aumena la cantidad de arista
                }
                else
                    menorPeso++; // para que el bucle no sea infinito

                ultimoMenor = menorPeso;
                menorPeso = 11;
            }
        }

        void recursionKruskal(Graph *arbol, char &orig, char &dest, int &menorPeso, int ultimoMenor)
        {
            Vertice *aux = grafo;
            Arista *ari;

            while (aux != NULL)
            {
                ari = aux->ady;
                while (ari != NULL)
                {
                    // si cumple con todas las condiciones
                    if(ari->peso < menorPeso && ari->peso >= ultimoMenor && ! arbol->existeArista(aux->nombre,ari->dest->nombre,ari->peso))
                    {
                        // se cambia  los valores actuales
                        orig = aux->nombre;
                        dest = ari->dest->nombre;
                        menorPeso = ari->peso;
                    }
                    ari = ari->sig;
                }
                aux = aux->sig;
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

    Graph * kruskal = new Graph;
    g.algoritmoKruskal(kruskal);

    kruskal->show();


    return 0;
}