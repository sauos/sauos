// SimpleFS is a Simple File System driver.

int SimpleFS::MountFileSystem(char *Device, char *FSType)
{
	if (FSType == "toyfs") {
		return SimpleFS::ToyFS::CreateFS();
	}
}