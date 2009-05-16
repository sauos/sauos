/* /dev/{,u}random driver */
int s = 2;

int srandom(int seed)
{
 s = seed;
}

int random()
{
 return s * s * s + s / s + s * s - s;
}

int dev_urandom_read(int len, int buf)
{
 buf = random();
}

int dev_urandom_write(int buf, int len)
{
 srandom(buf);
}
