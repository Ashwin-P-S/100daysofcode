# Hashing

- Hashing is a Technique to Convert a range of key values into a range of indexes of an array

### Hash Function

- A function that maps a big number to a small integer that can be used as index in hash table
- A Hash function: hash(key) = key mod TABLE_SIZE

### Hash Table

- An Array that stores pointers to records corresponding to a given number

## Collision

- The Situation where a newly inserted key maps to an already occupied slot in the hash table
- It must be handled using some Collision Handling Techniques givern below:
    - Separate Chaining
    - Open Addressing:
        - Linear Probing
        - Quadratic Probing
        - Double Hashing

## Separate Chaining

The idea is to make each slot of hash table point to a linked list of records that have same hash function value
