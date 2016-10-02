import java.util.*;


public class LinkedList {

	public class Node {
		
		int data;
		Node next;

		Node(int data) {
			this.data=data;
		}
		private void display() {

			System.out.println("Read");
		}		
	}

	Node head;
	int size;	

	LinkedList() {

	}
	LinkedList(int data) {

		try{
			if(head == null) {
				Node node=new Node(data);
				this.head=node;
			} else {
				throw new Exception("Head is already initialized");
			}
		} catch(Exception e) {
			System.err.println("Head is initialized");
		}
		
	}


	public void createNode() {
		// Node n=new Node();
		// n.display();
	}

	public void display() {
		Node temp=head;
		try {
			if(head == null) {
				throw new Exception("Head is empty");
			}

			while(temp != null) {
				System.out.println(temp.data+"	");
				temp=temp.next;
			}

		} catch(Exception e) {
			System.err.println("Head is empty");
		}
	}

	private void insert(int data) {

		Node newNode=new Node(data);
		Node temp=head;
		while(temp.next != null) {
			temp=temp.next;
		}

		temp.next=newNode;
	}


	public static void main(String[] args) {
		System.out.println("Helooo");

		LinkedList list=new LinkedList();
		list.display();
		list.insert(20);
		list.insert(30);
		list.display();
		// list.createNode();
	}
}

