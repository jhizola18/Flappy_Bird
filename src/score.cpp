#include "score.h"

Score::Score()
	:
	host("localhost"),
	port("3306"),
	database("db_userscore"),
	uid("root"),
	password("admin")
{
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

void Score::insertscore(int rank, std::string user, int score)
{
	connect();
	const std::string queries = "INSERT INTO tbl_userscore(U_rank,U_name,U_score) VALUES(?, ?, ?)";
	pst = conn->prepareStatement(queries);
	try {
		
		pst->setInt(1, rank);
		pst->setString(2, user);
		pst->setInt(3, score);
		pst->execute();
		std::cout << "Score Saved!!!";
		
	}
	catch (sql::SQLException ex) {
		std::cout << "Score not Saved!!!";
	}
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
