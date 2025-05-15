ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00400000, LENGTH = 512K
    SRAM  (rwx) : ORIGIN = 0x20070000, LENGTH = 128K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM); /* Initial stack pointer */

SECTIONS
{
    .text : {
        KEEP(*(.isr_vector))        /* Vector table */
        *(.text*)                   /* Application code */
        *(.rodata*)                 /* Read-only data */
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)
    } > FLASH

    .data : AT (ADDR(.text) + SIZEOF(.text)) {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > SRAM

    .bss : {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > SRAM

    .stack (COPY) : {
        . = ALIGN(8);
        _stack_top = .;
    } > SRAM
}
