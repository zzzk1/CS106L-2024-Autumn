#include <string>

class Person {
protected:
  int id;
  int age;
  std::string name;

Person();
Person(int id, int age, std::string name);

public:
  int getId() const;
  int getAge() const;
  std::string getName() const;
  void setId(int id);
  void setAge(int age);
  void setName(std::string name);

  virtual std::string description() const = 0;
};