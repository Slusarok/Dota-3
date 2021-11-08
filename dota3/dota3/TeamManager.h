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