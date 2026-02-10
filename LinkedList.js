class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}
class linkedList {
  constructor() {
    this.head = null;
    this.size = 0;
  }

  insertFirst(data) {
    this.head = new Node(data, this.head);
    this.size++;
  }

  //Insert Last Node
  insertLast(data) {
    let node = new Node(data);
    let current;

    if (!this.head) {
      this.head = node;
    } else {
      current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = node;
    }
    this.size++;
  }

  //Print data
  printListData() {
    let current = this.head;
    while (current) {
      console.log(current.data);
      current = current.next;
    }
  }
}

const ll = new linkedList();
ll.insertFirst(100);
ll.insertFirst(200);
ll.insertFirst(300);

ll.insertLast(400)
ll.insertLast(500)
ll.insertLast(600)

ll.printListData();
