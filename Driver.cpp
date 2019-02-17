/*
NAME: DAVIS KIEU
SUBJECT: CO-SCI 832
DESCRIPTION: Project revolves around using a PQ & Heap to implement how a printer handles job requests. Simulates a printer Queue and prints jobs in accordance to priority.
User is in control of serveral operations related to the simulated printer.
*/

#include<iostream>
#include"PQ.h"

using namespace std;

//ASSIGNING PRIORITY VALUES
enum PRIORITIES {STUDENT,TA,INSTRUCTOR}; 

//START CLASS JOB DEFINITION
class Job
{
private:
	int priority, jobNumber;
public:
	Job() {};
	Job(int, int);
	int getPriority();
	int getJobNumber();
	bool operator >(const Job&);
	bool operator <(const Job&);
	bool operator <=(const Job&);
	bool operator >=(const Job&);
};
Job::Job(int priority, int jobNum)
{
	this->priority = priority;
	jobNumber = jobNum;
}
int Job::getPriority()
{
	return priority;
}
int Job::getJobNumber()
{
	return jobNumber;
}

// comparision of job Number is counter intuitive because the least number is greater priority

bool Job::operator<(const Job& other)
{
	return (this->priority == other.priority) ? (this->jobNumber > other.jobNumber) : (this->priority < other.priority);
}
bool Job::operator>(const Job& other)
{
	return (this->priority == other.priority) ? (this->jobNumber < other.jobNumber) : (this->priority > other.priority);
}
bool Job::operator<=(const Job& other)
{
	return (this->priority == other.priority) ? (this->jobNumber >= other.jobNumber) : (this->priority <= other.priority);
}
bool Job::operator>=(const Job& other)
{
	return (this->priority == other.priority) ? (this->jobNumber <= other.jobNumber) : (this->priority >= other.priority);
}

// END OF JOB CLASS DEFINITION 

//JOB COUNTER
int jobCount = 1;

//FUNCTION PROTOTYPES
char selection();
void addJob(PQ<Job>&);
void printJob(PQ<Job>&);
void viewJobs(PQ<Job>&);

int main()
{
	const int MAX = 100;

	PQ<Job> jobs(MAX);

	do
	{
		switch (selection())
		{
		case '1':
		{
			addJob(jobs);
			break;
		}
		case '2':
		{
			printJob(jobs);
			break;
		}
		case '3':
		{
			viewJobs(jobs);
			break;
		}
		case '4':
		{
			cout << "Ending Program...\n";
			return 0;
		}
		default:
		{
			cout << "\nNo such Selection!\n\n";
		}
		}
	} while (1);
}
char selection()
{
	char choice;

	cout << "Printer Queue\n"
		<< "=========\n"
		<< "1.Add job\n"
		<< "2.Print job\n"
		<< "3.View jobs\n"
		<< "4.Exit\n";

		cout << "Enter Choice: ";
		cin.get(choice);
		cin.ignore();

		return choice;
}
void addJob(PQ<Job>& pq)
{
	char choice;

	cout << "Who is requesting the job?\n";
	cin.get(choice);
	cin.ignore();

	if (choice == 'i' || choice == 'I')
		pq.Enqueue(*(new Job((int)INSTRUCTOR,jobCount++)));
	else if(choice == 't' || choice == 'T')
		pq.Enqueue(*(new Job((int)TA, jobCount++)));
	else if(choice == 's' || choice == 'S')
		pq.Enqueue(*(new Job((int)STUDENT, jobCount++)));
}
void printJob(PQ<Job>& pq)
{
	Job item;

	if(pq.isEmpty())
		cout << "No jobs to print in queue!\n";
	else
	{
		pq.Dequeue(item);
		
		int priority = item.getPriority();

		if((int)INSTRUCTOR == priority)
			cout << "Now printing Job # " << item.getJobNumber() << " : Instructor." << endl;
		else if ((int)STUDENT == priority)
			cout << "Now printing Job # " << item.getJobNumber() << " : Student." << endl;
		else if ((int)TA == priority)
			cout << "Now printing Job # " << item.getJobNumber() << " : TA." << endl;
	}
}
void viewJobs(PQ<Job>& pq)
{
	Job item;
	PQ<Job> copy(pq);	

	if (copy.isEmpty())
		cout << "No jobs to view in queue!\n";
	else
	{
		do
		{
			copy.Dequeue(item);

			int priority = item.getPriority();

			if ((int)INSTRUCTOR == priority)
				cout << "Job # " << item.getJobNumber() << " : Instructor." << endl;
			else if ((int)STUDENT == priority)
				cout << "Job # " << item.getJobNumber() << " : Student." << endl;
			else if ((int)TA == priority)
				cout << "Job # " << item.getJobNumber() << " : TA." << endl;
			
		} while (!copy.isEmpty());

		}
	}
