OUTPUT_FORMAT("binary")
ENTRY(SauOSStart)
phys = 0x00100000;
SECTIONS {
 .text phys : AT (phys) {
  code = .;
  *(.text)
  *(.rodata)
 }
 .data phys : AT (phys) {
  *(.data)
 }
 .bss phys : AT (0x00200000) {
  bss = .;
  *(.bss)
 }
 EndKernel = .;
}
