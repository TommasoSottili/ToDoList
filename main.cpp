#include <iostream>
#include <limits>
#include "ToDoList.h"
#include "ToDo.h"

using namespace std;

void cleanInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}// ripulitura per imput successivi

void printToDo(const ToDo& todo) {
    cout << (todo.isCompleted() ? "[X] " : "[ ] ")
         << todo.getDate() << " _ "
         << todo.getDescription() << endl;
}

void showMenu() {
    cout << "*******************************************************" << endl;
    cout << "                    Lista ToDo                         " << endl;
    cout << "*******************************************************" << endl;
    cout << "Per scegliere un'opzione, digita il numero della scelta corrispondente e premi Invio." << endl;
    cout << "*******************************************************" << endl;
    cout << "1. Aggiungi un ToDo" << endl;
    cout << "2. Rimuovi un ToDo" << endl;
    cout << "3. Modifica la descrizione di un ToDo" << endl;
    cout << "4. Modifica lo stato di un ToDo" << endl;
    cout << "5. Visualizza i ToDo" << endl;
    cout << "6. Visualizza i ToDo non completati" << endl;
    cout << "7. Salva i ToDo su un file" << endl;
    cout << "8. Carica i ToDo da un file" << endl;
    cout << "9. Elimina tutti i ToDo" << endl;
    cout << "0. Termina il programma" << endl;
    cout << "Opzione n: ";
}


