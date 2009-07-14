#include "stdarg.h"
#define CREATEPTR(addr) (void*)addr
int CurWhere_X;
int CurWhere_Y;

void *CopyMemory(void *dest, void *src, int sz)
{
 const char *sp = (const char*)src;
 char *dp = (char*)dest;
 int szr;
 while (szr < sz) {
  *dp++ = *sp++;
  szr++;
 }
}

void *SauOSMain()
{
 StringWrite("Welcome to SauOS. Licensed under GPLv3. Copyright (c) 2009 imate900 and ScorchOS.");
 StringCrLf();
}

int StringLength(char *String)
{
 int StrSize;
 while (*String) {
  StrSize++;
  *String++;
 }
}

void *memset(void *dest, char val, int cnt)
{
 char *asdf = (char*)dest;
 int szr;
 while (szr < cnt) {
  *asdf = val;
  szr++;
 }
}

unsigned char ReadPort(unsigned short Port)
{
 unsigned char a;
 asm ("inb %1, %0" : "=a" (a) : "dN" (Port));
 return a;
}

unsigned char WritePort(unsigned short Port, unsigned short Data)
{
 asm ("outb %1, %0" : : "dN" (Port), "a" (Data));
}

int StringCrLf()
{
 void *VideoBuffer = CREATEPTR(0xb8000);
 CurWhere_Y++;
 unsigned temp = CurWhere_Y - 24;
 if (CurWhere_Y > 25) {
  unsigned blank = 0x20 | (0x0F << 8);
  CopyMemory(VideoBuffer, VideoBuffer + temp * 80, (25 - temp) * 80 * 2);
  memset(VideoBuffer + (25 - temp) * 80, blank, 80);
 }
 temp = CurWhere_Y * 80 + CurWhere_X;
 WritePort(0x3D4, 14);
 WritePort(0x3D4, temp >> 8);
 WritePort(0x3D5, 15);
 WritePort(0x3D5, temp);
}

int StringWrite(char *String)
{
 /* Determine bytes to write to video buffer. */
 int StrSize = StringLength(String);

 /* Create buffer. */
 void *VideoMemory = CREATEPTR(0xb8000);
 unsigned short Where;

 /* Write text. (Parts based on bkerndev but rewrote.) */
 int CurrPlace;
 unsigned temp = CurWhere_Y - 24;
 while (CurrPlace < StrSize) {
  Where = VideoMemory + (CurWhere_Y * 80 + CurWhere_X);
  Where = *String | 0x0F;
  *String++;
  CurrPlace++;
  if (CurWhere_X > 80) {
   CurWhere_X = 0;
   CurWhere_Y++;
  }
  if (CurWhere_Y > 25) {
   unsigned blank = 0x20 | (0x0F << 8);
   CopyMemory(VideoMemory, VideoMemory + temp * 80, (25 - temp) * 80 * 2);
   memset(VideoMemory + (25 - temp) * 80, blank, 80);
  }
  temp = CurWhere_Y * 80 + CurWhere_X;
  WritePort(0x3D4, 14);
  WritePort(0x3D4, temp >> 8);
  WritePort(0x3D5, 15);
  WritePort(0x3D5, temp);
 }
}

char *FormatString(const char *Format, ...)
{
 va_list a;
 char *b;

 va_start(a, Format);
 vsprintf(b, Format, a);
 va_end(a);

 return b;
}

void *WriteFormattedString(const char *Format, ...)
{
 va_list a;
 char *b;

 va_start(a, Format);
 vsprintf(b, Format, a);
 StringWrite(b);
 va_end(a);
}
