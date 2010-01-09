#include "process.h"

process_list_t procs;

int UpTime;
int latest;

int Process::GetLatestPid()
{
	return latest;
}

// proc_state_t is for fork()ing
process_t Process::NewProcess(proc_state_t state)
{
	process_t newproc;
	int NewPid = Process::GetLatestPid() + 1;
	procs[NewPid]->status = PROC_ACTIVE;
	if (state) procs[NewPid]->state = state;
	procs[NewPid]->Ticket->Active = false;
	latest++;
	newproc->pid = NewPid;
	return newproc;
}

int Process::IdleTask()
{
	for(;;) UpTime++;
}

int Process::GetLuckyProcess()
{
	int Pid;
	int Pid2;
	Pid = Process::GetLatestPid();
	Pid2 = Pid;
	do {
		if (Processes[Pid]->State == PROCESS_KILLED)
		{
			Pid--;
		}
		else
		{
			Processes[Pid]->Ticket->Active = true;
			Processes[Pid]->Ticket->Number = rand()%100;
			Pid--;
		}
	} while (Pid != -1);
	
	// Reiterate all over the processes and test if their number is lucky...
	int highest_so_far;
	int win_pid;
	do {
		if (Processes[Pid2]->State == PROCESS_KILLED)
		{
			Pid--;
		}
		else
		{
			if (Processes[Pid2]->Ticket->Number > highest_so_far)
			{
				// a likely winner...
				highest_so_far = Processes[Pid]->Ticket->Number;
				win_pid = Pid2;
			}
		}
	}
	
	// We guess we found a winner... and it is...
	return win_pid;
}

int Process::LotterySch()
{
	int pid;
	int iffy;
	for (;;) {
		pid = Process::GetLuckyProcess();
		Process::SwitchTo(pid);
		// Wait...
		do {
			iffy++;
			iffy--;
			iffy++;
			iffy--;
			iffy++;
			iffy--;
			iffy++;
		} while (iffy < 800);
		reseed_random();
	}
}
