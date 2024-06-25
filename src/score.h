#pragma once
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"


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
	void insertscore(int rank, std::string user, int score);
	void displayscore();
public:
	sql::Connection* conn;
	sql::Driver* driver;
	sql::PreparedStatement* pst;
	sql::Statement* st;
	sql::ResultSet* result;

};