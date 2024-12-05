#include "student.h"
#include <string>

Student::Student(int id, int age, std::string name, std::string schoolName) : schoolName{schoolName} {};

std::string Student::Student::description() const {
  return "This is Student Class";
}