#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_8040FDD0[];
extern char lbl_8040FE20[];
extern char lbl_80532560[];
void fn_802B7934() {
    fn_8027C808(lbl_80532560, lbl_8040FE20, 0, 0x10, 0, 0, 0, 0, (u32)lbl_8040FDD0, 4, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802B7934_ctor = (void*)fn_802B7934;
