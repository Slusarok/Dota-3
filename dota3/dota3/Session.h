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