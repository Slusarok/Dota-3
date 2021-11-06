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



using namespace std;
class Player
{
public:
	int ID, Rank;
	string Name;
	Player(int ID_Player, string Name_Player, int Rank_Player)
	{
		ID = ID_Player;
		Name = Name_Player;
		Rank = Rank_Player;

	}
	int GetRank() { return Rank; }
	void SetRank(int newRank) {
		if (newRank > 0)
			Rank = newRank;
		else Rank = 0;
	}
	Player() {}

};

class Hero
{
public:
	int ID, HP, Damage;
	string Name;
	Hero(int ID_Hero, string Name_Hero, int Damage_Hero, int HP_Hero)
	{
		ID = ID_Hero;
		Name = Name_Hero;
		Damage = Damage_Hero;
		HP = HP_Hero;
	}
	int GetHP() { return HP; }
	int GetDamage() { return Damage; }
	int setHP(int hp) { this->HP = hp; }
	Hero() {}
};
class PlayerManager
{
public:
	vector<Player>new_player;

	void CreatePlayer(int ID_Player, string Name_Player, int Rank_Player)
	{
		new_player.push_back(Player(ID_Player, Name_Player, Rank_Player));
	}

	void CreatePlayer(Player New_player[5])
	{
		for (int i = 0; i < 5; ++i)
			new_player.push_back(New_player[i]);
	}

	void DeletePlayer(int Del_ID)
	{
		new_player.erase(new_player.begin() + Del_ID - 1);
	}

	Player* GetPlayerByName(vector<Player>new_player, int lenght, string name)
	{
		for (int i = 0; i < new_player.size(); i++)
		{
			if (new_player[i].Name == name)
				return &new_player[i];
		}
		return nullptr;
	}

	Player* GetPlayerById(vector<Player>new_player, int lenght, int id)
	{
		for (int i = 0; i < new_player.size(); i++)
		{
			if (new_player[i].ID == id)
				return &new_player[i];
		}
		return nullptr;
	}


	void ShowPlayerInfo()
	{
		for (int i = 0; i < new_player.size(); i++)
		{
			cout << new_player[i].ID << '\t' << "Player:" << new_player[i].Name << '\t' << "Rank : " << '\t' << new_player[i].Rank << endl;
		}
		cout << endl;
	}

	void PlayerShaffle()
	{
		random_shuffle(new_player.begin(), new_player.end());
		for (int i = 0; i < new_player.size(); i++)
		{
			cout << new_player[i].ID << '\t' << "Player:" << new_player[i].Name << '\t' << "Rank : " << '\t' << new_player[i].Rank << endl;
			
		}
		cout << endl;
		
		
	}
};






class HeroManager
{
public:

	vector<Hero>all_hero;

	void CreateHero(int ID_Hero, string Name_Hero, int Damage_Hero, int HP_Hero)
	{
		all_hero.push_back(Hero(ID_Hero, Name_Hero, Damage_Hero, HP_Hero));
	}

	void CreateHero(Hero All_hero[5])
	{
		for (int i = 0; i < 5; ++i)
			all_hero.push_back(All_hero[i]);
	}

	void DeleteHero(int Del_ID)
	{
		all_hero.erase(all_hero.begin() + Del_ID - 1);
	}

	Hero* GetHeroByName(string name)
	{
		for (int i = 0; i < all_hero.size(); i++)
		{
			if (all_hero[i].Name == name)
			{
				cout << all_hero[i].ID << '\t' << "Player :" << all_hero[i].Name << '\t' << "Hero HP = " << all_hero[i].HP << '\t' << "Hero Damage =" << all_hero[i].Damage << endl;
				return &all_hero[i];
			}
		}
		return nullptr;
	}

	Hero* GetHeroById(int id)
	{
		for (int i = 0; i < all_hero.size(); ++i)
		{
			if (all_hero[i].ID == id)
			{ 
				cout << all_hero[i].ID << '\t' << "Hero :" << all_hero[i].Name << '\t' << "Hero HP = " << all_hero[i].HP << '\t' << "Hero Damage =" << all_hero[i].Damage << endl;
				return &all_hero[i];
			}
		}
		return nullptr;
	}


	void ShowHeroInfo()
	{
		for (int i = 0; i < all_hero.size(); i++)
		{
			cout << all_hero[i].ID << '\t' << "Hero :"  <<all_hero[i].Name << '\t' << "Hero HP = "  << all_hero[i].HP << '\t' << "Hero Damage =" << all_hero[i].Damage << endl;
		}
		cout << endl;
	}
	void HeroShaffle()
	{
		random_shuffle(all_hero.begin(),all_hero.end());
		for (int i = 0; i < all_hero.size(); i++)
		{
			cout << all_hero[i].ID << '\t' << "Hero :" << all_hero[i].Name << '\t' << "Hero HP = " << all_hero[i].HP << '\t' << "Hero Damage =" << all_hero[i].Damage << endl;

		}
		cout << endl;


	}
};

class Team {

public:
	std::string Name;
	Hero All_hero[5];
	Player New_player[5];
	Team(std::string name) :Name(name) {}
	Team(std::string name, Hero all_hero[5], Player new_player[5]) :Name(name) {
		
		for (int i = 0; i < 5; i++)
		{
			All_hero[i] = all_hero[i];
			New_player[i] = new_player[i];
		}

	}

	Team() {}
};

