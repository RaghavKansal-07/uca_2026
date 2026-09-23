public class SearchLinkedList {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static boolean isPresent(Node list1, Node list2) {
        if (list1 == null) {
            return true;
        }

        Node current = list2;

        while (current != null) {
            Node p1 = list1;
            Node p2 = current;

            while (p1 != null && p2 != null && p1.data == p2.data) {
                p1 = p1.next;
                p2 = p2.next;
            }

            if (p1 == null) {
                return true;
            }

            current = current.next;
        }

        return false;
    }

    static void printResult(boolean result) {
        System.out.println(result ? "Yes" : "No");
    }

    public static void main(String[] args) {

        Node list1 = new Node(1);
        list1.next = new Node(2);
        list1.next.next = new Node(3);
        list1.next.next.next = new Node(4);

        Node list2 = new Node(1);
        list2.next = new Node(2);
        list2.next.next = new Node(2);
        list2.next.next.next = new Node(1);
        list2.next.next.next.next = new Node(2);
        list2.next.next.next.next.next = new Node(3);

        boolean result = isPresent(list1, list2);

        printResult(result);
    }
}
