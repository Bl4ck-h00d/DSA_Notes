// QUESTION : We are given array of jobs, Job contains the job's deadline and it's profit. We need to find the maximum profit that can be gained.

// THOUGHT PROCESS
// Basically what we do is we take that job first whose profit is max and will do it on it's deadline , if that slot is free.
// and by doing this what happens is that sabse bade profit sabse phle hore and jitna deadline ke paas hai utne zyada kam krne ka time milega.

// That's why max jobs can be done.
// Now to manage the slots , we create an array of size 'maxTime' (which is the maximum deadline time among all the jobs).

// ALGORITHM : GREEDY

// First we sort the array accourding to the profit.
// 2) Now we iterate over the array and then caluate the maximum deadline among all the jobs available [ie. maxTime]
// 3) Now we create an array 'timeslots' that will check if that paticular timeslot is free or not
// 4) Now we take the first job (ie the one with maximum profit)
// 4.1) Now starting from the point of it's deadline we keep checking the timeslot if it's free or not and if it's free we fill that spot
// and add that job's profit to the total_profit ( also break the loop ), otherwise we keep checking the previous timeslots
// 5) Now return the jobcount and total_profit.