#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_80414B04[];
extern char lbl_80414B10[];
extern char lbl_80414B24[];
extern char lbl_80532340[];
extern char lbl_80533440[];

void fn_8032E740(void) {
    fn_8027C808(lbl_80533440, lbl_80414B24, (u32)lbl_80532340, 0x38, 0, 0, (u32)lbl_80414B04, 1, (u32)lbl_80414B10, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032E740_ctor = (void*)fn_8032E740;
