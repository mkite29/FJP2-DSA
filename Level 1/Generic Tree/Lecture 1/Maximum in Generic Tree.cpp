int max1(Node *node)
{
  int ans = node->data;
  for(auto &i : node->children){
      ans = max(ans,max1(i));
  }
  return ans;
}
