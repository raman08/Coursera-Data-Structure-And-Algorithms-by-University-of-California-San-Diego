# Trees

## Defination

A tree is:
	
1) Empty, or

2) a node with:

a) a key, and

b) a list of the child trees.

c) parents (optional)

## Terminology
	
1) Root : top node of the tree
2) Child : A line down directly from a parent
3) Ansestors : Parent, or parent of parent, etc.
4) Descendant : Child, or child of child, etc.
5) Sibling : Sharing the same parents.
6) Leaf: Node with no children
7) Level : 1 + number of edges between root and the node
8) Height: Maximim depth of the subtree node and the farthest leaf
9) Forest : Collection of the trees


## Binary Trees
	
The tree with maximun of the 2 childern is called binary tree.

For a binary tree, node consist:

1) key
2) left
3) right
4) parents (OPtional)
	
	
	
## Implenentations
		
### Height(tree) 

	Height(tree) {
		if tree == nil:
			return 0;

		return 1 + max(Height(tree.left) + Height(tree.right));
	}

### Size(tree)

	Size(tree) {
		if tree == nil:
			return 0;

		return 1 + max(Size(tree.left) + Size(tree.right));
	}


## Depth First Traversal

The first three algorithms are used as depth first stratergies. In all three algorithms all the sub-tree are traversed first before exploring the other sibling.

### In_Order_traversal(tree)
	
	// Mostly for binary Tree
	
	In_Order_traversal(tree) { 

		if tree == nil:
			return

		In_Order_traversal(tree.left)

		///Operations on element///

		In_Order_traversal(tree.right)
	}
	
### Pre_order_traversal(tree)

	Pre_order_traversal(tree) {

		if tree = nil:
			return

		///Operations///

		Pre_order_traversal(tree.left)
		Pre_order_traversal(tree.right)
	}

### Post_order_traversal(tree)

	Post_order_traversal(tree) {

		if tree = nil:
			return

		Pre_order_traversal(tree.left)
		Pre_order_traversal(tree.right)

		///Operations///
	}

## Breath First Travelsal

It is used to traverse the tree such that all nodes in the same level are traversed first.

### Level_Order_traversal(tree)

	Level_Order_traversal(tree) {

		if tree == nil:
			return

		Queu q
		q.Enqueue(tree)

		while not q.Empty() :
			current = q.Dequeue()

			///Operations///

			if current.left != nil:
				q.Enqueue(current.left)

			if current.right != nil:
				q.Enqueue(current.right)
			
			q.dequeue(current)

	}

