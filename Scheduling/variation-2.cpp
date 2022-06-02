/**
 * Min meeting rooms required to accomodate all the meetings
 *
 * Given [start,end] of n meetings, return min meeting rooms required.
 *
 * I/p-
 * [[0, 30],[5, 10],[15, 20]]
 * 
 * 
 * 1 meet         2 meets      2meets       1meet                ->no. of meetings happening at that pt of time      
 * x-----------------------------------------------x
 *           x------------x
 *                        x-----------x
 * 
 * 0---------5-----------10-----------15----------30-------------------Infinity
 * 
 * 
 * Max 2 meetings happen at a time hence 2 meeting rooms are enough
 * 
 * 
 * Iterate through all the time points, if that point belongs to "start" set then increament the count of meeting rooms by 1 and if that point belongs to "end" set then decrement the count of meeting rooms by 1 as 1 meeting has ended. count stores the meeting rooms required at any time point.
 * 
 * ans=max(all count values) 
 * 
 * 
 * 
 * Approach- store start and end time in separate arrays and sort them
 * 
 * start-[0, 5, 15]
 * end- [10, 20, 30]
 * 
 * have 2 pointers pointing 0 index of both arrays
 * 
 * 
 *  0 5 15
 *  ^
 * 
 *  10 20 30
 *  ^
 * 
 * if start[i]<end[j]
 *      count++
 *      ans=max(ans, count)
 *      i++
 * else 
 *     count--
 *     j++
 *  
 */