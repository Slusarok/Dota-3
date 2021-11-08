class PlayerManager
{
public:
	vector<Player>new_player;

	void CreatePlayer(int ID_Player, string Name_Player, int Rank_Player)
	{
		new_player.push_back(Player(ID_Player, Name_Player, Rank_Player));
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