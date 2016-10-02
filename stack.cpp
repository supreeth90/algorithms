#include <iostream>
#include <vector>

using namespace std;


class Stack {

public: 
	vector<int> data;
	int head;
	Stack();
	push(int data);


};


Stack::Stack() {
	head=-1;

}
Stack::push(int data) {
	data.push_back(data);
	head++;
}