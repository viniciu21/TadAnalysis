#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

#include "../include/Doubly_Linked_List.hpp"
#include "../include/Queue.hpp"

int main() {
    ofstream doublyLinkedListInsertion, queueInsertion, doublyLinkedListDelete, queueDelete;
    //Arquivos de saida
    doublyLinkedListInsertion.open("../data/linkedInsertion.txt");
    queueInsertion.open("../data/insertion/queueInsertion.txt");
    doublyLinkedListDelete.open("../data/delete/linkedDelete.txt");
    queueDelete.open("../data/delete/queueDelete.txt");

    long double linked_insert_values[100], queue_insert_values[100], linked_delete_values[100], queue_delete_values[100];

    short target{10};

    for (size_t index{100}; index < 10000; index += 100) {
        long double doublyLinkedListInsertionSum{0}, queueInsertionSum{0}, doublyLinkedListDeletenSum{0}, queueDeletenSum{0}, doublyLinkedListInsertionAvarege, doublyLinkedListDeleteAvarege, queueInsertionAvarege, queueDeleteAvarege;

        for (int j{0}; j < 100; j++) {
            Doubly_Linked_List *listaLincada = new Doubly_Linked_List();
            queue *fila = new queue(100);

            for (int k{0}; k < 100; k++) {
                auto startChrono = chrono::steady_clock::now();
                listaLincada->insert(target);
                auto endChrono = chrono::steady_clock::now();
                auto timeDifference = endChrono - startChrono;

                linked_insert_values[k] = chrono::duration<long double, std::nano>(timeDifference).count();

                auto startChrono3 = chrono::steady_clock::now();
                fila->enqueue(target);
                endChrono = chrono::steady_clock::now();
                timeDifference = endChrono - startChrono3;

                queue_insert_values[k] = chrono::duration<long double, std::nano>(timeDifference).count();
            }
            for (int z{0}; z < 100; z++) {
                doublyLinkedListInsertionSum += linked_insert_values[z];
                queueInsertionSum += queue_insert_values[z];
            }

            doublyLinkedListInsertionAvarege = doublyLinkedListDeletenSum / 100;
            queueInsertionAvarege = queueInsertionSum / 100;
            doublyLinkedListInsertion << doublyLinkedListInsertionAvarege << " "
                                      << "\n";
            queueInsertion << queueInsertionAvarege << " "
                           << "\n";
            auto startChrono2 = chrono::steady_clock::now();
            listaLincada->removeFirst();
            auto endChrono2 = chrono::steady_clock::now();
            auto timeDifference2 = endChrono2 - startChrono2;
            linked_delete_values[j] = chrono::duration<long double, std::nano>(timeDifference2).count();
            startChrono2 = chrono::steady_clock::now();
            fila->dequeue();
            endChrono2 = chrono::steady_clock::now();
            timeDifference2 = endChrono2 - startChrono2;
            queue_delete_values[j] = chrono::duration<long double, std::nano>(timeDifference2).count();
            delete listaLincada;
            delete fila;
        }
        for (int z = 0; z < 100; z++) {
            doublyLinkedListDeletenSum += linked_delete_values[z];
            queueDeletenSum += queue_delete_values[z];
        }

        doublyLinkedListDeleteAvarege = doublyLinkedListDeletenSum / 100;
        queueDeleteAvarege = queueDeletenSum / 100;

        doublyLinkedListDelete << doublyLinkedListDeleteAvarege << " "
                               << "\n";
        queueDelete << queueDeleteAvarege << " "
                    << "\n";
    }

    return 0;
}
