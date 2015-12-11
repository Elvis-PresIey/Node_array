#include "List.h"


void List::AddFreeNode(int pos) {
	//int nextIndex = index[index[pos]];
	int firstFree = index[1];
	index[1] = index[pos];
	index[index[1]] = firstFree;
	//index[pos] = nextIndex;
}

int List::GetFreeNode() {
	int freeNodeIndex = index[1];
	index[1] = index[freeNodeIndex];
	return freeNodeIndex;
}


 List::List(int s) {
	 if (s <= 0) throw std::exception("INVALID SIZE");
	 data = (double*)malloc(sizeof(double) * (s + 2));
	 index = (int*)malloc(sizeof(int) * (s + 2));
	 prev = curr = index[0] = 0;
	 for (int i = 1; i < (s + 1); ++i)
		 index[i] = i + 1;
	 index[s + 1] = 1;
 }


void List::MoveNext() {
	if (!index[curr]) throw std::exception ("END OF LIST!");
	prev = curr;
	curr = index[curr];
}

void List::Add(double val) {
	if (isFull()) { throw std::exception("LIST IS FULL!"); return; }
	int nextIndex = index[curr];
	int pos = GetFreeNode();
	data[pos] = val;
// AFTER THE CURRENT
	index[curr] = pos;
	index[pos] = nextIndex;
}

void List::Del() {
	if (isEmpty()) { throw std::exception("LIST IS EMPTY!"); return; }
	int nextIndex = index[curr];
	AddFreeNode(prev);
	index[prev] = nextIndex;
	curr = nextIndex;
}

double& List::operator*(){
	return data[curr];
}

void List::PrintList() const {
	if (isEmpty()) return;
	printf("\n");
	for (int i = index[0]; i; i = index[i])
		printf("%lf ", data[i]);
}
