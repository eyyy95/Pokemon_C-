/*********************************************************************
** Program name: Source file for derived Pidgey Object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for derived Pidgey object, which will be one of the opponents that we encounter in this game. Constructor initializes with unique values and attack function is uniquely coded to account for Pidgey's higher critical chance rate
*********************************************************************/
#include"Pidgey.hpp"

Pidgey::Pidgey() //constructor will initialize all member variables with respective values for Pidgey
{
    Attack = 10;
    Defense = 5;
    maxHealth = 36;
    Health = 36;
    pokemonType = 2;
}

void Pidgey::fullRestore() //fully restore pidgey;s health
{
    Health = maxHealth;
}

void Pidgey::battleAttack(Pokemon* opponent) //attack function for pidgey, accepts pointer to opponent Pokemon object
{
    int criticalChance; //integer value for chance to generate critical hit

    criticalChance = rand()%100 + 1;

    int damage, attackDamage, opponentDefense;
    attackDamage = rand()%Attack + 1; //similar to project 3, have attack be similar to die roll using the pokemon's attack

    opponentDefense = rand()%(opponent->getDefense()) + 1;


    damage = attackDamage - opponentDefense;

    if(damage <= 0) //if damage is calculated to be negative, round that up to 0, so that healing is not conducted from an attack
        damage = 0;

    if(criticalChance < 21) //20% chance of inflicting critical hit, which is double damage
    {
        cout << "Pidgey has scored a critical hit!" << endl; //confirm that critical hit was generated
        damage = damage * 2; //double damage
        opponent->inflictDamage(damage); //inflict doubled amount to opponent
    }

    else //inflict normal amount of damage to opponent
        opponent->inflictDamage(damage);
}
