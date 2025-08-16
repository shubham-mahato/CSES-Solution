#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void build(int node, int start, int end, vector<int> &arr, vector<int> &tree)
{
  if (start == end)
  {
    tree[node] = arr[start];
  }
  else
  {
    int mid = (start + end) / 2;
    build(2 * node, start, mid, arr, tree);
    build(2 * node + 1, mid + 1, end, arr, tree);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}

int minRange(int node, int l, int r, int start, int end, vector<int> &tree)
{
  if (r < start || end < l)
    return INT_MAX;
  if (l <= start and end <= r)
    return tree[node];

  int mid = (start + end) / 2;
  int left = minRange(2 * node, l, r, start, mid, tree);
  int right = minRange(2 * node+1, l, r, mid + 1, end, tree);
  return min(left, right);
}
void update(int node, int start, int end, int idx, int val, vector<int> &arr, vector<int> &tree)
{
  if (start == end)
  {
    tree[node] = val;
    arr[idx] = val;
  }
  else
  {
    int mid = (start + end) / 2;
    if (idx <= mid)
      update(2 * node, start, mid, idx, val, arr, tree);
    else
      update(2 * node + 1, mid + 1, end, idx, val,
             arr, tree);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}
int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> arr(n), tree(4 * n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  build(1, 0, n - 1, arr, tree);
  vector<vector<int>> query(q, vector<int>(3));
  for (int i = 0; i < q; i++)
  {
    cin >> query[i][0] >> query[i][1] >> query[i][2];
  }

  for (int i = 0; i < q; i++)
  {
    int process = query[i][0];
    int a = query[i][1];
    int b = query[i][2];
    if (process == 1)
    {
      a--;
      update(1, 0, n - 1, a, b, arr, tree);
    }
    else
    {
      a--;
      b--;
      int minVal = minRange(1, a, b, 0, n - 1, tree);
      cout << minVal << endl;
    }
  }

  return 0;
}