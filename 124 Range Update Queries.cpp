#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
  vector<long long> tree;
  vector<long long> lazy;
  int size;

public:
  SegmentTree(int n)
  {
    size = n;
    tree.resize(4 * n);
    lazy.resize(4 * n, 0);
  }
  void build(int node, int start, int end, vector<long long> &arr)
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
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }
  void update(int node, int start, int end, int l, int r, long long val)
  {
    if (lazy[node] != 0)
    {
      tree[node] += (end - start + 1) * lazy[node];
      if (start != end)
      {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (r < start || end < l)
      return;
    if (l <= start and end <= r)
    {
      tree[node] += (end - start + 1) * val;
      if (start != end)
      {
        lazy[2 * node] += val;
        lazy[2 * node + 1] += val;
      }
      return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
  }

  long long pointVal(int node, int start, int end, int idx)
  {
    if (lazy[node] != 0)
    {
      tree[node] += (end - start + 1) * lazy[node];
      if (start != end)
      {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (start == end)
    {
      return tree[node] + lazy[node];
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
    {
      return pointVal(2 * node, start, mid, idx);
    }
    else
    {
      return pointVal(2 * node + 1, mid + 1, end, idx);
    }
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  SegmentTree st(n);
  st.build(1, 0, n - 1, arr);
  vector<vector<int>> query;
  for (int i = 0; i < q; i++)
  {
    int process;
    cin >> process;
    if (process == 1)
    {
      int l, r, val;
      cin >> l >> r >> val;
      query.push_back({process, l, r, val});
    }
    else
    {
      int k;
      cin >> k;
      query.push_back({process, k});
    }
  }

  for (int i = 0; i < q; i++)
  {
    int process = query[i][0];
    if (process == 1)
    {
      int l = query[i][1], r = query[i][2], val = query[i][3];
      st.update(1, 0, n - 1, l - 1, r - 1, val);
    }
    else
    {
      int k = query[i][1];
      long long ans = st.pointVal(1, 0, n - 1, k - 1);
      cout << ans << endl;
    }
  }

  return 0;
}