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