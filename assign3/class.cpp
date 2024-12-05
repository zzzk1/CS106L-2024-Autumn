#include "class.h"
#include <string>

Student::Student() {

}
Student::Student(std::string schoolName)
    : schoolName{schoolName} {};

std::string Student::Student::helloStudent() {
  return "";
}

std::string Student::getSchoolName() const { return this->schoolName; }
void Student::setSchoolName(const std::string& schoolName) {
  this->schoolName = schoolName;
}