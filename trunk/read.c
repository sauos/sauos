/*
 * Read from /dev devices
 */
int sys_readdev(char *dev, void *buf, int len)
{
 if (dev == "/dev/null") return 0;
 if (dev == "/dev/zero") (int)buf = 0; return;
 if (dev == "/dev/urandom") (int)buf = random(); return;
 if (dev == "/dev/hd/0") return ata_read(0x0a0, len);
}
