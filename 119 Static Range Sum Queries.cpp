#include <iostream>
#include <vector>
using namespace std;

void build(int node, int start, int end, vector<long long> &arr, vector<long long> &tree)
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
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

long long rangeQuery(int node, int l, int r, int start, int end, vector<long long> &tree)
{
  if (r < start || end < l)
    return 0;
  if (start >= l and end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  long long left = rangeQuery(2 * node, l, r, start, mid, tree);
  long long right = rangeQuery(2 * node + 1, l, r, mid + 1, end, tree);
  return left + right;
}
int main()
{
  int n, q;
  cin >> n >> q;
  vector<long long> arr(n), tree(4 * n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<pair<int, int>> query(q);
  for (int i = 0; i < q; i++)
  {
    cin >> query[i].first >> query[i].second;
  }
  build(1, 0, n - 1, arr, tree);
  for (int i = 0; i < q; i++)
  {
    int l = query[i].first - 1, r = query[i].second - 1;

    long long ans = rangeQuery(1, l, r, 0, n - 1, tree);
    cout << ans << endl;
  }
  return 0;
}