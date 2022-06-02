/**
 * N meetings in 1 room
 * 
 * Given schedules of some meetings, return how many max meetings can occur in given 1 room.
 * 
 * Note- We "dont" have to find how many meeting rooms are required (it is fixed at 1) rather find how many meetings can happen in given 1 room
 * 
 * Intuition-> Jo meetings jaldi khatam ho rhi hai unko pehle krwa do, jaldi khali hoga to baki meetings ko bhi mauka milega.
 * 
 * => sort by end time
 * 
*/

 #include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second < b.second)
        return true;
    if (a.second == b.second)
        return a.first < b.first;
    return false;
}

int maxMeetings(int start[], int end[], int n)
{
    // Max meetings in 1 room not maximum rooms for meetings

    // Intuition- Let the meetings which end early be the allowed the room first.

    // sort by end time

    vector<pair<int, int>> schedule;

    for (int i = 0; i < n; i++)
    {
        schedule.push_back({start[i], end[i]});
    }

    sort(schedule.begin(), schedule.end(), cmp);

    int ans = 0;
    int last = 0;

    for (int i = 0; i < n; i++)
    {
        if (schedule[i].first > last)
        {
            ans++;
            last = schedule[i].second;
        }
    }

    return ans;
}