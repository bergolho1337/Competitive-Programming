#include <bits/stdc++.h>

using namespace std;

#define DOG 0
#define CAT 1

class Animal {
protected:
    int type;           // 0 = Dog, 1 = Cat
    int arrival_time;
    string name;
public:
    Animal (const int arrival_time, string name) {
        this->arrival_time = arrival_time;
        this->name = name;
    }
    ~Animal () {}
    void print () {
        printf("Type: %d || Arrival time: %d || Name: %s\n",this->type,this->arrival_time,this->name.c_str());
    }
    string getName () { return this->name; }
    int getArrivalTime () { return this->arrival_time; }
    int getType () { return this->type; }
};

class Dog : public Animal {
public:
    Dog (const int arrival_time, string name) : Animal(arrival_time, name) {
        this->type = 0;
    }
    ~Dog () {}
};

class Cat : public Animal {
public:
    Cat (const int arrival_time, string name) : Animal(arrival_time, name) {
        this->type = 1;
    }
    ~Cat () {}
};

// Question class
class Shelter {
private:
    list<Dog*> dogs;
    list<Cat*> cats;
public:
    Shelter () {}
    ~Shelter () {
        while (!dogs.empty()) {
            dogs.pop_front();
        }
        while (!cats.empty()) {
            cats.pop_front();
        }
    }
    void enqueue (Animal *animal) {
        int type = animal->getType();
        if (type == DOG) {
            dogs.push_back((Dog*)animal);
        }
        else if (type == CAT) {
            cats.push_back((Cat*)animal);
        }
    }
    Animal* dequeueDog () {
        Animal *out = dogs.front();
        dogs.pop_front();
        return out;
    }
    Animal* dequeueCat () {
        Animal *out = cats.front();
        cats.pop_front();
        return out;
    }
    Animal* dequeueAny () {
        if (dogs.empty() && !cats.empty()) {
            return dequeueCat();
        }
        else if (!dogs.empty() && cats.empty()) {
            return dequeueDog();
        }
        else {
            int oldestDog = dogs.front()->getArrivalTime();
            int oldestCat = cats.front()->getArrivalTime();
            Animal *out = nullptr;
            if (oldestDog < oldestCat) {
                out = dogs.front();
                dogs.pop_front();
            }
            else {
                out = cats.front();
                cats.pop_front();
            }
            return out;
        }
    }
    void print () {
        printf("----- DOGS ------ (size = %d)\n",(int)dogs.size());
        for (auto it : dogs) {
            it->print();
        }
        printf("----- CATS ------ (size = %d)\n",(int)cats.size());
        for (auto it : cats) {
            it->print();
        }
    }
};

int main () {

    Dog *dog1 = new Dog(0,"Bud");
    Dog *dog2 = new Dog(1,"Charlie");
    Cat *cat1 = new Cat(2,"Fluffy");
    Cat *cat2 = new Cat(3,"Jasmine");
    Dog *dog3 = new Dog(4,"Vira-lata");
    Cat *cat3 = new Cat(5,"Mimi"); 

    Shelter *s1 = new Shelter();

    s1->enqueue(dog1);
    s1->enqueue(dog2);
    s1->enqueue(cat1);
    s1->enqueue(cat2);
    s1->enqueue(dog3);
    s1->enqueue(cat3);

    s1->print();

    Animal *a1 = s1->dequeueAny();
    Animal *a2 = s1->dequeueAny();
    printf("-------------------------------\n");
    a1->print();
    a2->print();
    printf("-------------------------------\n");

    Animal *a3 = s1->dequeueCat();
    Animal *a4 = s1->dequeueDog();
    printf("-------------------------------\n");
    a3->print();
    a4->print();
    printf("-------------------------------\n");

    s1->print();
    
    delete s1;

    delete dog1;
    delete dog2;
    delete dog3;
    delete cat1;
    delete cat2;
    delete cat3;

    return 0;
}
