int kmain(void *mbd, unsigned int magic)
{
 init_video();
 if (magic != 0x1BADB002)
 {
  puts("[ERROR] SauOS not booted with a Multiboot loader.");
  freeze();
 }

 puts("[INFO] SauOS booted.");
 puts("[NOTE] We need to now implement something to do here. Crashing...");
 freeze();
}
