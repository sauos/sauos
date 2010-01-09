// SimpleFS is the SauOS Filesystem layer.
// See http://code.google.com/p/sauos/wiki/SimpleFS for more info.

int SimpleFS::MountFileSystem(char *Device, char *FSType)
{
	if (FSType == "toyfs") {
		return SimpleFS::ToyFS::CreateFS();
	}
}