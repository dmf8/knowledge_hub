#include <string>

struct Claw
{
    Claw();
    Claw(int toes, int count);
    int toes;
    int count;
};

class Animal
{
public:
    Animal(const Animal &a);
    Animal(const std::string &name);
    Animal();

    void showName() const;

private:
    std::string name;
    const int type = 0;
    Claw claw = Claw{2, 2};
};