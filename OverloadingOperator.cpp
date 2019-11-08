#include <iostream>

using namespace std;

class Operators
{
private:
    int p_age;
    string p_name;
public:
    Operators();
    Operators(int a, string b);; //Constructor

    //Operators(const Operators& other) = delete;
    //^^if we dont want copy constructor, we can delete it like that

    Operators(const Operators& other) : p_age(other.p_age), p_name(other.p_name) //Copy constructor
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Operators& data);
    // ^^^Przeci¹zenie operatorow "Overloading operators"



    ~Operators()
    {
        std::cout << "Destruction of object" << std::endl;
    }
    //^^Destruktor

};

std::ostream& operator<<(std::ostream& out, const Operators& data) //Overloiading operator <<
{
    out <<  data.p_age << std::endl;
    out <<  data.p_name << std::endl;
    return out;
}

Operators::Operators()
{
    std::cout << "Constructor of object (default)" << std::endl;
    p_age = 5;
    p_name = "Adam";
}

Operators::Operators(int a, string b)
{
    std::cout << "Constructor of object (With parameters)" << std::endl;
    p_age = a;
    p_name = b;
}

void print()
{
    Operators test1(5, "so");
    Operators test2(10000, "Ewa");
    Operators test;

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;
    std::cout << test << std::endl;
}

int main()
{

    print();

    return 0;
}
