/*
 * Logic of processes.
 */

extern unsigned int rand();
extern int srand(unsigned int seed);

unsigned int procs;

struct {
	int stat;
	int pid;
	char *nam;
	int ticket_a;
	int ticket_n;
} proc_t;

int create_process(char *name) {

	tmp.stat = 0; // active zombie
	tmp.pid = procs++;
	tmp.nam = name;
	tmp.ticket_a = 0; // not ticketing
	tmp.ticket_a = 0;
}
