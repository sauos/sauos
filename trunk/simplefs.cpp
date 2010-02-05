// SimpleFS is the SauOS Filesystem layer.
// See http://code.google.com/p/sauos/wiki/SimpleFS for more info.

dev_t ref[32768]
int max_dev;

int SimpleFS::MountFileSystem(char *Device, char *FSType)
{
	if (FSType == "toyfs") {
		return SimpleFS::ToyFS::CreateFS();
	}
}

int SimpleFS::RegisterDevice(dev_t *device)
{
	if (max_dev == 32768) {
		return -1;
	}

	max_dev++;

	ref[max_dev] = device;
	return max_dev;
}
