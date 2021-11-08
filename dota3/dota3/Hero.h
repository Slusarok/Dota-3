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