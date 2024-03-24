struct Node {
	Node* links[26];
	int cnt = 0, ew = 0,min_idx = -1, sz = -1;

	bool contains(char c) {
		return links[c-'a'] != nullptr;
	}
	void put(char c, Node* node) {
		links[c-'a'] = node;
	}
	Node *get(char c) {
		return links[c-'a'];
	}
	void set() {cnt++;}
	void set2() {ew++;}
	void deset() {cnt--;}
	void deset2() {ew--;}
	int getcnt() {return cnt;}
	int getew() {return ew;}

};
class Trie {
private: Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word, int id) {
		Node* node = root;
		for(int i=0; i<word.length(); i++) {
			if(!node->contains(word[i])) node->put(word[i], new Node());
			node = node->get(word[i]); 
            if(node->min_idx == -1) {
                node->min_idx = id;
                node->sz = word.size();
            }
            else {
                if(word.size() < node->sz) {
                    node->min_idx = id;
                    node->sz = word.size();
                }
            }
			node->set();
		}
		node->set2();
	}

	int cntequalto(string word) {
		Node* node = root;
		for(int i=0; i<word.length(); i++) {
			if(node->contains(word[i])) node = node->get(word[i]);
			else return 0;
		}
		return node->getew();
	}
	int startWith(string prefix) {
		Node* node = root;
		for(int i=0; i<prefix.length(); i++) {
			if(node->contains(prefix[i])) node = node->get(prefix[i]);
			else return 0;
		}
		return node->getcnt();
	}
	void erase(string word) {
		Node* node = root;
		for(int i=0; i<word.length(); i++) {
			if(node->contains(word[i])) {
				node = node->get(word[i]);
				node->deset();
			} else return;
		}
		node->deset2();
	}
    int lcp(string &uler) {
        Node* node = root;
        for(char c: uler) {
            if(node->contains(c)) {
                node = node->get(c);
            }else {
                return node->min_idx;
            }
        }
        return node->min_idx;
    }
    
};

class Solution {
public:
    
    vector<int> stringIndices(vector<string>& a, vector<string>& q) {
        int n = q.size();
        vector<int> res(n);
        int itr = 0;
        Trie T;
        int mn = 1e9, rika = -1; 
        for(int i=0; i<a.size(); i++) {
            if(mn > a[i].size()) {
                mn = a[i].size();
                rika = i;
            }
        }
        itr = 0;
        for(auto x: a) {
            string uler = x;
            reverse(begin(uler), end(uler));
            
            T.insert(uler, itr++);
        }
        
        for(int i=0; i<n; i++) {
            string s = q[i]; reverse(begin(s), end(s));
            // cout << s << ' ' << T.cntequalto(s) << '\n';
            int val = T.lcp(s);
            res[i] = (val == -1 ? rika : val);
        }
        return res;
        
        
    }
};
