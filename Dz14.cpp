#include <iostream>
#include <Windows.h>
using namespace std;

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base(T1 valueP1, T2 valueP2) : value1(valueP1), value2(valueP2) {}

    virtual ~Base() {}

    void printBase() const {
        cout << "1 значення: " << value1 << "\n2 значення: " << value2;
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child(T1 valueP1, T2 valueP2, T3 valueP3, T4 valueP4) : Base<T1, T2>(valueP1, valueP2), value3(valueP3), value4(valueP4) {}

    ~Child() {}

    void printChild() const {
        this->printBase();
        cout << "\n3 значення: " << value3 << "\n4 значення: " << value4;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
private:
    T5 value5;
    T6 value6;

public:
    Child2(T1 valueP1, T2 valueP2, T3 valueP3, T4 valueP4, T5 valueP5, T6 valueP6) : Child<T1, T2, T3, T4>(valueP1, valueP2, valueP3, valueP4), value5(valueP5), value6(valueP6) {}

    ~Child2() {}

    void printChild2() const {
        this->printChild();
        cout << "\n5 значення: " << value5 << "\n6 значення: " << value6 << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Перевірка Base: " << endl;
    Base <int, string> base(17, "котик");
    base.printBase();

    cout << endl;

    cout << "Перевірка Child: " << endl;
    Child<string, double, char, int> child("песик", 10.5, '=', 11);
    child.printChild();

    cout << endl;

    cout << "Перевірка Child2: " << endl;
    Child2<int, bool, char, string, double, bool> child2(10, false, 'A', "папуга", 1.2, true);
    child2.printChild2();

    return 0;
}
