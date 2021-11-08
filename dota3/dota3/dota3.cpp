#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <numeric>  
#include <list>
#include "Player.h"
#include "Hero.h"
#include "HeroManager.h"
#include "PlayerManager.h"
#include "Team.h"
#include "TeamManager.h"
#include "Session.h"
#include "GameManager.h"

using namespace std;

int main()
{
	srand(time(NULL));
	
	PlayerManager create_Player_Manager;
	HeroManager create_Hero_Manager;

	create_Player_Manager.CreatePlayer(1, "Andrius", 125);
	create_Player_Manager.CreatePlayer(2, "Nazar", 123);
	create_Player_Manager.CreatePlayer(3, "Dima", 125);
	create_Player_Manager.CreatePlayer(4, "Alex", 100);
	create_Player_Manager.CreatePlayer(5, "Roma", 150);
	create_Player_Manager.CreatePlayer(6, "Ivan", 125);
	create_Player_Manager.CreatePlayer(7, "Semen", 150);
	create_Player_Manager.CreatePlayer(8, "Vasil", 200);
	create_Player_Manager.CreatePlayer(9, "Brandon", 200);
	create_Player_Manager.CreatePlayer(10, "Avreli", 150);

	create_Hero_Manager.CreateHero(1, "Warrior", 150, 100);
	create_Hero_Manager.CreateHero(2, "Paladin", 150, 100);
	create_Hero_Manager.CreateHero(3, "Shaman", 125, 65);
	create_Hero_Manager.CreateHero(4, "Warlock", 150, 100);
	create_Hero_Manager.CreateHero(5, "Mag", 120, 55);
	create_Hero_Manager.CreateHero(6, "Druid", 110, 75);
	create_Hero_Manager.CreateHero(7, "DH", 150, 65);
	create_Hero_Manager.CreateHero(8, "Monah", 50, 250);
	create_Hero_Manager.CreateHero(9, "Priest", 25, 50);
	create_Hero_Manager.CreateHero(10, "Hunter", 175, 65);
	
	
	create_Player_Manager.PlayerShaffle();
	create_Hero_Manager.HeroShaffle();
	GameManager gamemanage = GameManager();
	gamemanage.PerformGameSession(create_Player_Manager, create_Hero_Manager);


	return 0;
}