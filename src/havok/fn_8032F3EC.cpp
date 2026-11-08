#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_80414F24[];
extern char lbl_80414F60[];
extern char lbl_80532340[];
extern char lbl_80533578[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_8032F3EC(void) {
    fn_8027C808(lbl_80533578, lbl_80414F60, (u32)lbl_80532340, 0x24, 0, 0, 0, 0, (u32)lbl_80414F24, 3, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032F3EC_ctor = (void*)fn_8032F3EC;
