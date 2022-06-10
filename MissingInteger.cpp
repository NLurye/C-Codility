#include <algorithm>
#include <vector>
#define SIZE 1000000
using namespace std;

int solution(vector<int> &A) {
    int size = A.size();
    vector<bool> C(SIZE); //counting appearance starting from one
    for(int i = 0; i<size; i++)
        if(A[i]>0)
            C[A[i]-1] = true;
    auto it = find(C.begin(), C.end(), false);
    return (it == C.end())? SIZE+1: it-C.begin()+1;
}

/*
Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/
