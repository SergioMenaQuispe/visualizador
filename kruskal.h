#ifndef KRUSKAL_H
#define KRUSKAL_H


#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
using namespace std;

struct AristaK;

struct VerticeK{
    char nombre;
    VerticeK *sig;
    AristaK *ady;
    bool taken;
};

struct AristaK{
    VerticeK *dest;
    AristaK *sig;
    int peso;
};


class GraphK {
    private:
        VerticeK *grafo;
    public:
        GraphK(){grafo = NULL;}
        void insertarVertice(char nombre)
        {
            VerticeK *aux,*nuevo = new VerticeK();
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

        void agregarArista(VerticeK *&aux1, VerticeK *&aux2, int peso, AristaK *&nueva_arista)
        {
            AristaK *ari;
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
            AristaK *nueva_arista = new AristaK();
            VerticeK *aux1, *aux2;

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
                VerticeK *aux_borrar;
                VerticeK *anterior = NULL;

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
                    VerticeK * punt = grafo;
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

                    VerticeK * punt = grafo;
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

        void eliminarArista(VerticeK *&orig, char dest)
        {

            // la arita a borrar que toma el valor ady a origen
            AristaK *borrar = orig->ady, *anterior = NULL;

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
        void eliminarGrafo(VerticeK *&grafo, char &n)
        {
            VerticeK *aux = grafo;
            n = aux->nombre;
            grafo = aux->sig;
            delete aux;
        }

        void mostrarGrafo()
        {
            VerticeK *punt;
            AristaK *ari;
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

        VerticeK *getVertice(char nombre)
        {
            VerticeK *vert, *aux = grafo;
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
            VerticeK *aux = grafo;
            AristaK *ari;
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
            VerticeK *aux = grafo;
            AristaK *ari;
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
        void algoritmoKruskal(GraphK *&arbol)
        {
            VerticeK *aux = grafo;
            AristaK *ari;

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

        void recursionKruskal(GraphK *arbol, char &orig, char &dest, int &menorPeso, int ultimoMenor)
        {
            VerticeK *aux = grafo;
            AristaK *ari;

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
            VerticeK *punt;
            AristaK *ari;
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
        void show_arbol()
        {

            ofstream archivo;
            archivo.open("arbol.dot",ios::out);

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


#endif // KRUSKAL_H
