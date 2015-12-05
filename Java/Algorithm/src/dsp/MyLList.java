package dsp;

public class MyLList {
	int count = 0;
	node head = null;
	
	class node {
		int data;
		node next = null;
		node (int i) {
			data = i;
		}
	}
	
	public void insert(int key) {
		count++;
		if(head == null) {
			head = new node(key);
			return;
		}
		
		node q = head;
		node p = head;
		while(p != null) {
			q = p;
			p = p.next;
		}
		q.next = new node(key);
	}
	
	public void print() {
		if(head == null)
			return;
		
		node p = head;
		while(p != null) {
			System.out.print(" " + p.data);
			p = p.next;
		}
	}
	
	public void delete(int key) {
		if(head == null)
			return;
		
		node q = head;
		node p = head;
		while(p != null) {
			if(p.data == key) {
				q.next = p.next;
				return;
			}
			q = p;	
			p = p.next;
		}
	}
	
	public void reverse() {
		if(head == null)
			return;
		
		node q = head;
		node p = head;
		node r = head;
		while(p != null) {
			r = p.next;
			p.next = q;
			if(q == head)
				q.next = null;
			q = p;
			p = r;
		}
		head = q;
	}
	
	public boolean isPresentKey(int key) {
		node p = head;
		while(p != null) {
			if(p.data == key)
				return true;
			p = p.next;
		}
		return false;
	}
}
