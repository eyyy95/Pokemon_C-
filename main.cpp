/*********************************************************************
** Program name: Driver Program for Final Project
** Author: Edward Yeow
** Date: 3/19/19
** Description: Our driver program that runs the game of my Final Project. This driver program contains all of the menus involved in game play and uses a switch statement to call on the appropriate functions depending on the type of space the main character lands on, representing interaction with the space
*********************************************************************/
#include<iostream>
#include<cstdlib> //need for exit() and rand() functions
#include<ctime> //needed to seed our program for rand()
#include"map.hpp" //linked space structure that represents our game's map - contains 6 spaces
#include"Space.hpp"
#include"pokemon.hpp" //pokemon base class, and derived classes below
#include"Pikachu.hpp" //need for our main character object
#include"Rattata.hpp"
#include"Pidgey.hpp"
#include"item.hpp"
#include"itemContainer.hpp" //container structure for our items
#include"potionSpace.hpp"
#include"escapeRopeSpace.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{

    unsigned seed; //seed our program so rand() produces different random results each time the program runs
        seed = time(0);
        srand(seed);

  int userChoice;

  //display the goal of the game to the user
  cout << "Welcome to Pokemon Tournament! In this game, you will be playing as the Pokemon Pikachu! there are 6 levels and each level has something for the user, whether it be an item or a Pokemon to battle. There are 2 types of items: 1. Potions - these will help restore your Pikachu's health after battles, and 2. Escape Rope - this item is necessary to finish the game after defeating the final boss, but there is a chance you may encounter this item early, and you will win when you do! Once you reach the last level, and beat the final boss, you win! If your PIkachu runs out of health before this happens though, you lose! " << endl;
  cout << "What would you like to do?" << endl; //First menu - would they like to play or exit
  cout << "1. Start Game." << endl;
  cout << "2. Exit." << endl;
  cin >> userChoice;

    while(1) //User validation that prevents the input of non-integer data
            {
                if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout<< "You have entered invalid input data type. Please enter an integer" <<endl;
                        cin>> userChoice;
                    }
                if(!cin.fail())
                    break;
            }

        while(userChoice < 1 || userChoice > 2) //Limits user to inputting numbers between 1 and 2, consistent with available choices
            {
                cout << "Invalid option. Please select between options 1 and 2.";
                cin >> userChoice;
            }

  if(userChoice == 2)
    {
      exit(1); //call exit function to terminate program if user chooses that they don't want to play
    }

  else
     {
          Map sampleMap; //initialize our linked space object
          itemContainer potionBag; //initialize container to hold potions
          itemContainer escapeRopeBag; //separate container to hold escape rope. If this is full, the player automatically wins
          Pokemon* mainCharacter; //pointer to the main character object
          Pokemon* opponent; //pointer that will point to the opponent pokemon encountered on pokemon spaces. Will change with every different pokemon space
          mainCharacter = new Pikachu(); //create main character object with polymorphic constructor
          int currentSpaceNumber = 1;

          potionBag.addPotion(); //start the user off with 1 potion

          cout << "Welcome to the game Pikachu! Your task is to win this tournament! There are 6 levels to get through, and each level either has a Pokemon you will face, or an item you can keep! Let's get started!" << endl;
    //Welcome message to confirm starting of the game
        while(mainCharacter->checkFaint()!= true) //as long as the main character has not fainted from depleted health, continue running the program
        {

            if(escapeRopeBag.isEmpty() == false) //if the player has found the escape rope - print that they have won the game and exit
            {
                cout << "Congratulations! You have found the escape rope and defeated all the Pokemon! You win!" << endl;
                exit(1);
            }

            int currentSpaceType, currentSpaceNumber; //integers to hold our current location and the type of the space the player is currently on

            currentSpaceType = sampleMap.getCurrentSpace()->getSpaceType(); //first analyze what kind of space you are on
            cout << "Current space: " << currentSpaceNumber+1 << endl;

            switch(currentSpaceType) //call on the respective functions based on what type of space the player lands on
            {
            case 1: //Space Type 1 is for the abstract class Pokemon Space - will never encounter this
                break;
            case 2: //Space Type 2 is for space containing a Pidgey
                opponent = sampleMap.getCurrentSpace()->getSpacePokemon(); //have opponent pointer point to the Pidgey residing on the space
                cout << "You have encountered a Pidgey! Battle it to defeat it!" << endl; //confirm the player's encounter
                while(mainCharacter->checkFaint() == false) //as long as the player has not fainted, run the battle
                {
                    if(opponent->checkFaint() == true) //if the opponent faints, break this battle loop
                        break;

                    cout << "Pikachu's Health: " << mainCharacter->getHealth() << endl; //Display both Pokemon's health; Pikachu's health serves as the step limit in this game
                    cout << "Pidgey's Health: " << opponent->getHealth() << endl;

                    int battleChoice; //Menu to allow user to either attack opponent pokemon or heal their main character
                    cout << "What will you do?" << endl;
                    cout << "1. Attack!" << endl;
                    cout << "2. Use potion!" << endl;
                    cin >> battleChoice;
                    while(1) //User validation that prevents the input of non-integer data
                        {
                            if(cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1000,'\n');
                                    cout<< "You have entered invalid input data type. Please enter an integer" <<endl;
                                    cin>> battleChoice;
                                }
                            if(!cin.fail())
                                break;
                        }

                    while(battleChoice < 1 || battleChoice > 2) //Limits user to inputting numbers between 1 and 2, consistent with available choices
                        {
                            cout << "Invalid option. Please select between options 1 and 2.";
                            cin >> battleChoice;
                        }



                    switch(battleChoice) //switch menu to either have character attack opponent, or heal the main character
                    {
                    case 1:
                        cout << "Pikachu attacked Pidgey!" << endl;
                        mainCharacter->battleAttack(opponent); //call on attack function for main character and have opponent be the parameter
                        if(opponent->checkFaint()==true) //check if opponent has fainted after the attack
                            {
                                cout << "The Pidgey fainted!" << endl;
                                break;
                            }
                        cout << "Pidgey attacked Pikachu!" << endl;
                        opponent->battleAttack(mainCharacter); //have opponent attack main character
                        if(mainCharacter->checkFaint()==true)// check if main character has fainted after the attack
                        {
                            cout << "Pikachu fainted! Game over!" << endl;
                            exit(1); //if main character dies, the game is over, so exit will terminate the program to ensure it's over
                        }
                        break;

                    case 2: //If user chooses to restore their character pokemon. If they choose this attack, they give up their attack and the opponent will attack regardless
                        if(potionBag.isEmpty() == true) //check if potion bag container is empty
                            {
                            cout << "You don't have any potions to use!" << endl; //Inform user that their potion bag is empty
                            cout << "Pidgey attacked Pikachu!" << endl; //Opponent will attack main character
                            opponent->battleAttack(mainCharacter); //check if main character has fainted after attack
                            if(mainCharacter->checkFaint()==true)
                                {
                                    cout << "Pikachu fainted! Game over!" << endl;
                                    exit(1);
                                }

                            }
                        else
                        {
                            mainCharacter->restoreHealth(20); //if user does have potions, we will restore main character's health by 20
                            potionBag.removeItem(); //then remove a potion from container to symbolize the use of 1 potion
                            cout << "Pidgey attacked Pikachu!" << endl; //have opponent attack main character
                            opponent->battleAttack(mainCharacter);
                            if(mainCharacter->checkFaint()==true) //check if main character has fainted
                            {
                                cout << "Pikachu fainted! Game over!" << endl;
                                exit(1);
                            }

                        }
                        break;


                    }

                } //after the battle has been completed without character fainting, ask if the user wants to continue playing
                cout << "What would you like to do?" << endl;
                cout << "1. Move forward" << endl;
                cout << "2. Exit. " << endl;
                cin >> userChoice;
                while(1) //User validation that prevents the input of non-integer data
                        {
                            if(cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1000,'\n');
                                    cout<< "You have entered invalid input data type. Please enter an integer" <<endl;
                                    cin>> userChoice;
                                }
                            if(!cin.fail())
                                break;
                        }

                    while(userChoice < 1 || userChoice > 2) //Limits user to inputting numbers between 1 and 5, consistent with available choices
                        {
                            cout << "Invalid option. Please select between options 1 and 2.";
                            cin >> userChoice;
                        }
                if(userChoice == 2)
                    exit(1);
                else
                    sampleMap.moveForward(); //move forward on the map, using the space's next pointer
                    mainCharacter->inflictDamage(2); //have Pikachu take 2 points of damage after each step, indicating fatigue
                    currentSpaceNumber = currentSpaceNumber + 1; //increment space number so that next step's location is accurate
                break;
            case 3: //if user encounters a Rattata space. Same logic as case 2, but with opponent pointer pointing to Rattata object

                opponent = sampleMap.getCurrentSpace()->getSpacePokemon();
                cout << "You have encountered a Rattata! Battle it to defeat it!" << endl;
                while(mainCharacter->checkFaint() == false || opponent->checkFaint()== false)
                {
                    if(opponent->checkFaint() == true)
                        break;

                    cout << "Pikachu's Health: " << mainCharacter->getHealth() << endl;
                    cout << "Rattata's Health: " << opponent->getHealth() << endl;

                    int battleChoice;
                    cout << "What will you do?" << endl;
                    cout << "1. Attack!" << endl;
                    cout << "2. Use potion!" << endl;
                    cin >> battleChoice;
                    while(1) //User validation that prevents the input of non-integer data
                        {
                            if(cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1000,'\n');
                                    cout<< "You have entered invalid input data type. Please enter an integer" <<endl;
                                    cin>> battleChoice;
                                }
                            if(!cin.fail())
                                break;
                        }

                    while(battleChoice < 1 || battleChoice > 2) //Limits user to inputting numbers between 1 and 5, consistent with available choices
                        {
                            cout << "Invalid option. Please select between options 1 and 2.";
                            cin >> battleChoice;
                        }

                    switch(battleChoice)
                    {
                    case 1:
                        cout << "Pikachu attacked Rattata!" << endl;
                        mainCharacter->battleAttack(opponent);
                        if(opponent->checkFaint()==true)
                            {
                                cout << "The Rattata fainted!" << endl;
                                break;
                            }
                        cout << "Rattata attacked Pikachu!" << endl;
                        opponent->battleAttack(mainCharacter);
                        if(mainCharacter->checkFaint()==true)
                        {
                            cout << "Pikachu fainted! Game over!" << endl;
                            exit(1);
                        }
                        break;

                    case 2:
                        if(potionBag.isEmpty() == true)
                            {
                            cout << "You don't have any potions to use!" << endl;
                            opponent->battleAttack(mainCharacter);
                            cout << "Rattata attacked Pikachu!" << endl;
                            if(mainCharacter->checkFaint()==true)
                            {
                                cout << "Pikachu fainted! Game over!" << endl;
                                exit(1);
                            }
                            break;
                            }
                        else
                        {
                            cout << "You used a potion!" << endl;
                            mainCharacter->restoreHealth(20);
                            potionBag.removeItem();
                            cout << "Rattata attacked Pikachu!" << endl;
                            opponent->battleAttack(mainCharacter);
                            if(mainCharacter->checkFaint()==true)
                            {
                                cout << "Pikachu fainted! Game over!" << endl;
                                exit(1);
                            }
                            break;
                        }


                    }

                }
                cout << "What would you like to do?" << endl;
                cout << "1. Move forward" << endl;
                cout << "2. Exit. " << endl;
                cin >> userChoice;
                while(1) //User validation that prevents the input of non-integer data
                        {
                            if(cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1000,'\n');
                                    cout<< "You have entered invalid input data type. Please enter an integer" <<endl;
                                    cin>> userChoice;
                                }
                            if(!cin.fail())
                                break;
                        }

                    while(userChoice < 1 || userChoice > 2) //Limits user to inputting numbers between 1 and 5, consistent with available choices
                        {
                            cout << "Invalid option. Please select between options 1 and 2.";
                            cin >> userChoice;
                        }
                if(userChoice == 2)
                    exit(1);
                else
                    sampleMap.moveForward();
                    mainCharacter->inflictDamage(2);
                    currentSpaceNumber = currentSpaceNumber + 1;
                break;

            case 4: //WHen user lands on space containing a potion
                  cout << "You have found a potion!" << endl; //inform user that they found a potion
                  potionBag.addPotion(); //add a potion item to the container
                  cout << "What would you like to do?" << endl; //Ask if the user would like to proceed
                cout << "1. Move forward" << endl;
                cout << "2. Exit. " << endl;
                cin >> userChoice;
                while(1) //User validation that prevents the input of non-integer data
                        {
                            if(cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1000,'\n');
                                    cout<< "You have entered invalid input data type. Please enter an integer" <<endl;
                                    cin>> userChoice;
                                }
                            if(!cin.fail())
                                break;
                        }

                    while(userChoice < 1 || userChoice > 2) //Limits user to inputting numbers between 1 and 2, consistent with available choices
                        {
                            cout << "Invalid option. Please select between options 1 and 2.";
                            cin >> userChoice;
                        }
                if(userChoice == 2)
                    exit(1);
                else
                    sampleMap.moveForward();
                    mainCharacter->inflictDamage(2); //fatigue damage to the character
                    currentSpaceNumber = currentSpaceNumber + 1;
                break;
            case 5: //if user lands on space containing escape rope item
                cout << "You found an escape rope!" << endl; //inform user what they have found
                escapeRopeBag.addEscapeRope(); //add escape rope item to the escape rope container
                break;


            }
        }


     }

return 0;
}
