# Priority Queue

A priority queue data structure is a generalization of the standard queue data structure.

In the priority queue data structure, there is no such thing as the beginning or the end of a queue.

## Defination (Informally)

A priority queue is a generalization of a queue where each element is assigned a priority and elements come out in order by priority.

## Defination (Formally)

Priority Queue is an abstract data type support the following main operations:

- **Insert(p):** add a new element with priority p
- **ExtractMax():** extracts an element with maximun priority

#### Additional Operations

- **Remove(it):** removes an element pointed by iterator it
- **GetMax():** returns an element with maximun priority (without changing anything)
- **ChangePriority(it, p):** changes the priority of an element pointed bt it to p

#### Running Time


| Implementation           | Insertion Time | ExtractMax Time |
|---                       |---             |---              |
| **Unsorted Array/ List** | O(1)           | O(n)            |
| **Sorted Array/ List**   | O(n)           | O(1)            |
| **Binary Heap**          | O( log(n) )    |O( log(n) )      |

