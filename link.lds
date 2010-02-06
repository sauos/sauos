ENTRY (_sauos_init)

SECTIONS{
    . = 0x00100000;
    _sauos_start = .;
    .text :{
        *(.text)
    }

    .rodata ALIGN (0x1000) : {
        *(.rodata)
    }

    .data ALIGN (0x1000) : {
        *(.data)
	edata = .;
    }

    .bss : {
        sbss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }
    _sauos_end = .;
}

