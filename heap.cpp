#include <iostream>

using namespace std;


class Heap {

public:
	int *array;
	int capacity;
	int size;

	Heap(int capacity);
	void insert(int element);
	int parent(int child);
	int leftChild(int parent);
	int rightChild(int parent);
	void swap(int loc1,int loc2);
	void max_heapify(int loc);
	void display();
	int deleteMax();
	void percolateDown(int loc);
};


Heap::Heap(int capacity) {
	this->array=(int *)calloc(capacity,sizeof(int));
	this->capacity=capacity;
	this->size=0;
}

void Heap::insert(int element) {
	if(this->size + 1 > this->capacity) {
		cout << "Capacity Exceeded" << endl;
		return ;
	} 
	array[size]=element;
	max_heapify(size);
	size++;
}

int Heap::leftChild(int parent) {
	int lChild=(2*parent+1);
	if(lChild >= size) {
		return -1;
	} 
	return lChild;
}

int Heap::rightChild(int parent) {
	int rChild=(2*parent+2);
	if(rChild >= size) {
		return -1;
	} 
	return rChild;
}

int Heap::parent(int child) {
	int parent=(child-1)/2;
	if(child <= 0) {
		return -1;
	}
	return parent;
}

void Heap::swap(int loc1,int loc2) {
	int temp=this->array[loc2];
	this->array[loc2]=this->array[loc1];
	this->array[loc1]=temp;
}

void Heap::max_heapify(int loc) {

	int temp;
	int parent_val;
	if(this->parent(loc) == -1) {
		return;
	}
	parent_val=this->array[this->parent(loc)];
	if(parent_val < this->array[loc]) {
		swap(loc,this->parent(loc));
		max_heapify(this->parent(loc));
	}
}

void Heap::display() {
	cout << "Size is " << size << endl;
	for(int i=0;i<size;i++) {
		cout << this->array[i] << "	 ";
	}
	cout << endl;
}


int Heap::deleteMax() {
	if(size == 0) {
		return -1;
	}
	int maxElement=0;
	maxElement=this->array[0];
	this->array[0]=this->array[size-1];
	size--;
	percolateDown(0);
	return maxElement;
}

void Heap::percolateDown(int loc) {
	int lChild=leftChild(loc);
	int rChild=rightChild(loc);
	int max=loc;
	int temp;

	if(lChild >= size && rChild >= size) {
		return;
	}

	if(lChild != -1 && this->array[loc] < this->array[lChild]) {
		max=lChild;
	} 
	if(rChild != -1 && this->array[max] < this->array[rChild]) {
		max=rChild;
	}

	if(max != loc) {
		swap(max,loc);
		percolateDown(max);
	}
}

int main() {

	Heap *heapObj=new Heap(20);
	heapObj->insert(20);
	heapObj->insert(30);
	heapObj->insert(28);
	heapObj->insert(190);
	heapObj->insert(8);
	heapObj->insert(450);
	heapObj->insert(890);
	heapObj->insert(2);
	heapObj->insert(1);
	heapObj->display();

	cout << endl;
	cout << heapObj->deleteMax() << endl;
	heapObj->display();
	cout << heapObj->deleteMax() << endl;
	// heapObj->display();
	cout << heapObj->deleteMax() << endl;
	heapObj->display();
	cout << heapObj->deleteMax() << endl;
	cout << heapObj->deleteMax() << endl;
	cout << heapObj->deleteMax() << endl;
	cout << heapObj->deleteMax() << endl;
	cout << heapObj->deleteMax() << endl;
	cout << heapObj->deleteMax() << endl;
	cout << heapObj->deleteMax() << endl;

	return 1;
}
