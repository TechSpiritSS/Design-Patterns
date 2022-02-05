#include <iostream>
using namespace std;

class FlyBehavior
{
public:
    virtual ~FlyBehavior() {}
    virtual void fly() = 0;
};

class QuackBehavior
{
public:
    virtual ~QuackBehavior() {}
    virtual void quack() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly()
    {
        cout << "I'm flying with wings!" << endl;
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly()
    {
        cout << "I can't fly!" << endl;
    }
};

class Quack : public QuackBehavior
{
public:
    void quack()
    {
        cout << "Quack!" << endl;
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack()
    {
        cout << "Squeak!" << endl;
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack()
    {
        cout << "<< Silence >>" << endl;
    }
};

class Duck
{
private:
    FlyBehavior *fly;
    QuackBehavior *quack;

public:
    Duck(FlyBehavior *fly, QuackBehavior *quack)
    {
        this->fly = fly;
        this->quack = quack;
    }
    virtual ~Duck() {}
    void swim()
    {
        cout << "All ducks float, even decoys!" << endl;
    }

    virtual void display() = 0;

    void performFly()
    {
        fly->fly();
    }
    void performQuack()
    {
        quack->quack();
    }
    void setFlyBehavior(FlyBehavior *fly)
    {
        this->fly = fly;
    }
    void setQuackBehavior(QuackBehavior *quack)
    {
        this->quack = quack;
    }
};

class MallardDuck : public Duck
{
public:
    MallardDuck() : Duck(new FlyWithWings, new Quack) {}
    void display()
    {
        cout << "I'm a real Mallard duck" << endl;
    }
};

class ModelDuck : public Duck
{
public:
    ModelDuck() : Duck(new FlyNoWay, new MuteQuack) {}
    void display()
    {
        cout << "I'm a model duck" << endl;
    }
};

class RubberDuck : public Duck
{
public:
    RubberDuck() : Duck(new FlyNoWay, new Squeak) {}
    void display()
    {
        cout << "I'm a rubber duck" << endl;
    }
};

class DecoyDuck : public Duck
{
public:
    DecoyDuck() : Duck(new FlyNoWay, new MuteQuack) {}
    void display()
    {
        cout << "I'm a decoy duck" << endl;
    }
};

class DuckSimulator
{
public:
    static void simulate(Duck *duck)
    {
        duck->display();
        duck->performFly();
        duck->performQuack();
        duck->swim();
    }
};

class DuckFactory
{
public:
    static Duck *createDuck(int type)
    {
        Duck *duck = NULL;
        switch (type)
        {
        case 1:
            duck = new MallardDuck();
            break;
        case 2:
            duck = new ModelDuck();
            break;
        case 3:
            duck = new RubberDuck();
            break;
        case 4:
            duck = new DecoyDuck();
            break;
        default:
            break;
        }
        return duck;
    }
};
