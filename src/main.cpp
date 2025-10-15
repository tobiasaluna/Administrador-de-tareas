#include <iostream>
#include <vector>
#include <fstream>
#include "Task.h"

std::vector<Task> tasks;
int nextId = 1;

void loadTasks() {
    std::ifstream file("data/tasks.txt");
    if (!file) return;
    int id;
    std::string title, desc;
    while (file >> id) {
        file.ignore();
        std::getline(file, title);
        std::getline(file, desc);
        tasks.push_back(Task(id, title, desc));
        if (id >= nextId) nextId = id + 1;
    }
}

void saveTasks() {
    std::ofstream file("data/tasks.txt");
    for (const auto &t : tasks) {
        file << t.getId() << "\n" << t.getTitle() << "\n" << t.getDescription() << "\n";
    }
}

void addTask() {
    std::string title, desc;
    std::cout << "Título: "; std::getline(std::cin, title);
    std::cout << "Descripción: "; std::getline(std::cin, desc);
    tasks.push_back(Task(nextId++, title, desc));
    saveTasks();
}

void listTasks() {
    for (const auto &t : tasks) {
        std::cout << t.toString() << std::endl;
    }
}

int main() {
    loadTasks();
    int choice;
    do {
        std::cout << "\n1. Agregar tarea\n2. Listar tareas\n0. Salir\nElige: ";
        std::cin >> choice; std::cin.ignore();
        if (choice == 1) addTask();
        else if (choice == 2) listTasks();
    } while (choice != 0);
}
