class Node {
    int data;
    Node top;
    
    Node(int data) {
        this.data = data;
        this.top = null;
    }
}

class Stack {

    private Node head;

    public void push(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = newNode;
        } else {
            newNode.top = head;
            head = newNode;
        }
    }

    public void pop() {
        if (head == null) {
            return;
        }
        head = head.top;
    }

    public int peek() {
        if (head == null) {
            return -1;
        }
        return head.data;
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + "\n");
            current = current.top;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(10);
        stack.push(22);
        stack.push(35);
        stack.push(49);
        stack.push(56);
        stack.display();
        System.out.println("Peek: ");
        System.out.println(stack.peek());
        System.out.println("Pop");
        stack.pop();
        stack.display();
        System.out.println("Peek after: ");
        System.out.println(stack.peek());
    }
}