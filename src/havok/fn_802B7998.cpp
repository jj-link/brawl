#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_8040FE68[];
extern char lbl_8040FEA4[];
extern char lbl_80532560[];
extern char lbl_80532588[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_802B7998(void) {
    fn_8027C808(lbl_80532588, lbl_8040FEA4, (u32)lbl_80532560, 0x24, 0, 0, 0, 0, (u32)lbl_8040FE68, 3, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802B7998_ctor = (void*)fn_802B7998;
