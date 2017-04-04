#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define TABLE_SIZE 128
template <typename k,typename V>
class hashnode {
	public:
		hashnode(const k &key, const V &value):key(key),value(value){}
		k key;
		V value;
		//hashnode *next;
};

template <typename k,typename V>
class HashMap {
	private:
		hashnode<k,V> **table;
	public:
		HashMap() {
			table = new hashnode<k,V> *[TABLE_SIZE]();
			for(int i = 0; i < TABLE_SIZE; i++) {
				table[i] = NULL;
			}
		}

		~HashMap() {
			for(int i =0; i < TABLE_SIZE; i++) {
				if(table[i]!=NULL) {
					//table[i] = NULL;
					delete table[i];

				}
			}
			delete[] table;
		}

		k hashfunc(k key) {
			return key % TABLE_SIZE;
		}

		void insert(k key, V value){
			k hash = hashfunc(key);
			while(table[hash] != NULL && table[hash]->key != key) {
				hash = hashfunc(hash+1);
			}
			if(table[hash] != NULL) {
				delete table[hash];
			}
			table[hash] = new hashnode<k,V> (key,value);
		}
		V search(k key) {
			k hash = hashfunc(key);
			while(table[hash] != NULL && table[hash]->key != key) {
				hash = hashfunc(hash+1);
			}
			if(table[hash] == NULL) {
				return -1;
			}else{
				return table[hash]->value;
			}
		}
		void remove(k key){
			k hash = hashfunc(key);
			while(table[hash] != NULL) {
				if(table[hash]->key == key) {
					break;
				}
				hash = hashfunc(hash+1);
			}
			if(table[hash] != NULL) {
				delete table[hash];
			}
			cout<<"Element removed";
		}
};
#endif
