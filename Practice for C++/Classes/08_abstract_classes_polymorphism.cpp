//https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem?isFullScreen=false

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache:public Cache{
    public:

    LRUCache(int capacity){
        cp = capacity;
    }

    void set(int set_key,int set_val){
        Node *N;

        if(mp.empty()){
            N = new Node(set_key,set_val);
            head = N;
            tail = N;
            mp[set_key] = N;
            return;
        }

        // check whether k is in map or not
        auto it = mp.find(set_key);
        // k is in map
        if (it != mp.end()) {

            it->second->value = set_val;

            // if it's the head
            if (it->second == head) {
                return;
            }

            //if it's the tail
            else if(it->second==tail){
                tail = tail->prev;
            }

            else{
            //if it's in the middle
            it->second->prev->next = it->second->next;
            it->second->next->prev = it->second->prev;
            }

            //move it to the head
            head->prev = it->second;
            it->second->next = head;
            it->second->prev = NULL;
            head = it->second;
        }

        //k isn't in map
        else{
            N = new Node(head->prev,head,set_key,set_val);
            mp[set_key] = N;
            head->prev = N;
            head = N;

            if(mp.size()>cp){
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = NULL;
            }
        }
    }
    

    int get(int index){
        auto it=mp.find(index);
        if(it!=mp.end()){
            return it->second->value;
        }
        else{
            return -1;
        }
    }
} ;

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
