#pragma force_active on
extern void* lbl_27_bss_5278[];

extern "C" void fn_27_1E847C(int unused, int idx, void* val)
{
    lbl_27_bss_5278[idx] = val;
}
