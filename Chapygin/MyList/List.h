#pragma once

#include <stdio.h>
#include <exception>

class List {
private:
	double* data;
	int* index;
	int curr;
	int prev;
	int size;

	int GetFreeNode();
	void AddFreeNode(int pos);
	void DelFreeNode();

public:
	List(int s);
	~List() { delete[] data; delete[] index; }

	bool isEmpty() const { return !index[0]?true:false; }
	bool isFull() const { return (index[1] == 1)?true:false; }
	bool EOL() const { return (!index[curr])?true:false; }
	int GetSize() const { return size; }

	void MoveNext();
	void Rewind() {	prev = 0; curr = index[0]; }
	void Add(double val);
	void Del();
	double& operator*();
	void PrintNode() const { printf("%lf ", data[curr]); }
	void PrintList() const;
};
