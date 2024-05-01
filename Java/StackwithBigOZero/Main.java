class Node {
    int data;
    Node top;
    Node nextMin; 
    
    Node(int data) {
        this.data = data;
        this.top = null;
        this.nextMin = null;
    }
}

class CustomStack {
    private Node head;
    private Node min; 

    public void push(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            min = newNode; 
        } else {
            newNode.top = head;
            head = newNode;
            
            if (newNode.data < min.data) {
                newNode.nextMin = min;
                min = newNode;
            }
        }
    }

    public void pop() {
        if (head == null) {
            return;
        }
        
        if (head == min) {
            min = min.nextMin;
        }
        head = head.top;
    }

    public int peek() {
        if (head == null) {
            return -1;
        }
        return head.data;
    }

    public int getMinimum() {
        if (min == null) {
            return -1; 
        }
        return min.data;
    }

    public void displayStack() {
        Node current = head;
        while (current != null) {
            System.out.println(current.data);
            current = current.top;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        CustomStack stack = new CustomStack();

        stack.push(9);
        stack.push(7);
        stack.push(4);
        stack.push(3);
        stack.push(5);
        stack.push(2);
        stack.push(1);
        stack.displayStack();
        System.out.println("Minimum Value: " + stack.getMinimum());
        System.out.println("Peek: " + stack.peek());
        stack.pop();
        stack.pop();
        stack.displayStack();
        System.out.println("Minimum value: " + stack.getMinimum());
        System.out.println("Peek: " + stack.peek());
        stack.pop();
        stack.pop();
        stack.push(0);
        stack.push(10);
        stack.displayStack();
        System.out.println("Minimum value: " + stack.getMinimum());
        System.out.println("Peek: " + stack.peek());
    }
}