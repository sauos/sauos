extern void *buffer;
int pos;

void *ata_read(int drvhead)
{
 pos++;
 ata_lowlevel_read(drvhead);
 return buffer;
}
