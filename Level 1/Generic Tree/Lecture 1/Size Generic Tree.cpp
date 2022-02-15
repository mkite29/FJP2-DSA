int size(Node *node){
   int s = 1;
   for(auto &i : node->children)
    s += size(i);

    return s;

}
