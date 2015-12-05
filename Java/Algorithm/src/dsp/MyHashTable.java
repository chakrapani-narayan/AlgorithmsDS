package dsp;

public class MyHashTable {
	MyLList[] llists = new MyLList[100];
	int count = 0;
	
	MyHashTable() {
		for (int i = 0; i < llists.length; i++) {
			llists[i] = new MyLList();
		}
	}
	
	int getHashIndex(int key) {
		return key;
	}
	
	void insert(int key) {
		int idx = getHashIndex(key);
		llists[idx].insert(key);
	}
	
	boolean isPresentKey(int key) {
		for(MyLList ll : llists) {
			if(ll.isPresentKey(key) == true)
				return true;
		}
		return false;
	}
	
	void print() {
		for(MyLList ll : llists) {
			ll.print();
		}
	}
}
