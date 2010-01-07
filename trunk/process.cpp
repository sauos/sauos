int UpTime;

int Process::IdleTask()
{
	for(;;);
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
		// Wait...
		do {
			iffy++;
			iffy--;
			iffy++;
		} while (iffy < 200);
	}
}