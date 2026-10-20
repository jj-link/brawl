#pragma force_active on
extern char lbl_27_bss_54EC[];
extern void* lbl_27_bss_5278[];

extern "C" {
void* fn_27_1E8374(int idx)
{
    if (idx <= -1 || idx >= 0x9a) {
        return lbl_27_bss_54EC;
    }
    return lbl_27_bss_5278[idx];
}
}
