# Linked List
### Dsa

# Cicular Linked List

- Program to Reverse the Circular Linked List

## Logic behind the Reversing

- Initialize Three Pointer Variables
    - last = head
    - cur = head->link
    - prev = head
, where head is pointing the head node

- Move head node ahead

- Move head node ahead [head = head -> link]
- Link current node with previous node [cur -> link = prev]
- Make previous node as current node [prev = cur]
- Make current node as head node [cur = head]
- Repeat Step 3 to 6 till head is not equal to last [head != NULL]

- After linking all nodes in loop, link the current node with previous node [cur -> link = prev]
- Finally, move head at its position. Move head node to last node [head = prev]