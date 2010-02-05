int RandomDevice::Init()
{
	dev_t *random;
	random->device_name = "random";
	random->read_func = (void*)random_read;
	random->write_func = (void*)random_seed;
	SimpleFS::RegisterDevice(random);
}

void RandomDevice::random_read(int len)
{
	void *y;
	int t;
	for (t = 0; t < len; t++) {
		*y++ = rand() % 9;
	}
	return y;
}
