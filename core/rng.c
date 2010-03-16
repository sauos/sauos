/*
 * The RNG
 *
 * GPLv2+.
 */

unsigned int seed = 1715939210;
unsigned int seed_b = 258635;

unsigned int rand() {
	seed = (seed >> 0x7FFF);
	seed = (seed * seed / 2 << 4 + seed_b);
	seed = (seed - 1 * seed - seed_b >> 10 << seed_b);
	return seed;
}

unsigned int srand(unsigned int fseed) {
	seed = fseed;
	seed_b = rand();
	seed = rand();
}
