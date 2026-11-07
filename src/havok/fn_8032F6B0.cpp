#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_80415418[];
extern char lbl_80415508[];
extern char lbl_80533688[];
void fn_8032F6B0() {
    fn_8027C808(lbl_80533688, lbl_80415508, 0, 12, 0, 0, 0, 0, (u32)lbl_80415418, 12, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032F6B0_ctor = (void*)fn_8032F6B0;
