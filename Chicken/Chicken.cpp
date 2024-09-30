#include <iostream>
#include <cstring>

class Chicken
{
private:
    int age = 24;      
    char *name = nullptr;   

public:
    Chicken() {};

    Chicken(int _age) : age(_age) {};

    Chicken(int _age, const char *_name) : age(_age)
    {
        int len = strlen(_name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
            name[i] = _name[i];
    }

    Chicken(const Chicken &other)
    {
        age = other.age;
        if (other.name != nullptr)
        {
            int len = strlen(other.name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = other.name[i];
        }
        else
        {
            name = nullptr;
        }
    }

    Chicken &operator=(const Chicken &other)
    {

        if (this != &other)
        {
            if (name != nullptr)
            {
                delete[] name;
                name = nullptr;
            }

            age = other.age;

            if (other.name != nullptr)
            {
                int len = strlen(other.name) + 1;
                name = new char[len];
                for (int i = 0; i < len; i++)
                    name[i] = other.name[i];
            }
            else
            {
                name = nullptr;
            }
        }
        return *this;
    }

    ~Chicken()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
    }

    void setAge(int _age)
    {
        age = _age;
    }

    void setName(const char *_name)
    {
        if (name != nullptr)
            delete[] name;

        int len = strlen(_name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
            name[i] = _name[i];
    }

    const char *getName() const
    {
        return name;
    }

    const int &getAge() const
    {
        return age;
    }
};
