/*********************************************************************
** Program name:Source file for derived Rattata object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for derived Rattata object, which represents the tank opponent of the game. It has higher health, but has lower critical hit chance, which is reflected in the attack function
*********************************************************************/

#include"Rattata.hpp"

Rattata::Rattata() //constructor initializes object with unique respective values
{
    Attack = 14;
    Defense = 6;
    maxHealth = 45;
    Health = 45;
    pokemonType = 3;

}

void Rattata::fullRestore() //fully restore Rattata's health
{
    Health = maxHealth;
}

void Rattata::battleAttack(Pokemon* opponent) //attack function for Rattata object
{
    int criticalChance; //has lower critical chance than Pidgey - 5% compared to 20%

    criticalChance = rand()%100 + 1; //generate random number between 1 and 100

    int damage, attackDamage, opponentDefense;
    attackDamage = rand()%Attack + 1; //similar calculation to project 3 monsters

    opponentDefense = rand()%(opponent->getDefense()) + 1;


    damage = attackDamage - opponentDefense;

    if(damage<= 0) //if damage is calculated to be negative, inflict 0 damage
            damage = 0;

    if(criticalChance < 6) //5% chance of inflicting critical hit, which is double damage
    {
        cout << "Rattata has scored a critical hit!" << endl;
        damage = damage * 2; //double damage
        opponent->inflictDamage(damage); //inflict doubled amount to opponent
    }

    else
        opponent->inflictDamage(damage);
}
