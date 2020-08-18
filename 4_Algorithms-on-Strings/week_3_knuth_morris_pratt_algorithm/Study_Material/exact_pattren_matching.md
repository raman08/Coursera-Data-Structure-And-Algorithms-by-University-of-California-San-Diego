## Exact Pattren Matching

**Input:** String T (Text) and P (Pattren)
**Output:** All such positions in T (Text) where P (Pattren) appear as substring .

### Brute Force Approch

Scan the text letter by letter till the pattren is found and continue the search till end of the string.

##### Problems

- Time of srach is O(|T|.|P|).
- Need to search all the text.

We can improve the search by skipping the postions where we know the pattren can't be found.

</br>
</br>