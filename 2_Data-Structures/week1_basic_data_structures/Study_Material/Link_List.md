## Singly-Linked List

#### PushFront(key)

```
PushFront(key) {

	node = new node
	node.key = key
	node.next = head
	head = node

	if tail == nil:
		tail = head

}

```

#### PopFront(key)

```

PopFront(key) {

	if head == nil:
		Error!!!!!!!

	head = head.next

	if head == nil:
		tail = nil

}

```

#### PushBack(key)

```
PushBack(key) {

	node = new.node
	node.key = key
	node.next = nil

	if tail == nil:
		head = tail = node

	else:
		tail.next = node
		tail = node

}

```

#### PopBack(key)

```

PopBack() {

	if head == nil:
		ERROR!!!!!!!!!!!!!

	if head = tail:
		head = tail = nil

	else:
		p = head

		while p.next.next != nil:
			p = p.next

		p.next = nil
		tail = p

}

```

#### AddAfter(node, key)

```

AddAfter(node, key) {

	node2 = new node
	node2.key = key
	node2.next = node.next
	node.next = node2

	if tail == node
		tail = node2

}

```


## Double Linked List

#### PushBack(key)

```

PushBack(key) {

	node = new node
	node.key = key
	node.next = nil

	if tail == nil:
		head = tail = node
		node.next = node
		node.prev = tail
		tail = node

}

```

#### Popback()

```

Popback() {

	if head = nil:
		ERROR!!!!!!!!!

	if head = tail:
		head = tail = nil

	else:
		tail = tail.prev
		tail.next = nil

}

```

#### AddAfter(node, key)

```

AddAfter(node, key) {

	node2 = new node
	node2.key = key
	node2.next = node.next
	node.prev = node
	node2.next = node2

	if node2.next != nil:
		node2.next.prev = node2

	if tail == node
		tail = node2

}

```

#### AddAfter(node, key)

```

AddAfter(node, key) {

	node2 = new node
	node2.key = key
	node2.next = node
	node.prev = node.prev
	node2.next = node2

	if node2.next != nil:
		node2.prev.next = node2

	if tail == node
		tail = node2

}

```