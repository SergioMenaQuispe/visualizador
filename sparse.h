#ifndef SPARSE_H
#define SPARSE_H


#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class NodoE
{
    public:
        int m_row;
        int m_col;
        NodoE<T> * m_pNext_row;
        NodoE<T> * m_pNext_col;
        T         m_Data;
    public:
        NodoE(T d, int row, int col)
        {
            m_Data = d;
            m_row = row;
            m_col = col;
            m_pNext_row =m_pNext_col =0;
        }

        void Matate(){
        delete this;
        }

};


template<class T, int row_size=5, int col_size=5>
class Matrix
{
    private:
        NodoE<T>  * m_Row[row_size];
        NodoE<T>  * m_Col[col_size];
    public:
        Matrix(){
            for(int i=0;i<row_size;i++)
                m_Row[i]=0;
            for(int i=0;i<col_size;i++)
                m_Col[i]=0;

        };
        void Insert(T d, int row, int col)
        {
            NodoE<T> ** p,**q;
            bool r =  find_row(row, col, p);
            bool c =  find_col(row, col, q);
            if(!r && !c){
                NodoE<T> * pNew = new NodoE<T>(d,row,col);
                pNew->m_pNext_row = *p;
                (*p) = pNew;
                pNew->m_pNext_col = *q;
                (*q) = pNew;
            }

            (*p)->m_Data = d;
        }

        void delete_cell(int row, int col){

        }
        bool find_row(int row, int col, NodoE<T> ** & p){
            p = &m_Col[col];
            while(*p){
                if((*p)->m_row == row) return true;
                if((*p)->m_row < row) return false;
                p = &((*p)->m_pNext_row);
            }
            return false;
        }

        bool find_col(int row, int col, NodoE<T> ** & p){
            p = &m_Row[row];
            while(*p){
                if((*p)->m_col == col) return true;
                if((*p)->m_col < col) return false;
                p = &((*p)->m_pNext_col);
            }
            return false;
        }

        void Delete(int row, int col){
            NodoE<T> **p;
            if(find_row(row, col, p)){
                delete (*p);
            }
        }

        void change(int row, int col);

        void Sum(int row);
        void Sum(int row, int begin, int end);

        void Print(){
            cout<<"    ";
            for(int j=0;j<col_size;j++)
                cout<<"C"<<j<<": ";
            cout<<endl;
            for(int i=0;i<row_size;i++){
                cout<<"F"<<i<<": ";
                for(int j=0;j<col_size;j++){
                    NodoE<T> **p;
                    if(find_col(i,j,p))
                        cout<<(*p)->m_Data<<"   ";
                    else
                        cout<<"0   ";
                }
                cout<<endl;
            }
        }

        T max_row(int row){
            T max=0;
            for(int j=0;j<col_size;j++){
                NodoE<T> **p;
                if(find_col(row,j,p))
                    if((*p)->m_Data >= max)
                        max=(*p)->m_Data;
            }
            return max;
        }
        T min_row(int row){
            T min;
            NodoE<T> **p;
            for(int j=0;j<col_size;j++){
                if(find_col(row,j,p))
                    min=(*p)->m_Data;
                if(min!=0)
                    break;
            }
            for(int j=0;j<col_size;j++){
                if(find_col(row,j,p))
                    if((*p)->m_Data <= min)
                        min=(*p)->m_Data;
            }
            return min;
        }

        T max_col(int col){
            T max=0;
            for(int j=0;j<row_size;j++){
                NodoE<T> **p;
                if(find_col(j,col,p))
                    if((*p)->m_Data >= max)
                        max=(*p)->m_Data;
            }
            return max;
        }
        T min_col(int col){
            T min;
            NodoE<T> **p;
            for(int j=0;j<row_size;j++){
                if(find_col(j,col,p))
                    min=(*p)->m_Data;
                if(min!=0)
                    break;
            }
            for(int j=0;j<row_size;j++){
                if(find_col(j,col,p))
                    if((*p)->m_Data <= min)
                        min=(*p)->m_Data;
            }
            return min;
        }

