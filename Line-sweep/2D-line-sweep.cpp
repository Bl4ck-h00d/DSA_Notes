// https: // leetcode.com/problems/rectangle-area-ii/

// https : // www.evernote.com/client/web?login=true&newReg=true#?b=5a3710da-b7cc-9757-b3d0-e5cb875c2dea&n=b8bae930-c60b-cb3c-7315-724351746966&

#include<bits/stdc++.h>
        using namespace std;

static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
class Solution
{
public:
    int mod = 1e9 + 7;
    int rectangleArea(vector<vector<int>> &rectangles)
    {

        /*
            Intuition-

            -> Assume we are dividing the given figure into segments by drawing horizontal lines
            -> at every given y-coordinates
            -> we assume a segment between current Y coord and just prev y-coordinate
            -> height=currY-prevY
            -> Now we sweep the segment from  left to right
            -> When we encounter an x-coordinate, we check if that rectangle has a part in this                     segment or not
            -> We then assume the width swept as x-coord of start of that rect and end x-coord of                   end of that particular rect
            -> If the next rect has start before the end of prev one then we need not consider that
               as it was already considered therefore start=max(start,prevEnd);

     __________________________________________________________y3
                          |/ / / / / / |
     _____________________|/_/_/_/_/_/_|__________________ y2
                    |\ \ \|\ \|/ / / / |
                    |\ \ \|\ \|/ / / / |
                    |\ \ \|\ \|/ / / / |
            ----------------------------------------------------- y1
        */

        /**
            2D-Line sweep algo

            -> Sort the rectangles according to x-coord
            -> Scan from bottom-to-top (y-coords)
            -> On hitting a height
            -> Scan from left to right (x-coords) and add the area of rectangles that completely
                occupies y and y-prev range height.
        */

        set<int> yScan; // store y-coords

        for (auto rectangle : rectangles)
        {
            yScan.insert(rectangle[1]);
            yScan.insert(rectangle[3]);
        }

        sort(rectangles.begin(), rectangles.end(), cmp); // sort by x-coord
        long long area = 0;

        // scan bottom to top
        int prevY = *yScan.begin();
        for (auto y : yScan)
        {
            long long height = y - prevY;
            long long x_start = 0;
            long long x_end = 0;

            // scan left to right
            for (auto rectangle : rectangles)
            {
                // check if rectangles are completely overlap with height.
                if (rectangle[1] <= prevY && rectangle[3] >= y)
                {
                    x_start = max((long long)rectangle[0], x_end); // jumps the overlap case
                    x_end = max((long long)rectangle[2], x_end);
                    area += (x_end - x_start) * (long long)height % mod;
                }
            }
            prevY = y;
        }
        return area % mod;
    }
};