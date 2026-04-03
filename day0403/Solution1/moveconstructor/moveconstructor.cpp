#include <iostream>
#include <string>
using namespace std;

class Human {
private:
    string name;
    int age;
public:
    Human(const string& n, int a) : name(n), age(a) {
        cout << "생성자" << endl;
    }

    void viewHuman() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

int main() {
    Human h("홍길동", 100);
    h.viewHuman();

    Human h2(h);
    h2.viewHuman();

    Human h3(h);
    h3.viewHuman();

    return 0;
}