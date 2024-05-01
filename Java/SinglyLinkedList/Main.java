class Node {
    int data;
    Node next;
    
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {

    private Node head;

    public Node getHead() {
        return head;
    }

    public void insert_front(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            head = newNode;
        }
    }

    public void insert_end(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while(temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    public void delete(int value) {
        if (head == null) {
            return;
        }
        if (head.data == value) {
            head = head.next;
            return;
        }
        Node prev = head;
        Node current = head.next;
        while (current != null && current.data != value) {
            prev = current;
            current = current.next;
        }
        if (current != null) {
            prev.next = current.next;
        }
    }

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + ",");
            temp = temp.next;
        }
        System.out.println();
    }    
}

public class Main {
    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
        System.out.println("Insert 1,2,3,4,5 at front:");
        list.insert_front(1);
        list.insert_front(2);
        list.insert_front(3);
        list.insert_front(4);
        list.insert_front(5);
        list.display();
        System.out.println("Delete 3:");
        list.delete(3);
        list.display(); 
        System.out.println("Insert 6,7,8,9,10 at end:");
        list.insert_end(6);
        list.insert_end(7);
        list.insert_end(8);
        list.insert_end(9);
        list.insert_end(10);
        list.display(); 
    }
}