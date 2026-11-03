#pragma force_active on
typedef unsigned int u32;
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_8040EADC[];
extern char lbl_8040EB68[];
extern char lbl_8040EA78[];
extern char lbl_80532378[];
void fn_8027C914(void) {
    fn_8027C808(lbl_80532378, lbl_8040EB68, 0, 0x24, 0, 0, (u32)lbl_8040EA78, 1, (u32)lbl_8040EADC, 7, 0);
}

__declspec(section ".ctors") extern void* const fn_8027C914_ctor = (void*)fn_8027C914;
