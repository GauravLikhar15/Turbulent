// Program to find the maximum profit job sequence from a
// given array of jobs with deadlines and profits
#include <algorithm>
#include <iostream>
using namespace std;
/*
Input: Four Jobs with following 
deadlines and profits
JobID  Deadline  Profit
  a      4        20   
  b      1        10
  c      1        40  
  d      1        30
Output: Following is maximum 
profit sequence of jobs
        c, a   
        
*/

// A structure to represent a job
struct Job {
	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on
				// deadline
};

// This function is used for sorting all jobs according to
// profit
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns minimum number of platforms required
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of profit
	sort(arr, arr + n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) {
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			// Free slot found
			if (slot[j] == false) {
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}

// Driver code
int main()
{
	cout<<"How many jobs are there?\n";
	int n;
	cin>>n;
	cout<<"Enter Job ,Deadline, Profit\n";
	Job arr[n];
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
	}
	
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	// Function call
	printJobScheduling(arr, n);
	return 0;
}

