/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
*/

//Better solution:

int solution(int N) { 
    int maxGap = 0;
    int gap = -1;//to avoid case of zeroes not surrounded by ones (right side) 
    for(int i=0; i<32; ++i){
        if(!((1 << i) & N))//if bit i == 0
        {
            if(gap != -1) //only if there was already 1 before
            {
                ++gap; 
            }
        }
        else //if bit i == 1
        {
            if(gap > 0)
            {
                maxGap = (maxGap > gap)? maxGap: gap;
            }
            gap = 0;
        }
    }
    return maxGap;
}  

/*
int solution(int N) { 
int maxGap = 0;
for(int i=0; i<32; ++i){
    int gap = 0;
    if((1 << i) & N){//if bit i == 1
        ++i;
        while(!((1 << i) & N)) //while bit i == 0
        {
            if(i == 31)
            {
                gap = 0;
                break;
            }           
            ++gap;
            ++i;
        }
        --i;
    }
    if (gap > maxGap)
        maxGap = gap;
    }
return maxGap;
}   */

/*int solution(int N) {
int maxGap = 0, gap = 0;
while(N%2==0)
    N/=2;
while (N>=1) {
    if((N%2)==1)
    {
     maxGap = (gap>maxGap)? gap: maxGap;
     if (N==1) 
     return maxGap;
     gap = -1;
    }
    gap++;
N/=2;
}
 return maxGap;
}
*/

/*
int solution(int N) {
int maxGap = 0, gap = -1;

while (N>=1) {
    if ((gap!=-1)&&((N%2)==0)) {// after reached first 1 only
        gap++;
    }
    if((N%2)==1)
    {
     maxGap = (gap>maxGap)? gap: maxGap;
     if (N==1) 
     return maxGap;
     gap = 0;
    }
N/=2;
}
 return maxGap;
}
*/
