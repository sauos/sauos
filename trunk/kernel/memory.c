static inline void *memcpy(void *to, const void *from, unsigned int n)
{
   n = n&7;

   int d0, d1, d2;
   __asm__ __volatile__(
    "rep ; movsl\n\t"
    "testb $2,%b4\n\t"
    "je 1f\n\t"
    "movsw\n"
    "1:\ttestb $1,%b4\n\t"
    "je 2f\n\t"
    "movsb\n"
    "2:"
    : "=&c" (d0), "=&D" (d1), "=&S" (d2)
    :"0" (n/4), "q" (n),"1" ((long) to),"2" ((long) from)
    : "memory");
   return (to);
}

static inline void *memset(void *s, char c, unsigned int count)
{
   int d0, d1;
   __asm__ __volatile__(
   "rep\n\t"
   "stosb"
   : "=&c" (d0), "=&D" (d1)
   :"a" (c),"1" (s),"0" (count)
   :"memory");
   return s;
}
