#include "List.h"

List& Merge(List& list1, List& list2) {
	char small;
	List* listRes = new List(list1.GetSize() + list2.GetSize());
	while (!(list1.EOL()) && !(list2.EOL())) {
		if (list1.operator*() > list2.operator*()) {
			listRes -> Add(list2.operator*());
			listRes -> MoveNext();
			listRes -> Add(list1.operator*());
			listRes -> MoveNext();
		} else {
			listRes -> Add(list1.operator*());
			listRes -> MoveNext();
			listRes -> Add(list2.operator*());
			listRes -> MoveNext();
		}
	list1.MoveNext(); list2.MoveNext();
	}
	//LAST NODE OF SMALL LIST
	if ((list1.EOL()) && (list2.EOL())) small = 3;
	else if (list1.EOL()) small = 1;
	else small = 2;
	if (list1.operator*() > list2.operator*()) {
		listRes -> Add(list2.operator*());
		listRes -> MoveNext();
		listRes -> Add(list1.operator*());
		listRes -> MoveNext();
	} else {
		listRes -> Add(list1.operator*());
		listRes -> MoveNext();
		listRes -> Add(list2.operator*());
		listRes -> MoveNext();
	}

	if (small == 1) {
		list2.MoveNext();
		while (!(list2.EOL())) {
			listRes -> Add(list2.operator*());
			listRes -> MoveNext();
			list2.MoveNext();
		} 
		listRes -> Add(list2.operator*());
		listRes -> MoveNext();
	} else if (small == 2) {
		list1.MoveNext();
		while (!(list1.EOL())) {
			listRes -> Add(list1.operator*());
			listRes -> MoveNext();
			list1.MoveNext();
		} 
		listRes -> Add(list1.operator*());
		listRes -> MoveNext();
	}

	listRes -> Rewind();
	return *listRes;
}
	