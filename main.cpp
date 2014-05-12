#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Weapon.cpp"
#include "Player.cpp"
#include "Weapon.h"
#include "Player.h"

using namespace std;


typedef enum states{intro, weapon_choice, chck_encounter, enemymake,
	encount_gen, event_gen,enemy1, enemy2, enemy3, boss1, boss2, boss3,
	event1,	event2, event3,fight1, fight2, fight3, easy_fight,
	mid_fight, hard_fight, empty, gameover, victory, winfight, bossState};

int random(int numb)//function for random numbers
{
	int rand_gen = (rand()% numb) + 1;
	return rand_gen;
}

int damage(int ppower, int epower)//function for caclulation battle damage
{
	int dealt = abs(int((((ppower*0.6) - (epower*0.4))(random(5)))));
	return dealt;
}

int main()
{
	Player player1("player1");//player object
	Player bandit("bandit");//enemy player objects
	Player bounty_hunter("bounty_hunter");
	Player hitman("hitman");
	Player boss("boss");
	string BOG;//input strings
	string pinput;
	string pinput2;
	int courage = 3;//count of character courage
	int lives = 2;//number of lives per game
	int playerlvl = 1;//player starting level
	int bosscount = 0;//count for boss encouter
	int wincount = 0;//count for number of wins
	int bstat;

	states test = intro;
	while(test != empty)
	{
	switch(test)
	{
		case intro://introduction case
		{
			cout << "Welcome to Choice" << endl;
			cout << "A game where you will have to make choices" << endl;
			cout << "Choose: boy or girl?" << endl;
			cin >> BOG;
			cout << "Choose a name:" << endl;
			cin >> pinput;
			player1.setP_Name(pinput);
			test = weapon_choice;
			break;
		}

		case weapon_choice://player chooses weapon and recieves base stats for game
		{
			cout << "Choose: pistols, shotgun, rifle, or crossbow" << endl;
			cin >> pinput2;
			while((pinput2 != "pistols") || (pinput2 != "shotgun")||(pinput2 != "rifle")||(pinput2 != "crossbow"))
			{
				cout << "Choose: pistols, shotgun, rifle, or crossbow" << endl;
				cin >>pinput2;
			}
			if (pinput2 == "pistols")
			{
				player1.setP_Power(4);
				player1.setP_Accuracy(3);
				player1.setP_Agility(10);
			}
			if(pinput2 == "shotgun")
			{
				player1.setP_Power(10);
				player1.setP_Accuracy(4);
				player1.setP_Agility(2);
			}
			if(pinput2 == "rifle")
			{
				player1.setP_Power(6);
				player1.setP_Accuracy(7);
				player1.setP_Agility(8);
			}
			if(pinput2 == "crossbow")
			{
				player1.setP_Power(5);
				player1.setP_Accuracy(10);
				player1.setP_Agility(3);
			}
			test = enemymake;
			break;
		}

		case enemymake: /*randomly pick between weak, medium, and strong enemy*/
		{
			if((playerlvl == 10)||(playerlvl == 18)||(playerlvl ==25))
			{
				test = bossState;
				break;
			}
			int m = random(playerlvl);
			if((m >= 1)&&(m < 10))
			{
				test = enemy1;
				break;
			}
			if((m > 10)&&(m < 18))
			{
				test = enemy2;
				break;
			}
			if((m > 18)&&(m < 25))
			{
				test = enemy3;
				break;
			}
		}
		case enemy1:/*create weak enemy*/
		{
			int randstat = random(1);
			
			if(randstat == 0)
			{
				bandit.setAgility(player1.getAgility() - 1);
				bandit.setPower(player1.getPower() - 1);
			}	bandit.setAccuracy(player1.getAccuracy() - 1);

			else if(randstat == 1)
			{
				bandit.setAgility(player1.getAgility() + 1);
				bandit.setPower(player1.getPower() + 1);
				bandit.setAccurcay(player1.getAccuracy() + 1);
			}
			test = fight1;
			break;
		}
		case enemy2:/*create medium enemy*/
		{
			int randchck = random(1);
			int ranstat = random(5);
			if(randchck == 0)
			{
				bounty_hunter.setAgility(player1.getAgility() - randstat);
				bounty_hunter.setPower(player1.getPower() - randstat);
				bounty_hunter.setAccuracy(player1.getAccuracy() - randstat);
			}
			else if(randchck == 1)
			{
				bounty_hunter.setAgility(player1.getAgility() + randstat);
				bounty_hunter.setPower(player1.getPower() + randstat);
				bountyhunter.setAccurcay(player1.getAccuracy() + randstat);
			}
			test = fight2;
			break;
		}
		case enemy3://create strong enemy
		{
			int randchck = random(1);
			int ranstat = random(8);
			if(randchck == 0)
			{
				hitman.setAgility(player1.getAgility() - randstat);
				hitman.setPower(player1.getPower() - randstat);
				hitman.setAccuracy(player1.getAccuracy() - randstat);
			}
			else if(randchck == 1)
			{
				hitman.setAgility(player1.getAgility() + randstat);
				hitman.setPower(player1.getPower() + randstat);
				hitman.setAccurcay(player1.getAccuracy() + randstat);
			}
			test = fight3;
			break;
		}
		case fight1://fight against weak enemy
		{
			cout << "You have encountered a bandit" << endl;
			cout << "Choose: fight or run" << endl;
			cin >> pinput2;
			while((pinput2 != "fight")||(pinput2 != "run"))
			{
				cout << "Choose: fight or run" << endl;
				cin >> pinput2;
			}
			if(pinput2 == "fight")
			{
				int phealth = 100;
				int ehealth = 100;
				while((phealth >= 0) ||(ehealth >= 0))
				{
					if(player1.getAgility() >  bandit.getAgility())
					{
						int dealt = damage(player1.getPower(), bandit.getPower());
						ehealth = ehealth - dealt;
						if(ehealth <= 0)
						{
							test = winfight;
							break;
						}
						else
						{
							cout << "You dealt damage." << "The bandit has " << ehealth << " health left" << endl;
							int edealt = damage(bandit.getPower(), player1.getPower());
							phealth = phealth - edealt;
							cout << "The bandit dealt damage." << "You have " << phealth << " health left" << endl;
						}
					}
					else if(player1.getAgility() <= bandit.getAgility())
					{
						int endealt = damage(bandit.getPower(), player1.getPower());
						phealth = phealth - endealt;
						if((phealth <= 0)&& (lives <= 0))
						{
							test = gameover;
							break;
						}
						if((phealth <= 0)&&(lives >0))
						{
							lives -= 1;
							test = weapon_choice;
							break;
						}
						else
						{
							cout << "The bandit dealt damage." << "You have " << phealth << " health left" << endl;
							int pdealt = damage(player1.getPower(), bandit.getPower());
							ehealth = ehealth - pdealt;
							cout << "You dealt damage." << "The bandit has " << ehealth << " health left" << endl;
						}
					}
				}
				break;
			}
			if(pinput2 == "run")
			{
				courage -=1;
				if (courage <=0)
				{
					test = gameover;
					break;
				}
			}
			test = enemymake;
			break;
		}
		case fight2: /*fight against medium enemy*/
		{
			cout << "You have encountered a bounty hunter" << endl;
			cout << "Choose: fight or run" << endl;
			cin >> pinput2;
			while((pinput2 != "fight")||(pinput2 != "run"))
			{
				cout << "Choose: fight or run" << endl;
				cin >> pinput2;
			}
			if(pinput2 == "fight")
			{
				int phealth = 100;
				int ehealth = 100;
				while((phealth >= 0) ||(ehealth >= 0))
				{
					if(player1.getAgility() >  bounty_hunter.getAgility())
					{
						int dealt = damage(player1.getPower(), bounty_hunter.getPower());
						ehealth = ehealth - dealt;
						if(ehealth <= 0)
						{
							test = winfight;
							break;
						}
						else
						{
							cout << "You dealt damage." << "The bounty hunter has " << ehealth << " health left" << endl;
							int edealt = damage(bounty_hunter.getPower(), player1.getPower());
							phealth = phealth - edealt;
							cout << "The bounty hunter dealt damage." << "You have " << phealth << " health left" << endl;
						}
					}
					else if(player1.getAgility() <= bounty_hunter.getAgility())
					{
						int endealt = damage(bounty_hunter.getPower(), player1.getPower());
						phealth = phealth - endealt;
						if((phealth <= 0)&& (lives <= 0))
						{
							test = gameover;
							break;
						}
						if((phealth <= 0)&&(lives >0))
						{
							lives -= 1;
							test = weapon_choice;
							break;
						}
						else
						{
							cout << "The bounty hunter dealt damage." << "You have " << phealth << " health left" << endl;
							int pdealt = damage(player1.getPower(), bounty_hunter.getPower());
							ehealth = ehealth - pdealt;
							cout << "You dealt damage." << "The bounty hunter has " << ehealth << " health left" << endl;
						}
					}
				}
				break;
			}
			if(pinput2 == "run")
			{
				courage -=1;
				if (courage <=0)
				{
					test = gameover;
					break;
				}
			}
			test = enemymake;
			break;
		}
		case fight3:/*fight strong enemy*/
		{
			cout << "You have encountered a hitman" << endl;
			cout << "Choose: fight or run" << endl;
			cin >> pinput2;
			while((pinput2 != "fight")||(pinput2 != "run"))
			{
				cout << "Choose: fight or run" << endl;
				cin >> pinput2;
			}
			if(pinput2 == "fight")
			{
				int phealth = 100;
				int ehealth = 100;
				while((phealth >= 0)||(ehealth >= 0))
				{
					if(player1.getAgility() >  hitman.getAgility())
					{
						int dealt = damage(player1.getPower(), hitman.getPower());
						ehealth = ehealth - dealt;
						if(ehealth <= 0)
						{
							test = winfight;
							break;
						}
						else
						{
							cout << "You dealt damage." << "The hitman has " << ehealth << " health left" << endl;
							int edealt = damage(hitman.getPower(), player1.getPower());
							phealth = phealth - edealt;
							cout << "The hitman dealt damage." << "You have " << phealth << " health left" << endl;
						}
					}
					else if(player1.getAgility() <= hitman.getAgility())
					{
						int endealt = damage(hitman.getPower(), player1.getPower());
						phealth = phealth - endealt;
						if((phealth <= 0)&& (lives <= 0))
						{
							test = gameover;
							break;
						}
						if((phealth <= 0)&&(lives >0))
						{
							lives -= 1;
							test = weapon_choice;
							break;
						}
						else
						{
							cout << "The hitman dealt damage." << "You have " << phealth << " health left" << endl;
							int pdealt = damage(player1.getPower(), hitman.getPower());
							ehealth = ehealth - pdealt;
							cout << "You dealt damage." << "The hitman has " << ehealth << " health left" << endl;
						}
					}
				}
				break;
			}
			if(pinput2 == "run")
			{
				courage -=1;
				if (courage <=0)
				{
					test = gameover;
					break;
				}
			}
			test = enemymake;
			break;
		}
		case bossState: /*fight boss, after 3rd time fighting him will win game*/
		{
			bosscount += 1;
			int phealth = 100;
			int bhealth = 200;
			int input;
			bstat = random(15);
			boss.setPower(player1.getPower() + bstat);
			boss.setAccuracy(player1.getAccuracy() + bstat);
			boss.setAgility(player1.getAgility() + bstat);
			while((phealth <= 0) || (bhealth <= 0))
			{
				cout << "Choose: 1, 2, 3, 4, or 5 " << endl;
				cin >> pinput2;
				while((input != 1)||(input != 2)||(input != 3)||(input != 4)||(input != 5))
				{
					cout << "Choose: 1 2 3 4 5 " << endl;
					cin >> input;
				}
				int power = random(5);
				int power2 = random(5);
				while(power == power2)
				{
					power2 = random(5);
				}
				if(input = power)
				{
					cout << "Bad Choice: You take damage" << endl;
					phealth = phealth - 10;
					if((phealth <= 0)&& (lives <= 0))
					{
						test = gameover;
						break;
					}
					if((phealth <= 0)&&(lives > 0))
					{
						lives -=1;
						test = weapon_choice;
						break;
					}
					else
					{
						cout << "You have " << phealth << " health left" << endl;
					}
				}
				if(input = power2)
				{
					cout << "Good Choice: The boss takes damage" << endl;
					bhealth = bhealth - 10;
					if(bhealth <= 0 )
					{
						if(bosscount == 3)
						{
							test = victory;
							break;
						}
						else
						{
							test = winfight;
							break;
						}
					}
					else
					{
						cout << "The boss has " << bhealth << "health left" << endl;
					}
				}
				else
				{
					int bdealt = damage(boss.getPower(), player1.getPower());
					phealth -= bdealt;
					if((phealth <= 0)&&(lives <= 0))
					{
						cout << "The boss has finished you off" << endl;
						test = gameover;
						break;
					}
					if((phealth <= 0)&&(lives > 0))
					{
						lives -= 1;
						cout << "The boss has finished you off" << endl;
						test = weapon_choice;
						break;
					}
					else
					{
						cout << "The boss dealt damage. You have " << phealth << " health left" << endl;
						int pdealt = damage(player1.getPower(), boss.getPower());
						bhealth -= pdealt;
						if(bhealth <= 0)
						{
							if(bosscount == 3)
							{
								cout << "You finished off the boss" << endl;
								test = victory;
								break;
							}
							else
							{
								cout << "You finished off the boss" << endl;
								test = winfight;
								break;
							}
						}
						else
						{
							cout << "The boss takes damage.  It has " << bhealth << " health left" << endl;
						}
					}
				}
			}
			break;
		}
		case winfight: /*after winning a fight can possibly level up*/
		{
			wincount += 1;
			cout << "You win the fight.  You survive another day." << endl;
			if ( wincount >= playerlvl)
			{
				playerlvl +=1;
				player1.setPower(player1.getPower()+1);
				player1.setAgility(player1.getAgility() +2);
				player1.setAccuracy(player1.getAccuracy()+2);
				cout << "Congradulations you managed to level up." << endl;
				cout << "You are now level " << playerlvl << endl;
			}
			test = enemymake;
			break;

		}
		case gameover:/*gameover messages*/
		{
			if(lives <=0)
			{
				cout << "You lost your last live." << endl;
				cout << "GAME OVER" << endl;
				test = empty;
				break;
			}
			else
			{
				cout << "Your choices were too much of a burden." << endl;
				cout << "GAME OVER" << endl;
				test = empty;
			break;
			}
		}
		case victory: /*victory condition messages*/
		{
			cout << "Congradulations you beat the final boss" << endl;
			cout << "Your choices lead you to victory. " << endl;
			test = empty;
		}

	}
   }
  
return 0;
}
