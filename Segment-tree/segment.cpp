#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> segmentTree;

public:
    SegmentTree(int n);
    void build(int index, int nodeLow, int nodeHigh, int arr[]);
    int query(int index, int nodeLow, int nodeHigh, int low, int high); // min query=> min(L,R)
    void update(int index, int nodeLow, int nodeHigh, int idx, int val);
};

SegmentTree::SegmentTree(int n)
{
    segmentTree.resize(4 * n + 1);
}

void SegmentTree::build(int index, int nodeLow, int nodeHigh, int arr[])
{
    if (nodeLow == nodeHigh)
    {
        segmentTree[index] = arr[nodeLow];
        return;
    }

    int mid = nodeLow + (nodeHigh - nodeLow) / 2;
    build(2 * index + 1, nodeLow, mid, arr);
    build(2 * index + 2, mid + 1, nodeHigh, arr);

    segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}

int SegmentTree::query(int index, int nodeLow, int nodeHigh, int low, int high)
{
    // no overlap
    //  nodeL nodeH l h  or l h nodeL nodeH
    if (nodeHigh < low || high < nodeLow)
        return INT_MAX;

    // complete overlap
    //  l nodeL nodeH h
    if (nodeLow >= low && nodeHigh <= high)
        return segmentTree[index];

    // partial overlap
    int mid = nodeLow + (nodeHigh - nodeLow) / 2;

    int left = query(2 * index + 1, nodeLow, mid, low, high);
    int right = query(2 * index + 2, mid + 1, nodeHigh, low, high);

    return min(left, right);
}

void SegmentTree::update(int index, int nodeLow, int nodeHigh, int idx, int val)
{
    if (nodeLow == nodeHigh)
    {
        segmentTree[index] = val;
        return;
    }

    int mid = nodeLow + (nodeHigh - nodeLow) / 2;

    if (idx <= mid)
    {
        update(2 * index + 1, nodeLow, mid, idx, val);
    }
    else
    {
        update(2 * index + 2, mid + 1, nodeHigh, idx, val);
    }
    segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree sg(n);
    sg.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = sg.query(0, 0, n - 1, l, r);
            cout << ans << endl;
        }
        else if (type == 2)
        {
            int idx, val;
            cin >> idx >> val;
            sg.update(0, 0, n - 1, idx, val);
        }
    }
    return 0;
}
