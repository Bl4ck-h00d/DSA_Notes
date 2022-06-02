/**
 * Maximum events a person can attend
 *
 * Given schedules of some events. We can attend a particular event at any day in the given schedule range i.e, if an event starts at "s" and ends at "e", I can attend that event at any day between s<= d <= e.
 *
 * We can attend 1 event at a time
 *
 * I/P- [[1,5],[1,5],[1,5],[2,3],[2,3]]
 *
 * Intuition-
 * Apan ko max events attend krne hai to jo events jaldi khatam ho rhe hain unko pehle attend kr lete hai aur jo abhi lambe chalenge unko baad mein bhi kr skte hain
 *
 * iska mtlb => sort by ending day
 *
 * Ab apan dekhenege ki what is the next day jab main free/available hu aur vo day us particular event k schedule k range mein h
 *
 * Greedily events attend krna hai aur date bhi greedily select krna hai
 *
 *
 * https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
 */

#include <bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1])
        return a[0] < b[0];
    return false;
}


int maxEvents(vector<vector<int>> &events)
{

    /**
        Intuition- I want to attend maximum events. To jo event jaldi khatam ho rha hai usko pehle attend kr lete hai aur jo abhi chalenge lamba unko baad mein bhi kr skte h.

        => sort by end time

        Now for each event we will look for what next day I am available, to attend this event?
        If no day is available in that event range we move on
        else we will attend that event and remove that day
    */

    int n = events.size();

    // sort by end time
    sort(events.begin(), events.end(), cmp);

    int lastDay = events[n - 1][1];

    set<int> days; // Available days

    for (int i = 1; i <= lastDay; i++)
    {
        days.insert(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        // can I attend this event?
        int start = events[i][0];
        int end = events[i][1];

        // Get the next available day that matches the schedule
        auto day = days.lower_bound(start); // day greater than or equal to start day

        // No day available
        if (day == days.end() || *day > end)
            continue;

        // some day is available.
        ans++;           // we can attend this event
        days.erase(day); // remove this day from avaialble days set.
    }

    return ans;
}