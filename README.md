# dictionary-hash
Spellchecker that checks if words are found in the dictionary hash table

### Instructions:
1. Run the program with 3 command line arguments in the following order: 
   + dictionary file
   + test file
   + personal dictionary file.
2. Results will output to a file, indicating whether the words in the test file are correctly spelled according to the dictionary file and personal dictonary file.

### Overview:
I created a HashTable class that uses separate chaining. Each index of the array has a doubly linked list. Initially there is a “--“ to denote an empty spot. I calculate the hash value with the hash function that converts the string into a number by using its ascii values and Horner’s rule. I mod by the tableSize so that it can wrap around the table if it has to find an index. There is a contains function that checks if the word is in the hash table. The insert function checks if the list at the index is not denoted as empty, then it increments collisions. If the object is in not already in the table, it will be pushed back into the linked list at the proper index and increment the word count. The remove item checks if the word is in the hash table, and if it is, the item is removed and wordCount is decremented. The display table function traverses the table and calls the display function for the doubly linked list that traverses and prints out each list. In main I created an ofstream object so that I can write to a file. The command line arguments that are added should be in the order of dictionary, test file, and then personal dictionary. The program still runs if there is no personal dictionary (just uses dictionary and test file). It takes each word, takes away the ‘/’ and everything after it, changes it to lowercase and hashes all of the words in the dictionaries into the hash table. Then it goes through the test file also taking away any ‘/’ and everything after it, changes it to lowercase, and checks if that value is in the hash table. If it is then the word is spelled correctly. If the word is not found in the hash table, the word is considered to be spelled incorrectly.
