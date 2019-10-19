/*********************************************************************
** Program name: Source file for Derived Pikachu object
** Author: Edward Yeow
** Date: 3/19/19
** Description: Source file for Derived Pikachu object, which will be our main character's pokemon. Attack function includes chance of randomly killing off the opponent with one attack. Pikachu is the glass cannon character of the game with most potential to deal maximum damage, but lower defense and health. Also can deal double damage to Pidgey, representing Electricity's strength over flying type
*********************************************************************/
#include"Pikachu.hpp"

Pikachu::Pikachu()
{
    Attack = 12; //respective attack and defense values
    Defense = 8;
    Health = 40; //keep track of current health
    maxHealth = 40; //tells functions what Pikachu's max health can be
    pokemonType = 1; //identifier integer

}


void Pikachu::fullRestore()
{
    Health = maxHealth;
}

void Pikachu::battleAttack(Pokemon *opponent) //opponent is parameter and is the one being attacked
{
    int instantDeathChance; //Pikachu has 10% chance of instantly killing the opponent

    instantDeathChance = rand()%100 + 1;

    if(instantDeathChance < 11) //if rand generator generates number between 1-10, call instant death function
        opponent->instantDeath(); //reduces opponent's health to 0

    else
    {
        int damage, attackDamage, opponentDefense;

        attackDamage = rand()%Attack + 1; //randomly generate numbers for attack and defense, similar to project 3 monsters

        opponentDefense = rand()%(opponent->getDefense()) + 1;


        damage = attackDamage - opponentDefense; //calculate damage to be inflicted (attack minus opponent's defense)

        if(damage<= 0) //if damage is calculated to be negative, inflict 0 damage
            damage = 0;

        if(opponent->getType()==2) //inflict double damage to Pidgey; check if opponent is a pidgey
           {
            damage = damage * 2; //double the calculated damage
            opponent->inflictDamage(damage); //inflict to opponent
            }

        else //otherwise, inflict damage as normally calculated
            opponent->inflictDamage(damage);
    }


}

