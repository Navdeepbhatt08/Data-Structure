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

  //Insert  First Node
  insertFirst(data)
  {
    this.head = new Node(data,this.head);
  }



  //Print data 

  printListData()
  {
    let currect = this.head
    while(currect)
    {
      console.log(currect.data)
      currect = currect.next;
    }
  }
}

const ll = new linkedList();
ll.insertFirst(100);
ll.insertFirst(200);
ll.insertFirst(300);

ll.printListData()
