public class IntersectionSortedLists {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static Node intersection(Node head1, Node head2) {
        Node resultHead = null;
        Node resultTail = null;

        Node p1 = head1;
        Node p2 = head2;

        while (p1 != null && p2 != null) {

            if (p1.data == p2.data) {
                Node newNode = new Node(p1.data);

                if (resultHead == null) {
                    resultHead = newNode;
                    resultTail = newNode;
                } else {
                    resultTail.next = newNode;
                    resultTail = newNode;
                }

                p1 = p1.next;
                p2 = p2.next;
            } 
            else if (p1.data < p2.data) {
                p1 = p1.next;
            } 
            else {
                p2 = p2.next;
            }
        }

        return resultHead;
    }

    static void printList(Node head) {
        Node current = head;

        while (current != null) {
            System.out.print(current.data);

            if (current.next != null) {
                System.out.print(" -> ");
            }

            current = current.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(2);
        head1.next.next.next = new Node(3);
        head1.next.next.next.next = new Node(4);

        Node head2 = new Node(2);
        head2.next = new Node(2);
        head2.next.next = new Node(2);
        head2.next.next.next = new Node(4);

        System.out.println("List 1:");
        printList(head1);

        System.out.println("List 2:");
        printList(head2);

        Node result = intersection(head1, head2);

        System.out.println("Intersection:");
        printList(result);

        System.out.println("List 1 after intersection:");
        printList(head1);

        System.out.println("List 2 after intersection:");
        printList(head2);
    }
}
