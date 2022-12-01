r(auto w:word){
            if(!p->next[w - 'a'])p->next[w - 'a'] = new Trie();
            p = p->next[w - 'a'];
        }