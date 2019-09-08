// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
#include <math.h>
#include <ctime>

class Warrior
{
  private:
    std::string name;
    int health;
    int attack;
    int block;

    static int numOfWarriors;

  public:
    // Gets the variables but protects the data since the variables is private
    std::string GetName(){return name;}
    void SetName(std::string name){ this->name = name;}
    int GetHealth(){return health;}
    void SetHealth(int health){ this->health = health;}
    int GetAttack(){return attack;}
    int GetBlock(){return block;}
    static int GetNumOfWarriors(){return numOfWarriors;}

    Warrior(std::string, int, int, int);
    Warrior();
    ~Warrior();

    int Attack();
    int Block();
};

// Need to initialize the static int variable before
int Warrior::numOfWarriors=0;

Warrior::Warrior(std::string name, int health, int attack, int block)
{
  this->name = name;
  this->attack = attack;
  this->block = block;
  this->health = health;
  Warrior::numOfWarriors++;
}

Warrior::Warrior()
{
  this->name = name;
  this->attack = attack;
  this->block = block;
  this->health = health;
  Warrior::numOfWarriors++;
}

Warrior::~Warrior()
{
  // std::cout<<"Warrior "<<this->name<<" destroyed\n";
}

int Warrior::Attack()
{
  return std::rand() % ((this->GetAttack()+1));
}

int Warrior::Block()
{
  return std::rand() % ((this->GetBlock()+1));
}


class Battle
{
  public:
    // NOTE: Static things belong to the class not the object!!!!
    // A static method can be invoked without the need for creating an instance of a class
    static void StartFight(Warrior&, Warrior&);
    static void GetAttackResult(Warrior&, Warrior&);
};


// NOTE: While defining the static functions
void Battle::StartFight(Warrior& warrior1, Warrior& warrior2)
{
  // To get the 1 as the attacker first we set it as false so that it becomes the attacker first
  bool attacker1 = false;

  while(warrior1.GetHealth()!=0 && warrior2.GetHealth()!=0)
  {
    attacker1 = !attacker1;
    if(attacker1)
    {
      Battle::GetAttackResult(warrior1, warrior2);
    }
    else
    {
      Battle::GetAttackResult(warrior2, warrior1);
    }
  }

  std::cout<<"Game over!!!\n";

  if(attacker1)
  {
    std::cout<<warrior2.GetName()<<" has died and "<< warrior1.GetName()<< " is Victorious\n";
  }
  else
  {
    std::cout<<warrior1.GetName()<<" has died and "<< warrior2.GetName()<< " is Victorious\n";
  }
}

void Battle::GetAttackResult(Warrior& attacker, Warrior& blocker)
{
  int netAttack = std::max(attacker.Attack()-blocker.Block(),0);
  blocker.SetHealth(std::max(blocker.GetHealth()-netAttack,0));
  std::cout<< attacker.GetName() << " attacks "<< blocker.GetName() <<
    " and deals "<< netAttack << " damage\n" << blocker.GetName() <<
    " is down to "<< blocker.GetHealth() << " health\n";
}

int main()
{
  srand(time(NULL));

  // The warriors have health attack and block
  Warrior thor("Thor", 100, 30, 15);
  Warrior hulk("Hulk", 135, 25, 10);

  Battle::StartFight(thor,hulk);

  return 0;
}
