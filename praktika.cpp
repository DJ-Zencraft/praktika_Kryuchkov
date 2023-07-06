#include <iostream>

using std::cout;

class Twix {
public:
    virtual void info() = 0;
    virtual ~Twix() {} // деструктор
};

class Left_Stick :public Twix {
public:
    void info() {
        cout << "You chose the right stick!\n"; 
    }
};

class Right_Stick :public Twix {
public:
    void info() {
        cout << "You chose the left stick!\n";
    }
};


/*Создаём руководящий класс*/
class Factory {
public:
    virtual Twix* Create() = 0; //Чистая виртуальная функция показывает, что в производстве будет метод Create
    virtual ~Factory() {}  //Виртуальный деструктор
};


class Left_StickFactory :public Factory {
public:
    Twix* Create() {
        return new Left_Stick; 
    }
};

class Right_StickFactory :public Factory {
public:
    Twix* Create() {
        return new Right_Stick;
    }
};


Twix* foo(Factory* value) {
    return value->Create();
}

void Chose()
{
    cout << "Choose a twix stick: left or right?\n (type l or r)\n";
}

////////////////////////////
int main() {
    Left_StickFactory Left_Stick;         
    Right_StickFactory Right_Stick;

    Factory* ptr1 = &Left_Stick;  
    Factory* ptr2 = &Right_Stick;

    Twix* ObjectTwix1 = foo(ptr1); 
    Twix* ObjectTwix2 = foo(ptr2); 

    Chose();
    
    char a;
    std::cin >> a;
    switch (a)
    {
    case 'r':
            ObjectTwix1->info();
            break;
    case 'l':
            ObjectTwix2->info();
            break;

    default:
        cout << "Something is wrong with the code!";
        break;
    }

    delete ObjectTwix1, delete ObjectTwix2; //Чистка памяти 

}