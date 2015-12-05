package dsp;

import java.util.*;

public class DataStructure {
	
	static HashMap<Integer, Integer>  hm = new HashMap<Integer, Integer>();
	static MyHashTable ht = new MyHashTable();
	static MyLList ll = new MyLList();
	
	static void Initialize() {

		//// hashtable
		ht.insert(91);
		ht.insert(1);
		ht.insert(52);
		ht.insert(66);
		ht.insert(8);		
		// hashtable
		
		////list
		ll.insert(91);
		ll.insert(1);
		ll.insert(52);
		ll.insert(66);
		ll.insert(17);
		ll.insert(8);
		//list	
	}
	
	public static void main(String[] args) {
		System.out.print("hello world\n");
		
		Initialize();
		
	    //// Fibonacci
		hm.put(1,1);
		hm.put(2,1);
		System.out.print("6th Fibonacci is " + fibonacci(6) + "\n");
		// Fibonacci
		
		//// hashtable
		System.out.print("\nPrinting HashTable \n");
		ht.print();
		// hashtable
		
		//// llist
		System.out.print("\nPrinting LinkedList \n");
		ll.print();
		System.out.print("\n");
		ll.delete(66);
		ll.print();
		System.out.print("\n");
		ll.reverse();
		ll.print();
		System.out.print("\n");
		// list
		
		//// Sort
		System.out.print("\nPrinting unsorted attay \n");
		MySort.print();
		//MySort.mergeSort();
		MySort.quickSort();
		System.out.print("\nPrinting sorted attay \n");
		MySort.print();
		// Sort
	}
	
    ////Fibonacci
	private static int fibonacci(int idx) {	
		if(idx > 2)
			return fibonacci(idx - 1) + fibonacci(idx - 2);
		return hm.get(idx);
	}
    //Fibonacci	
}
