#include <iostream>


using namespace std;

class Database {
public:
	static Database* inst;
public:
	int value;
	static Database* instance();
};

Database* Database::instance() {
	cout << "Get instance called" << endl;
	if(!inst) {
		cout <<"Instance doesnt exist hence creating" << endl;
		inst=new Database();
	}
	return inst;
}

int main() {

	Database::instance()->value=12;
	Database::instance()->value=22;

	return 1;
}