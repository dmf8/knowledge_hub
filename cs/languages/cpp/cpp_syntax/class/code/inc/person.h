#ifndef PERSON_H
#define PERSON_H

class Animal;

class Person
{
public:
    Person(int age);
    Person();
    Person(const Person &p);
    ~Person();

    void func() const;
    void func2(const Person &p) const;

    // friend
    void setPet(Animal *a);
    void showPetName() const;
    void showPetType() const;

private:
    int age;
    Animal *pet = nullptr;
};

#endif
