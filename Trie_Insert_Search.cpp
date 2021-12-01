/*   /\_/\    - Trie với string chỉ chứa chữ số và chữ cái.
    (= ._.)   - Add: Thêm 1 string vào Trie.
    / >?  \>$ - Search: Kiểm tra xem Trie có chứa string đó hay không.
*/
struct Node{
   vector<int> pos;
   bool endd;
   Node() {pos.resize(80); endd = false;}
};
struct Trie{
   vector<Node> info;
   int CNT = 0;
   void Add(string str) {
      int cur = 0, id;
      for (char ch : str) {
         id = ch-'0';
         if (!info[cur].pos[id]) {
            info[cur].pos[id] = ++CNT;
            info.push_back(Node());
         }
         cur = info[cur].pos[id];
      }
      info[cur].endd = true;
   }
   bool Search(string str) {
      int cur = 0, id;
      for (char ch : str) {
         id = ch-'0';
         if (!info[cur].pos[id]) return false;
         cur = info[cur].pos[id];
      }
      return info[cur].endd;
   }
};
int main()
{
   Trie a;
   a.info.push_back(Node()); // Phải có dòng này nhe
}
