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