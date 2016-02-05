//
//  HashTable.cpp
//  Hashing
//
//  Created by Cindy Hom on 11/4/15.
//  Copyright © 2015 Cindy Hom. All rights reserved.
//

#include "HashTable.h"


HashTable::HashTable(unsigned int t)
{
    collisions = 0;
    wordCount = 0;
    tableSize = t;
    arr = new DLL<string>[tableSize];
    
    for(int i = 0; i < tableSize; i++)
    {
        //-- denotes that there is no info in the node
        arr[i].push_back("--");
    }
    
}


HashTable::~HashTable()
{
    delete [] arr;
}


int HashTable::hash(string key)
{
    int hashVal;
    
    for(int i = 0; i < key.length(); i++)
    {
        hashVal += (key[i] * pow(37, i));
    }
    return hashVal % tableSize;
}



bool HashTable::contains(string &x)
{
    int index = hash(x);
    
    return arr[index].lookFor(x);
}



void HashTable::makeEmpty()
{
    for(int i = 0; i < tableSize; i++)
    {
        arr[i].clear();
        wordCount--;
    }

}


void HashTable::insert(string &x)
{
    int index = hash(x);
    
    if(!(arr[index].isEmpty()))
    {
        //if there is something already there a collision occurs
        collisions++;
    }
    
    if(!(contains(x)))
    {
        //if it is not in the table, use the index from the hash and push back the item
        arr[index].push_back(x);
        wordCount++;
    }
}


void HashTable::remove(string &x)
{
    int index = hash(x);
    //if item is in the hash table, remove it
    if(contains(x))
    {
        arr[index].removeItem(x);
        wordCount--;
    }

}



int HashTable::size() const
{
    return tableSize;
}


int HashTable::getWordCount() const
{
    return wordCount;
}



int HashTable::getCollisions() const
{
    return collisions;
}



void HashTable::displayTable() const
{
    for(int i = 0; i < tableSize; i++)
    {
        arr[i].display();
    }
}
