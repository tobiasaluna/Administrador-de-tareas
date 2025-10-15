#ifndef TASK_H
#define TASK_H
#include <iostream>

class Task {
    private:
        int id;
        std::string title;
        std::string description;
    public:
        Task(int id, std::string title, std::string description);
        int getId() const;
        std::string getTitle() const;
        std::string getDescription() const;
        void setTitle(const std::string &newTitle);
        void setDescription(const std::string &newDesc);
        std::string toString() const;
};


#endif 
