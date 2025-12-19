class Person
{
public:
    Person(int age);
    Person();
    Person(const Person &p);

    void func() const;
    void func2(const Person &p) const;

private:
    int age;
};
