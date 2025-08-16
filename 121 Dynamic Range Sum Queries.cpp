#include <iostream>
#include <vector>

const int INF = 1e9 + 5;
using namespace std;

class SegmentTree
{
  vector<long long> tree;
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
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }
  long long rangeSum(int node, int l, int r, int start, int end)
  {
    if (r < start || end < l)
      return 0;
    if (l <= start and end <= r)
      return tree[node];
    int mid = (start + end) / 2;
    long long left = rangeSum(2 * node, l, r, start, mid);
    long long right = rangeSum(2 * node + 1, l, r, mid + 1, end);
    return (left + right);
  }
  void update(int node, int start, int end, int idx, int val, vector<int> &arr)
  {
    if (start == end)
    {
      arr[idx] = val;
      tree[node] = val;
    }
    else
    {
      int mid = (start + end) / 2;
      if (idx <= mid)
      {
        update(2 * node, start, mid, idx, val, arr);
      }
      else
      {
        update(2 * node + 1, mid + 1, end, idx, val, arr);
      }
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }
};
int main()
{
  int n, q;
  cin >> n >> q;
  SegmentTree st(n);
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  st.build(1, 0, n - 1, arr);
  vector<vector<int>> query(q, vector<int>(3));
  for (int i = 0; i < q; i++)
  {
    cin >> query[i][0] >> query[i][1] >> query[i][2];
  }
  for (int i = 0; i < q; i++)
  {
    int process = query[i][0], a = query[i][1], b = query[i][2];

    if (process == 1)
    {
      a--;
      st.update(1, 0, n - 1, a, b, arr);
    }
    else
    {
      a--;
      b--;
      long long sum = st.rangeSum(1, a, b, 0, n - 1);
      cout << sum << endl;
    }
  }

  return 0;
}
