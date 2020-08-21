## Map

#### Defination

Map from S to V is a data structure with methods HasKey(O), Get(O), Set(O, v), where O c- S and v c- V.


## Set

#### Defination

Set is a data structure with methods Add(O), Remove(O), Find(O).

#### Implementing Set

Two ways to implement a set using chaining:
1. Set is equivalent to map from S to  V = {True, False}
2. Store just objects O instead of pairs (O, v) in chains.

##### Initial Constrains

- h: S --> {0, 1,2, ...., m -1} // hash value of S
- O, O' is belong to set S
- A : array of m list (chains) of object O

#### Implementation

##### find(O)

```

find(O) {
  L = A[h(O)]

  for O' in L:
  	if O' == O:
  		return True

  return False

}

```

##### add(O)

```
add(O) {

  L = A[h(O)]

  for O' in L:
  	if O' == O:
  		return

  L.append(O)

}

```

#### remove(O)

```

remove(O) {

  if not find(O):
  	return

  L = A[h(O)]
  L.erase(O)

}

```


## Hash Table

#### Defination

An implementation of set or a map using hashing is called hash table.

##### Examples in Programming Languages

###### Set:

- unordered_set in C++
- HashSet in Java
- Set in Pyhton

###### Map:

- unordered_map in C++
- HashMap in Java
- dict in Pyhton

### Conclusion

- Chaining is a technique to implement a hash table
- Memory Consumption is O(n + m)
- Operations work in time O(c + 1)
