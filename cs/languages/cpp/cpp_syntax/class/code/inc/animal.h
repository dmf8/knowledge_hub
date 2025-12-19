#include <string>

class Animal
{
public:
    Animal(const Animal &a);
    Animal() = default;

    void showName() const;

private:
    std::string name;
};