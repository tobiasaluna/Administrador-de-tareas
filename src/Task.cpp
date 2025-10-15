#include "Task.h"
#include <sstream>

Task::Task(int id, std::string title, std::string description)
    : id(id), title(title), description(description) {}

int Task::getId() const { return id; }
std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
void Task::setTitle(const std::string &newTitle) { title = newTitle; }
void Task::setDescription(const std::string &newDesc) { description = newDesc; }

std::string Task::toString() const {
    std::stringstream ss;
    ss << "ID: " << id << " | " << title << " - " << description;
    return ss.str();
}
