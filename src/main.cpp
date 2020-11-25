#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

#include "../include/Doubly_Linked_List.hpp"
#include "../include/Queue.hpp"

int main() {

    ofstream doublyLinkedListInsertion, queueInsertion, doublyLinkedListDelete, queueDelete;

    //  Arquivos de saida
    doublyLinkedListInsertion.open("../data/insertion/linkedInsertion.txt");
    queueInsertion.open("../data/insertion/queueInsertion.txt");
    doublyLinkedListDelete.open("../data/delete/linkedDelete.txt");
    queueDelete.open("../data/delete/queueDelete.txt");

    //  Vetores para armazenar os tempos de execução por grupo de amostra
    long double linked_insert_values[100], queue_insert_values[100], linked_delete_values[100], queue_delete_values[100];

    for (size_t index{100}; index <= 1000; index += 100) {

        // Variáveis para guardar os tempos de exeução de inserção na lista duplamente encadeada
        long double doublyLinkedListInsertionSum{0}, doublyLinkedListInsertionAvarege;

        // Variáveis para guardar os tempos de exeução de remoção na lista duplamente encadeada
        long double doublyLinkedListDeleteSum{0}, doublyLinkedListDeleteAvarege;

        // Variáveis para guardar os tempos de exeução de inserção na fila
        long double queueInsertionSum{0}, queueInsertionAvarege;

        // Variáveis para guardar os tempos de exeução de remoção na fila
        long double queueDeleteSum{0}, queueDeleteAvarege;
        

        //  Começa a rodada de execução da amostra de tamanho N para inserção
        for (int j{0}; j < 50; j++) {

            //  Instancia e preenche a lista para que tenha o tamanho N
            Doubly_Linked_List *LinkedList = new Doubly_Linked_List();
            for (size_t i = 0; i < index; i++)
                LinkedList->insert(0);

            //  Instancia a fila
            queue *fila = new queue(index);

            //  Calcula o tempo de execução da inserção na lista duplamente encadeada
            auto startChrono = chrono::steady_clock::now();
            LinkedList->insert(10);
            auto endChrono = chrono::steady_clock::now();
            auto timeDifference = endChrono - startChrono;

            linked_insert_values[j] = chrono::duration<long double, std::nano>(timeDifference).count();

            //  Calcula o tempo de execução da inserção na fila
            startChrono = chrono::steady_clock::now();
            fila->enqueue(10);
            endChrono = chrono::steady_clock::now();
            timeDifference = endChrono - startChrono;

            queue_insert_values[j] = chrono::duration<long double, std::nano>(timeDifference).count();

                
            //  Calcula o tempo de execução da remoção na lista duplamente encadeada
            startChrono = chrono::steady_clock::now();
            LinkedList->removeFirst();
            endChrono = chrono::steady_clock::now();
            timeDifference = endChrono - startChrono;

            linked_delete_values[j] = chrono::duration<long double, std::nano>(timeDifference).count(); 

            //  Calcula o tempo de execução da remoção na fila
            startChrono = chrono::steady_clock::now();
            fila->dequeue_all();
            endChrono = chrono::steady_clock::now();
            timeDifference = endChrono - startChrono;

            queue_delete_values[j] = chrono::duration<long double, std::nano>(timeDifference).count();
            
            delete LinkedList;
            delete fila;
        }

        //  Calcula média de tempo de inserção e remoção na lista e na fila para o tamanho N
            for (int z{0}; z < 100; z++) {
                doublyLinkedListInsertionSum += linked_insert_values[z];
                doublyLinkedListDeleteSum += linked_delete_values[z];
                queueInsertionSum += queue_insert_values[z];
                queueDeleteSum += queue_delete_values[z];
            }

            doublyLinkedListInsertionAvarege = doublyLinkedListInsertionSum / 50;
            doublyLinkedListDeleteAvarege = doublyLinkedListDeleteSum / 50;
            queueInsertionAvarege = queueInsertionSum / 50;
            queueDeleteAvarege = queueDeleteSum / 50;

            //  Insere o tempo médio de inserção e remoção na lista e na fila nos seus respectivos arquivos de saída
            doublyLinkedListInsertion << doublyLinkedListInsertionAvarege << " " << "\n";
            doublyLinkedListDelete << doublyLinkedListDeleteAvarege << " " << "\n";
            queueInsertion << queueInsertionAvarege << " " << "\n";
            queueDelete << queueDeleteAvarege << " " << "\n";

    }

    doublyLinkedListInsertion.close();
    queueInsertion.close();
    doublyLinkedListDelete.close();
    queueDelete.close();

    return 0;
}
