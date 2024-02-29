/*
Design a data structure that follows the constraints of a Least Recently Used 
(LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.


*/

//Brute force: Using vector of pairs
//T.C = Quadratic
//S.C = 

class LRUCache {
    vector<pair<int,int>> v;
    int n;
public:
    LRUCache(int capacity) {
        //constructor
        n = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i<v.size(); i++){
            if(v[i].first == key){
                int val = v[i].second;
                pair<int,int> temp = v[i];
                v.erase(v.begin()+i);
                v.push_back(temp);

                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i<v.size();i++){
            if(v[i].first == key){
                v.erase(v.begin()+i);
                v.push_back({key,value});
                return;
            }
        }
        if(v.size()==n){
            v.erase(v.begin());
            v.push_back({key,value});
        }else{
            v.push_back({key,value});
        }
    }
};

//Optimised solution using Doubly LL

//Watch video here: https://www.youtube.com/watch?v=81h8O-0U5oo
//and also striver's video

class LRUCache {
    list<int> dll;
    map<int, pair<list<int>::iterator,int>> mp;
    int n;
public:
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makerecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);

        mp[key].first = dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        makerecentlyUsed(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second = value;
            makerecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
            n--;
        }

        if(n<0){
            int key_to_delete = dll.back();
            mp.erase(key_to_delete);

            dll.pop_back();

            n++;
        }
    }
};