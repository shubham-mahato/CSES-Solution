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
int rangeMin(int node, int l, int r, int start, int end, vector<int> &tree)
{
  if (r < start || end < l)
    return INT_MAX;
  if (l <= start and end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  int left = rangeMin(2 * node, l, r, start, mid, tree);
  int right = rangeMin(2 * node + 1, l, r, mid + 1, end, tree);
  return min(left, right);
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
  vector<pair<int, int>> query(q);
  for (int i = 0; i < q; i++)
  {
    cin >> query[i].first >> query[i].second;
  }
  build(1, 0, n - 1, arr, tree);
  for (int i = 0; i < q; i++)
  {
    int l = query[i].first - 1;
    int r = query[i].second - 1;
    cout << rangeMin(1, l, r, 0, n - 1, tree) << endl;
  }
  return 0;
}