        T max(){
            T max=0;
            for(int i=0;i<row_size;i++){
                for(int j=0;j<col_size;j++){
                    NodoE<T> **p;
                    if(find_col(i,j,p))
                        if((*p)->m_Data >= max)
                            max=(*p)->m_Data;
                }
            }
            return max;
        }
        T min(){
            T min=0;
            NodoE<T> **p;
            for(int i=0;i<row_size;i++){
                for(int j=0;j<col_size;j++){
                    if(find_col(i,j,p))
                        min=(*p)->m_Data;
                    if(min!=0)
                        break;
                }
            }
            for(int i=0;i<row_size;i++){
                for(int j=0;j<col_size;j++){
                    if(find_col(i,j,p))
                        if((*p)->m_Data <= min)
                            min=(*p)->m_Data;
                }
            }
            return min;
        }
        T sum_row(int row){
            T sum=0;
            for(int j=0;j<col_size;j++){
                NodoE<T> **p;
                if(find_col(row,j,p))
                    sum += (*p)->m_Data;
            }
            return sum;
        }

        T sum_col(int col){
            T sum=0;
            for(int j=0;j<row_size;j++){
                NodoE<T> **p;
                if(find_col(j,col,p))
                    sum += (*p)->m_Data;
            }
            return sum;
        }

        void show(){
            string output = "digraph Sparce_Matrix { \n\tsnode [shape=box]\n\tMt[ label = \"Matrix\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];\n\te0[ shape = point, width = 0 ];\n\te1[ shape = point, width = 0 ];";

            // filas
            for(int i = 0; i < row_size; i++){
                output += "\tU" + to_string(i) + " [label = " + "\"" + to_string(i) + "\"" + " width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n";
            }

            for(int i = 1; i < row_size; i++){
                output += "\tU" + to_string(i - 1) + " -> " + "U" + to_string(i) + "\n";
                output += "\tU" + to_string(i) + " -> " + "U" + to_string(i - 1) + "\n";
            }

            // columnas
            for(int i = 0; i < col_size; i++){
                output += "\tA" + to_string(i) + " [label = " + "\"" + to_string(i) +"\""+ "   width = 1.5 style = filled, fillcolor = lightskyblue, group = " + to_string(i + 2) +  " ];\n";
            }

            for(int i = 1; i < col_size; i++){
                output += "\tA" + to_string(i - 1) + " -> " + "A" + to_string(i) + "\n";
                output += "\tA" + to_string(i) + " -> " + "A" + to_string(i - 1) + "\n";
            }

            output += "\n\tMt -> U0;\n\tMt -> A0;";

            output += "\n\t{ rank = same; Mt;";

            for(int i = 0; i < col_size; i++){
                output += "A" + to_string(i) + "; ";
            }

            output += "}\n";


            // los nodos del centro

            NodoE<T> **p;
            for(int i = 0; i < row_size; i++){
                for(int j = 0; j < col_size; j++){
                    if(find_col(i, j, p)){
                        output += "\tN" + to_string(j) + "_L" + to_string(i)  + "[label = \"" + to_string((*p)->m_Data) + "\" width = 1.5, group = " + to_string(j + 2) + " ];\n";
                    }
                }
            }


            for(int i=0;i<row_size;i++){
                for(int j=0;j<col_size;j++){
                    NodoE<T> **p;

                    if(find_col(i,j,p)){

                        // si existe un elemento en las filas anteriores
                        for(int desc = 1; desc <= i; desc ++){
                            if(find_col(i - desc, j, p)){
                                output += "\tN" + to_string(j) + "_L" + to_string(i) + " -> N" + to_string(j) + "_L" + to_string(i - desc) + "\n";
                                output += "\tN" + to_string(j) + "_L" + to_string(i - desc) + " -> N" + to_string(j) + "_L" + to_string(i) + "\n";
                                break;
                            }

                            if(desc == i){
                                output += "\tA" + to_string(j) + " -> N" + to_string(j) + "_L"  + to_string(i) + "\n";
                            }
                        }


                        // si existe un elemento en las columnas anteriores

                        for(int desc = 1; desc <= j; desc ++){
                            if(find_row(i, j - desc, p)){
                                output += "\tN" + to_string(j) + "_L" + to_string(i) + " -> N" + to_string(j - desc) + "_L" + to_string(i) + "\n";
                                output += "\tN" + to_string(j - desc) + "_L" + to_string(i) + " -> N" + to_string(j) + "_L" + to_string(i) + "\n";
                                break;
                            }
                            if(desc == j){
                                output += "\tU" + to_string(i) + " -> N" + to_string(j) + "_L"  + to_string(i) + "\n";
                            }

                        }

                    }
                }
            }

            output += "\n}";
            write("sparse.dot",output);
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


#endif // SPARSE_H
