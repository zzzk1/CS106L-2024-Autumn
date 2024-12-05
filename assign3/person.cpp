#include<string>
#include<person.h>

Person::Person() {
    this->id = 1;
    this->age = 1;
    this->name = "Default";
}

Person::Person(int id, int age, std::string name) : id{id}, age{age}, name{name} {};