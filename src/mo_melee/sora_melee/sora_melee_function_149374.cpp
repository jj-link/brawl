#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" {
unsigned int fn_27_149374(unsigned int unused, int kind)
{
    switch (kind) {
    case 3:
        return *(unsigned int*)(*(char**)(lbl_27_bss_3210 + 0x24) + 0x84);
    default:
        return 0;
    }
}
}
