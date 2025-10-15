#include <iostream>
#include <string>
#include "../src/Task.h"

void check(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "Error: " << message << std::endl;
        exit(1);
    }
}

void test_constructor() {
    Task t(1, "Estudiar", "Revisar C++");
    check(t.getId() == 1, "ID incorrecto en constructor");
    check(t.getTitle() == "Estudiar", "Titulo incorrecto en constructor");
    check(t.getDescription() == "Revisar C++", "Descripcion incorrecta en constructor");
    std::cout << "Constructor funciona correctamente\n";
}

void test_setters() {
    Task t(2, "Leer", "Capitulo 1");
    t.setTitle("Leer libro");
    t.setDescription("Capitulo 2");
    check(t.getTitle() == "Leer libro", "setTitle() no actualizo correctamente");
    check(t.getDescription() == "Capitulo 2", "setDescription() no actualizi correctamente");
    std::cout << "Setters funcionan correctamente\n";
}

void test_toString() {
    Task t(3, "Correr", "5km");
    std::string s = t.toString();
    check(s.find("Correr") != std::string::npos, "toString() no contiene el titulo esperado");
    check(s.find("5km") != std::string::npos, "toString() no contiene la descripcion esperada");
    std::cout << "toString funciona correctamente\n";
}

int main() {
    test_constructor();
    test_setters();
    test_toString();
    std::cout << "\nTodos los tests pasaron correctamente.\n";
    return 0;
}
