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

int main() {
    ToDoList list("La mia ToDoList");
    bool end = false;
    int c;
    std::string filename = "todo_list_data.txt";
    list.loadFromFile(filename);
    while (!end) {
        showMenu();
        if (!(cin >> c)) {
            cout << "Imput non valido." << endl;
        }
        cleanInput();
        switch (c) {
            case 1: {
                    try{
                        string description;
                        int day;
                        int month;;
                        int year;
                        cout << "Inserisci descrizione: ";
                        getline(cin, description);
                        cout << "Inserisci data in formato gg mm aaaa: ";
                        cin >> day >> month >> year;
                        Date data(day, month, year);
                        list.addToDo(ToDo(data,description));
                        cout << "ToDo aggiunto correttamente" << endl;
                    }
                    catch (const std::exception& e) {
                        cout << e.what() << endl;
                    }
            break;
            }
            case 2: {
                    try {
                        string description;
                        cout << "Inserisci la descrizione del ToDo da rimuovere: ";
                        getline(cin, description);
                        list.removeToDo(description);
                    }
                    catch (const std::exception& e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
            case 3: {
                    string oldDesc;
                    string newDesc;
                    cout << "Inserisci la descrizione del ToDo da modifcare: ";
                    getline(cin, oldDesc);
                    cout << "Inserisci la nuova descrizione: ";
                    getline(cin, newDesc);
                    try {
                        list.modify(oldDesc,newDesc);
                        cout << "Modifica effettuata correttamente." << endl;
                    }
                    catch (const std::exception& e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
            case 4: {
                    string description;
                    cout << "Inserisci la descrizione del ToDo di cui cambiare stato: ";
                    getline(cin, description);
                    list.ToDoCompleted(description);
                    cout << "Stato modificato (se il ToDo esisteva)." << endl;
                    break;
                }
            case 5: {
                    if (list.totalToDoCount() == 0) {
                        cout << "La lista delle attività è vuota " << endl;
                    }
                    else {
                        cout << "\n************* ELENCO COMPLETO *************" << endl;
                        for (const auto& it : list.getToDoList()) {
                            printToDo(it);
                        }
                        cout << "\n*******************************************" << endl;
                    }
                    break;
                }
            case 6: {
                    auto uncompleted = list.getUncompletedTodo();
                    if (uncompleted.empty()) {
                        cout << "Non hai ToDo in sospeso!" << endl;
                    }
                    else {
                        cout << "\n*** DA COMPLETARE ***" << endl;
                        for (const auto& it : uncompleted) {
                            printToDo(it);
                        }
                        cout << "\n*******************************************" << endl;
                    }
                    break;
                }
            case 7: {
                    string name;
                    cout << "Nome file per il salvataggio (invio per default '" << filename << "'): ";
                    getline(cin, name);
                    if (name.empty()) {
                        name = filename;
                    }
                    try {
                        list.saveToFile(name);
                        cout << "Salvataggio riuscito in " << filename << endl;
                    }
                    catch (const std::exception& e) {
                        cout << "Errore salvataggio: " << e.what() << endl;
                    }
                    break;
                }
        }

    }
}
