#include "mysql_driver.h"
#include "mysql_connection.h"
#include <cppconn/statement.h>
#include <iostream>

using namespace std;

int main() {
    sql::mysql::MySQL_Driver *driver = NULL;
    sql::Connection *con = NULL;
    sql::Statement *stmt = NULL;
    driver = sql::mysql::get_mysql_driver_instance();
    if (driver == NULL)
    {
        cout << "driver is null" << endl;
    }
    std::string host_address = "tcp://127.0.0.1:3306";
    std::string host_name = "root";
    std::string password = " ";
    con = driver->connect(host_address, host_name, password);
    if (con == NULL)
    {
        cout << "conn is null" << endl;
    }
    cout << "connect suceess" << endl;
    con->setSchema("Sigma");

    // 创建并构造sql语句，用完后手动删除
    stmt = con->createStatement();
    string sql_cmd = "INSERT INTO PlayerCommand(timestamp, cmd) VALUES ('";
    sql_cmd.append("1667");
    sql_cmd.append("','");
    sql_cmd.append("100'");
    sql_cmd.append(")");
    cout<<"insert cmd : "<<sql_cmd<<endl;
    try{
        stmt->execute(sql_cmd);
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    // 删除资源
    delete stmt;
    return 0;
}
