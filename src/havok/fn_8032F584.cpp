#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_80415274[];
extern char lbl_80415288[];
extern char lbl_80533610[];
void fn_8032F584() {
    fn_8027C808(lbl_80533610, lbl_80415288, 0, 8, 0, 0, 0, 0, (u32)lbl_80415274, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032F584_ctor = (void*)fn_8032F584;
