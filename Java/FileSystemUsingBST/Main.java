import java.util.ArrayList;
import java.util.List;

class Node {
    private String name;
    private boolean isDirectory;
    private List<Node> children;    // List for storing files and directories

    public Node(String name, boolean isDirectory) {
        this.name = name;
        this.isDirectory = isDirectory;
        this.children = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public boolean isDirectory() {
        return isDirectory;
    }

    public List<Node> getChildren() {
        return children;
    }

    public void addChild(Node child) {
        children.add(child);
    }
}

class FileSystemTree {
    private Node root;

    public Node getRoot() {
        return root;
    }

    public FileSystemTree(String rootName) {
        this.root = new Node(rootName, true);
    }

    public void addNode(String parentDirectory, String name, boolean isDirectory) {
        Node parentNode = findNode(root, parentDirectory);
        if (parentNode != null) {
            Node newNode = new Node(name, isDirectory);
            parentNode.addChild(newNode);
        } else {
            System.out.println("Parent directory not found!");
        }
    }

    private Node findNode(Node node, String name) {
        if (node.getName() == name) {
            return node;
        }
        // this for loop is equivalent to the while loop as it is traversing the tree
        for (Node child : node.getChildren()) {
            Node foundNode = findNode(child, name);
            if (foundNode != null) {
                return foundNode;
            }
        }
        return null;
    }

    public void displayFileSystem() {
        displayFileSystem(root, 0);
    }

    private void displayFileSystem(Node node, int depth) {
        StringBuilder indent = new StringBuilder();
        for (int i = 0; i < depth; i++) {
            indent.append("    ");
        }
        System.out.println(indent + node.getName() + (node.isDirectory() ? "/" : ""));
        for (Node child : node.getChildren()) {
            displayFileSystem(child, depth + 1);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        FileSystemTree fileSystem = new FileSystemTree("root");
        fileSystem.addNode("root", "documents", true);
        fileSystem.addNode("root", "downloads", true);
        fileSystem.addNode("documents", "document.txt", false);
        fileSystem.addNode("downloads", "text.txt", false);
        fileSystem.addNode("documents", "java", true);
        fileSystem.addNode("java", "Main.java", false);
        fileSystem.addNode("java", "Assignment.java", false);
        System.out.println("File System Structure:");
        fileSystem.displayFileSystem();
        fileSystem.addNode("root", "music", true);
        fileSystem.addNode("root", "picture", true);
        fileSystem.addNode("music", "song.mp3", false);
        fileSystem.addNode("picture", "pic1.png", false);
        fileSystem.addNode("music", "music.mp3", false);
        fileSystem.addNode("picture", "pic2.png", false);
        System.out.println("File System Structure:");
        fileSystem.displayFileSystem();
    }
}