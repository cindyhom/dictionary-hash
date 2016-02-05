//
//  HashTable.h
//  Hashing
//
//  Created by Cindy Hom on 11/4/15.
//  Copyright © 2015 Cindy Hom. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <string>
#include "DLL.h"
#include "math.h"

using std::string;


class HashTable{
private:
    int collisions;
    int wordCount;
    unsigned int tableSize;
    DLL<string> *arr;
    
    int hash(string key);
    
public:
    HashTable(unsigned int t = 100000);
    ~HashTable();
    bool contains(string &x);
    void makeEmpty();
    void insert(string &x);
    void remove(string &x);
    int size() const;
    int getCollisions() const;
    int getWordCount() const;
    void displayTable() const;
    

};


#endif /* HashTable_h */
