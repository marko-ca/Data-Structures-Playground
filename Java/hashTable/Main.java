import java.util.LinkedList;

class KeyValuePair<K, V> {
    K key;
    V value;

    public KeyValuePair(K key, V value) {
        this.key = key;
        this.value = value;
    }
}

class HashTable<K, V> {
    private static final int DEFAULT_CAPACITY = 10;
    private static final double LOAD_FACTOR_THRESHOLD = 0.75;

    private LinkedList<KeyValuePair<K, V>>[] table;
    private int size;

    public HashTable() {
        table = new LinkedList[DEFAULT_CAPACITY];
        size = 0;
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % table.length;
    }

    private void resize() {
        if ((double) size / table.length > LOAD_FACTOR_THRESHOLD) {
            LinkedList<KeyValuePair<K, V>>[] oldTable = table;
            table = new LinkedList[table.length * 2];

            for (LinkedList<KeyValuePair<K, V>> list : oldTable) {
                if (list != null) {
                    for (KeyValuePair<K, V> pair : list) {
                        insert(pair.key, pair.value);
                    }
                }
            }
        }
    }

    public void insert(K key, V value) {
        resize();
        int index = hash(key);
        if (table[index] == null) {
            table[index] = new LinkedList<>();
        }

        for (KeyValuePair<K, V> pair : table[index]) {
            if (pair.key.equals(key)) {
                pair.value = value;
                return;
            }
        }

        table[index].add(new KeyValuePair<>(key, value));
        size++;
    }

    public V get(K key) {
        int index = hash(key);
        if (table[index] != null) {
            for (KeyValuePair<K, V> pair : table[index]) {
                if (pair.key.equals(key)) {
                    return pair.value;
                }
            }
        }
        return null;
    }

    public void delete(K key) {
        int index = hash(key);
        if (table[index] != null) {
            table[index].removeIf(pair -> pair.key.equals(key));
            size--;
        }
    }

    public boolean contains(K key) {
        int index = hash(key);
        if (table[index] != null) {
            for (KeyValuePair<K, V> pair : table[index]) {
                if (pair.key.equals(key)) {
                    return true;
                }
            }
        }
        return false;
    }

    public LinkedList<K> keys() {
        LinkedList<K> keys = new LinkedList<>();
        for (LinkedList<KeyValuePair<K, V>> list : table) {
            if (list != null) {
                for (KeyValuePair<K, V> pair : list) {
                    keys.add(pair.key);
                }
            }
        }
        return keys;
    }

    public LinkedList<V> values() {
        LinkedList<V> values = new LinkedList<>();
        for (LinkedList<KeyValuePair<K, V>> list : table) {
            if (list != null) {
                for (KeyValuePair<K, V> pair : list) {
                    values.add(pair.value);
                }
            }
        }
        return values;
    }
}

public class Main {
    public static void main(String[] args) {
        HashTable<String, Integer> hashTable = new HashTable<>();

        hashTable.insert("apple", 10);
        hashTable.insert("banana", 20);
        hashTable.insert("cherry", 30);
        System.out.println("Keys: " + hashTable.keys());
        System.out.println("Values: " + hashTable.values());
        System.out.println("Get apple: " + hashTable.get("apple"));
        System.out.println("Contains banana: " + hashTable.contains("banana"));
        System.out.println("Deleting banana");
        hashTable.delete("banana");
        System.out.println("Contains banana: " + hashTable.contains("banana"));
        System.out.println("Keys: " + hashTable.keys());
        System.out.println("Values: " + hashTable.values());
    }
}