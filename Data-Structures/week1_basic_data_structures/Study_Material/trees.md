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

### Breath_first_Level_traversal(tree)

	Breath_first_Level_traversal(tree) {

		if tree == nil:
			return

		Queu q
		q.Enqueue(tree)

		while not q.Empty() :
			node = q.Dequeue()

			///Operations///

			if node.left != nil:
				q.Enqueue(node.left)

			if node.right != nil:
				q.Enqueue(node.right)

	}


### In_Order_traversal(tree)
	
	// Mostly for binary Tree
	
	In_Order_traversal(tree) { 

		if tree == nil:
			return

		In_Order_traversal(tree.left)

		///Operations on element///

		In_Order_traversal(tree.right)
	}
