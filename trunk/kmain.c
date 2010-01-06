//#include "multiboot.h"

extern "C" void kmain(struct multiboot_data* mbd, unsigned int magic);

void kmain( struct multiboot_data* mbd, unsigned int magic )
{
   
}

typedef long size_t;
 
void *operator new(size_t size)
{
    return malloc(size);
}
 
void *operator new[](size_t size)
{
    return malloc(size);
}
 
void operator delete(void *p)
{
}
 
void operator delete[](void *p)
{
}