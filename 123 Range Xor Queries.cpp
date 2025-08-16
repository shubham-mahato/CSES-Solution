#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
  vector<int> tree;
  int size;

public:
  SegmentTree(int n)
  {
    size = n;
    tree.resize(4 * n);
  }
  void build(int node, int start, int end, vector<int> &arr)
  {
    if (start == end)
    {
      tree[node] = arr[start];
    }
    else
    {
      int mid = (start + end) / 2;
      build(2 * node, start, mid, arr);
      build(2 * node + 1, mid + 1, end, arr);
      tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
  }
  int rangeXor(int node, int start, int end, int l, int r)
  {
    if (r < start || end < l)
      return 0;
    if (l <= start and end <= r)
      return tree[node];
    int mid = (start + end) / 2;
    int left = rangeXor(2 * node, start, mid, l, r);
    int right = rangeXor(2 * node + 1, mid + 1, end, l, r);
    return (left ^ right);
  }
};
int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  SegmentTree st(n);
  st.build(1, 0, n - 1, arr);
  vector<pair<int, int>> query(q);
  for (int i = 0; i < q; i++)
  {
    cin >> query[i].first >> query[i].second;
  }
  for (int i = 0; i < q; i++)
  {
    int l = query[i].first - 1, r = query[i].second - 1;
    int ans = st.rangeXor(1, 0, n - 1, l, r);
    cout << ans << endl;
  }
  return 0;
}