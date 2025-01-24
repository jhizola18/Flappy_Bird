#include "score.h"


Score::Score()
	:
	conn(nullptr),
	pst(nullptr),
	st(nullptr),
	driver(nullptr),
	result(nullptr),
	host("localhost"),
	port("3306"),
	database("db_userscore"),
	uid("root"),
	password("admin")
{
	this->current_highscore = 0;
}

Score::~Score() noexcept
{
	delete conn;
	delete pst;
	delete st;
}

void Score::connect()
{
	try {
		driver = get_driver_instance();
		conn = driver->connect(host,uid,password);
		conn->setSchema(database);
		std::cout << "Connected \n";
	}
	catch (sql::SQLException ex)
	{
		std::cout << "Can't Connect to Database \n";
	}

}

void Score::insertscore(std::string user, int score)
{
	connect();
	const std::string queries = "INSERT INTO tbl_userscore(U_name,U_score) VALUES(?, ?)";
	pst = conn->prepareStatement(queries);
	try {

		pst->setString(1, user);
		pst->setInt(2, score);
		pst->execute();
		std::cout << "Score Saved!!!";
	}
	catch (sql::SQLException ex) {
		std::cout << "Score not Saved!!!";
	}
}

int Score::highScoreManager(int currentScore)
{
	
	
	if (currentScore > current_highscore)
	{
		current_highscore = currentScore - 1;
		std::ofstream scoreFile("highScore.txt");
		if (scoreFile.is_open())
		{
			scoreFile << current_highscore;

			scoreFile.close();
		}

		std::ifstream highScoreFile("highScore.txt");
		if (highScoreFile.is_open())
		{
			highScoreFile >> current_highscore;
			highScoreFile.close();
		}
	}
	
	return current_highscore;
}

int Score::showHighScore()
{
	std::ifstream highScoreFile("highScore.txt");
	if (highScoreFile.is_open())
	{

		highScoreFile >> current_highscore;
		highScoreFile.close();

	}
	else {
		DrawText(" ", 10, 30, 20, BLACK);
	}

	return current_highscore;
}


void Score::displayscore()
{
	connect();
	std::string queries = "SELECT * FROM tbl_userscore;";
	pst = conn->prepareStatement(queries);
	result = pst->executeQuery();
	std::cout << "Rank" << "\tName" << "\tScore\n";
	while (result->next()) {

		std::cout << result->getInt(1) << "\t" << result->getString(2) << "\t" << result->getInt(3) << "\n";

	}
}
