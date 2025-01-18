#pragma once
#include <fstream>
#include "raylib.h"
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"

extern int scores;

class Score {

private:
	
	const std::string host;
	const std::string port;
	const std::string database;
	const std::string uid;
	const std::string password;

	

public:

	Score();
	~Score()noexcept;
	void connect();
	void insertscore(std::string user, int score);
	int highScoreManager(int currentScore);
	int showHighScore();
	void displayscore();

public:
	sql::Connection* conn;
	sql::Driver* driver;
	sql::PreparedStatement* pst;
	sql::Statement* st;
	sql::ResultSet* result;

	int current_highscore;

};