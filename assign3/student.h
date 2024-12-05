#include <string>
#include <person.h>

class Student : public Person {
  Student(int id, int age, std::string name, std::string schoolName);

private:
  std::string helloStudent();
  std::string schoolName;
public:
  std::string description() const;
};
