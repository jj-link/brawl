#pragma force_active on
typedef unsigned int u32;
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_8040F8DC[];
extern char lbl_8040F940[];
extern char lbl_80532510[];
void fn_80285D40(void) {
    fn_8027C808(lbl_80532510, lbl_8040F940, 0, 0x50, 0, 0, 0, 0, (u32)lbl_8040F8DC, 5, 0);
}

__declspec(section ".ctors") extern void* const fn_80285D40_ctor = (void*)fn_80285D40;
