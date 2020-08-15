## Approximate Pattren Matching

#### Problem Statement

**Input:** A string Pattren, A string Text, and integer d.
**Output:** All the postition in the text where the string Pattren appears as a substring with most d mismatched.

#### Solution

- Apply the BWT in the text.
- Reversed the Pattren in the text. Called in R_pattren.
- Find all the occurance of the first symbol of the R_pattren in first column of BWT(Text).
- Now find the patten with atmost d mutation in the last column of th BWT(Text).
- Now use first-last property and repeat the above two steps till pattren is found.