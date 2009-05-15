/* /dev/{,u}random driver */
int s = 2;

int srandom(int seed)
{
 s = seed;
}

int random()
{
 return seed * seed * seed + seed / seed + seed * seed - seed;
}

int dev_urandom_read(int len, int buf)
{
 buf = random();
}

int dev_urandom_write(int buf, int len)
{
 srandom(buf);
}
