#include <string>

class Student {
  Student();
  Student(std::string schoolName);

private:
  std::string helloStudent();
  std::string schoolName;

public:
  std::string getSchoolName() const;
  void setSchoolName(const std::string& schoolName);
};
