#include <string>
#include "person.h"

class Animal;
namespace friend_test
{
    void seeFriend(Animal *a);
}

struct Claw
{
    Claw();
    Claw(int toes, int count);
    int toes;
    int count;
};

class Animal
{
    // friend class Person;
    friend void friend_test::seeFriend(Animal *a);
    friend void Person::showPetName() const;
    friend void Person::showPetType() const;

public:
    Animal(const Animal &a);
    Animal(const std::string &name);
    Animal();

    void showName() const;

protected:
    std::string name;
    Claw claw = Claw{2, 2};

private:
    const int type = 0;
};

class Cat : public Animal
{
    // friend class Person;

public:
    Cat();
};