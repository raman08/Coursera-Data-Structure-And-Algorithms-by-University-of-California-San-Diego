## Dynamic Array:

### Defination

Abstract data type with the following operations (at a minimun):

1. **Get(i):** return element at location i
2. **Set(i, val):** sets element i to val
3. **PushBack(val):** Adds val to the end
4. **Remove(i):** Remove element at location i
5. **Size():** return size of the array

All the operations must be in constant time.

#### Store

- **arr:** dynamically-allocated array
- **capicity:** size of arr
- **size:** number of current element in arr

### Implementation

#### Get(i)

```

Get(i){

  if i < 0 or i >= size:
  	ERROR: index out of range

  return arr[i]

}

```

#### Set(i, val)

```

Set(i, val) {

  if i < 0 or i >= size:
  	ERROR: index out of range

  arr[i] = val

}

```

#### PushBack(val)

```

PushBack(val) {

  if size == capicity:
  	allocate new_arr[2*capicity]

  	for i from 0 to size - 1:
  		new_arr[i] = arr[i]

  	free arr
  	arr = new_arr
  	capicity = 2*capicity

  arr[size] = val
  size = size + 1

}

```

#### Remove(i)

```

Remove(i) {
  if i < 0 or i >= size:
  	ERROR: index out of range

  for j from i to size - 2
  	arr[j] = arr[j + 1]

  size = size + 1

}

```

#### Size()

```

Size(){
	return size
}

```


### Languages

- **C++ :**  vector

- **Java :** ArrayList

- **Python :** list

#### Runtime


| **Operation**  | **Time**  |
|:---            |:---       |
| Get(i)         | O(1)      |
| Set(i, val)    | O(1)      |
| PushBack(val)  | O(n)      |
| Remove(i)      | O(n)      |
| Size(i)        | O(1)      |

