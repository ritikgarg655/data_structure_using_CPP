# Data Structure using C++
This repository contain my practice done to learn DataStructure.

## Each folder contain:
  1. Code using class.
  2. Implementation using STL library.

## Folder content:
  ### 1. array:<br>
     A. static and dynamic array implementation.
     B. Usin STL implementation.
  ### 2. Linked List: 
     The problem with array is that it is not efficient in terms of memory. It always double the size, loss 
     of memory,but it is not in linked list but required double size, another to save addrress.
     Time comlexity of following operation in linked list:
       A. Insertion: O(N)
       B. Deletion:  O(N)
       C. Access:    O(N)
  ### 3. Stack:
     It is LIFO (last in, first out).
     Uses of stack:
        A. Used to undo in text editor.
        B. Tower of annoy problem.
        C. To check brackets in code in text editor.
        D. Used in dfs.
  
  ### 4. Queue:
    Queue implementaion using single linked list. Queue is FIFO (first in, first out)
    Time comlexity of following operation in queue:
       A. ENQUEUE: O(1)
       B. DEQUEUE:  O(1)
       C. SIZE:    O(N)
  ### 5. Periority queue:
    In periority queue, each element has some periority and according to which enqueue, dequeue and other function
    is implemented. Binary tree is used for implmentation. Hash table is used to remove element value wise in 
    O(Log N).
      A. Enqueue: O(Log N)
      B. Dequeue: O(Log N)
      C. Size: O(1)
      D. Remove_using value: O(Log N)
      E. Dequeue using index: O(Log N)
  ### 6. Union find:
     Union find is used to uinon two set and find is used to find in which set value belongs.
      A. union: aplha(n)
      B. Find: aplha(n)
      C. construct: O(n)
  ### 7. BST (Binary search tree):
    BST is tree which is acylic and has maximum two child for each parent. BST child has some constraint i.e. Left
    child is less than parent and right child is more than parent with respect to comparision function.
       A. Add element: O(Log N) 
       B. Remove element: O(Log N)
       C. Present: O(Log N)
     Travelsal in BST:
       A. Preorder (first left).
       B. Inorder.
       C. Postorder (first right).
       D. Level (level wise).
