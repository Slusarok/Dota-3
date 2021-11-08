class HeroManager
{
public:

	vector<Hero>all_hero;

	void CreateHero(int ID_Hero, string Name_Hero, int Damage_Hero, int HP_Hero)
	{
		all_hero.push_back(Hero(ID_Hero, Name_Hero, Damage_Hero, HP_Hero));
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