class TeamManager {
public:
	Team GenerateNewTeam(string TeamName, vector<Hero>all_hero, vector<Player>new_player) {

		Hero new_All_hero[5];
		Player new_New_player[5];
		if (TeamName == "Dire")
		{
			for (int i = 0; i < 5; i++)
			{
				new_All_hero[i] = all_hero[i];
				new_New_player[i] = new_player[i];

			}
		}
		if (TeamName == "Radiant")
		{
			for (int i = 0; i < 5; ++i)
			{
				new_All_hero[i] = all_hero[i+5];
				new_New_player[i] = new_player[i+5];
			}
				/*new_All_hero[0] = all_hero[5];
				new_New_player[0] = new_player[5];
				new_All_hero[1] = all_hero[6];
				new_New_player[1] = new_player[6];
				new_All_hero[2] = all_hero[7];
				new_New_player[2] = new_player[7];
				new_All_hero[3] = all_hero[8];
				new_New_player[3] = new_player[8];
				new_All_hero[4] = all_hero[9];
				new_New_player[4] = new_player[9];
				*/

		}

		Team team(TeamName, new_All_hero, new_New_player);
		return team;
	}
	void GetTeamInfo(string TeamName, Hero new_All_hero[5],Player new_New_player[5]) {
		if (TeamName == "Dire")
			cout << "*********************************************Team Dire*********************************************"<<endl;
		else
			cout << "*********************************************Team Radiant*********************************************"<<endl;
		for(int i=0; i<5;i++)
		{ 
			cout << new_New_player[i].ID << '\t' << "Player:" << new_New_player[i].Name << '\t' << "Rank: " << '\t' << new_New_player[i].Rank << endl;
			cout << new_All_hero[i].ID << '\t' << "Hero:" << new_All_hero[i].Name << '\t' << "Hero HP = " << new_All_hero[i].HP << '\t' << "Hero Damage =" << new_All_hero[i].Damage << endl;	
		}
		cout << endl<< endl;
		
		}
};
class Session {
	time_t StartTime = time(0);
public:
	Team Winner;
	Team TeamOne;
	Team TeamTwo;

	void CalculateWinner() {
		
		int hp_team_one = GetTeamHP(TeamOne);
		int hp_team_two = GetTeamHP(TeamTwo);

		int damage_team_one = GetTeamDamage(TeamOne);
		int damage_team_two = GetTeamDamage(TeamTwo);

		if (hp_team_two - damage_team_one > hp_team_one -damage_team_two)
		{ 
			AddRank(TeamTwo);
			RemoveRank(TeamOne);
			Winner = TeamOne;
			cout << "Team Dire won";
		}
		if (hp_team_two - damage_team_one == hp_team_one - damage_team_two)
		{
			cout << "Draw";
		}
		if (hp_team_two - damage_team_one < hp_team_one - damage_team_two)
		{
			AddRank(TeamOne);
			RemoveRank(TeamTwo);
			Winner = TeamTwo;
			cout << "Team Radiant won";
		}
	}

	int GetTeamHP(Team& team)
	{
		int Sum_HP = 0;
		for (auto hero : team.All_hero)
		{
			Sum_HP += hero.GetHP();
		}
		return Sum_HP;
	}

	int GetTeamDamage(Team& team)
	{
		int Sum_Damage = 0;
		for (auto hero : team.All_hero)
		{
			Sum_Damage += hero.GetDamage();
		}
		return Sum_Damage;
	}
	void AddRank(Team& winnerTeam)
	{
		for (auto& player : winnerTeam.New_player)
		{
			player.SetRank(player.GetRank() + 25);
		}


	}

	void RemoveRank(Team& looserTeam)
	{
		for (auto& player : looserTeam.New_player)
		{
			player.SetRank(player.GetRank() - 25);
		}
	}
};
class GameManager {
	list<Session> GameSession;
public:
	void PerformGameSession(PlayerManager _PlayerManager, HeroManager _HeroManager){

		TeamManager teamManager = TeamManager();


		Team team1 = teamManager.GenerateNewTeam("Dire", _HeroManager.all_hero, _PlayerManager.new_player);
		Team team2 = teamManager.GenerateNewTeam("Radiant", _HeroManager.all_hero, _PlayerManager.new_player);

		Session session = Session();
		session.TeamOne = team1;
		session.TeamTwo = team2;

		cout << "*******************************************Prepare for battle*******************************************"<<endl;


		teamManager.GetTeamInfo("Dire", team1.All_hero, team1.New_player);
		teamManager.GetTeamInfo("Radiant", team2.All_hero, team2.New_player);
		std::cout << std::endl;

		session.CalculateWinner();
		GameSession.push_back(session);


		}
};
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
	/*anager teamManager = TeamManager();
	Team Dire = teamManager.GenerateNewTeam("Dire", create_Hero_Manager.all_hero, create_Player_Manager.new_player);
	Team Radiant = teamManager.GenerateNewTeam("Radiant", create_Hero_Manager.all_hero, create_Player_Manager.new_player);
	teamManager.GetTeamInfo("Dire", Dire.All_hero, Dire.New_player);
	teamManager.GetTeamInfo("Radiant", Radiant.All_hero, Radiant.New_player);*/
	GameManager gamemanage = GameManager();
	gamemanage.PerformGameSession(create_Player_Manager, create_Hero_Manager);


	return 0;
}