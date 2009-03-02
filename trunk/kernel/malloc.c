void *malloc(int size)
{
	if (size == 0) return (void*)0;
	void *buf;
	buf += size;
	return buf;
}

void free(void *buf)
{
	buf = (void*)0;
}
