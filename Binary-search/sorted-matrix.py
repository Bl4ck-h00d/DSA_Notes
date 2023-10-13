
# 668. Kth Smallest Number in Multiplication Table [Hard]
# Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table? Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.

# Example :

# Input: m = 3, n = 3, k = 5
# Output: 3
# Explanation: 
# The Multiplication Table:
# 1	2	3
# 2	4	6
# 3	6	9

# The 5-th smallest number is 3 (1, 2, 2, 3, 3).
# For Kth-Smallest problems like this, what comes to our mind first is Heap. Usually we can maintain a Min-Heap and just pop the top of the Heap for k times. However, that doesn't work out in this problem. We don't have every single number in the entire Multiplication Table, instead, we only have the height and the length of the table. If we are to apply Heap method, we need to explicitly calculate these m * n values and save them to a heap. The time complexity and space complexity of this process are both O(mn), which is quite inefficient. This is when binary search comes in. Remember we say that designing condition function is the most difficult part? In order to find the k-th smallest value in the table, we can design an enough function, given an input num, determine whether there're at least k values less than or equal to num. The minimal num satisfying enough function is the answer we're looking for. Recall that the key to binary search is discovering monotonicity. In this problem, if num satisfies enough, then of course any value larger than num can satisfy. This monotonicity is the fundament of our binary search algorithm.

# Let's consider search space. Obviously the lower bound should be 1, and the upper bound should be the largest value in the Multiplication Table, which is m * n, then we have search space [1, m * n]. The overwhelming advantage of binary search solution to heap solution is that it doesn't need to explicitly calculate all numbers in that table, all it needs is just picking up one value out of the search space and apply enough function to this value, to determine should we keep the left half or the right half of the search space. In this way, binary search solution only requires constant space complexity, much better than heap solution.

# Next let's consider how to implement enough function. It can be observed that every row in the Multiplication Table is just multiples of its index. For example, all numbers in 3rd row [3,6,9,12,15...] are multiples of 3. Therefore, we can just go row by row to count the total number of entries less than or equal to input num. Following is the complete solution.

def findKthNumber(m: int, n: int, k: int) -> int:
    def enough(num) -> bool:
        count = 0
        for val in range(1, m + 1):  # count row by row
            add = min(num // val, n)
            if add == 0:  # early exit
                break
            count += add
        return count >= k                

    left, right = 1, n * m
    while left < right:
        mid = left + (right - left) // 2
        if enough(mid):
            right = mid
        else:
            left = mid + 1
    return left 

'''
📝 Proof: How do we know ans will always exist in multiplication table?

Every time, we are only checking if count(mid) >= k and running the process till L & R narrow down to each other. But how do we know ans always exists in table?

For eg. Consider a 3x5 table -

m = 3,  n = 5,  k = 9

1  2  3  4   5
2  4  6  8   10
3  6  9  12  15

= > [1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 8, 9, 10, 12, 15]
We have count(7) = count(6) = 9. But 7 doesn't exist in our table
Let's say ans doesn't exist in the table. Then, we must have some other number ans' smaller than ans which does exist in table and for which count(ans') >= k. (Why ans' must be smaller than ans? Because if ans doesn't exist in table and count(ans) >= k, then there must be smaller number for which count(.) >= k and we need to find smallest such number.)

    But, in the above solution, ans is the smallest number for which we found count(mid) >= k and then marked mid as ans. We can surely say that it's smallest since we also ran further search over range[L, mid-1] and we didnt find any count([L...mid-1]) >= k.

    From above two observation, we must conclude ans'=ans which is our final answer and does exist in the table.
'''