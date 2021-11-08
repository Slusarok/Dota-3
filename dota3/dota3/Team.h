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