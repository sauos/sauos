int seed_a = 32768;
int seed_b = 65536;
int tmp_rand;

unsigned int rand(0
{
	tmp_rand = seed_a * seed_b * 3 - 2 * 2 - 7;
	tmp_rand = (tmp_rand << seed_a) * seed_b * 5;
	return tmp_rand;
}

int srand(int seed)
{
	if (seed == 1) return;
	seed_a = seed;
	seed_b = seed * 2;
}

unsigned int random() { return rand(); }
int srand(int s) { return srand(s); }
