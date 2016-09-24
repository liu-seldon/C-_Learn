ENTRY(nomain)
SECTIONS
{
    . = 0x00000000004000a8 + SIZEOF_HEADERS;
    tinytext : {*(.text) *(.data) *(.rodata)}
    /DISCARD/ : {*(.comment)}
}
