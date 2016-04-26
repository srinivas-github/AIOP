#include <iostream>
#include <stack>
#include <algorithm>

struct Interval
{
    int start;
    int end;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void mergeIntervals(Interval arr[], int n)
{
    if ( n <= 0)
        return ;
    std::stack<Interval> s;
    std::sort(arr, arr+n, compareInterval);

    s.push(arr[0]);

    for(int i = 1; i < n; i++)
    {
         Interval top = s.top();

	 if (top.end < arr[i].start)
	     s.push(arr[i]);
	 else if (top.end < arr[i].end)
	 {
	     top.end = arr[i].end;
	     s.pop();
	     s.push(top);
	 }
    }

    printf("Merged Intervals..\n");
    while (!s.empty())
    {
        Interval t = s.top();
	printf("[ %d,%d]", t.start, t.end);
	s.pop();
    }
}


int main()
{
    Interval arr[]  = { {1,3}, {2,4}, {5,7}, {7.8}};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
