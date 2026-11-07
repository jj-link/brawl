#pragma force_active on
typedef unsigned int u32;

extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_8040F790[];
extern char lbl_8040F858[];
extern char lbl_805324D0[];

void fn_80282040(void) {
    fn_8027C808(lbl_805324D0, lbl_8040F858, 0, 0xC0, 0, 0, 0, 0, (u32)lbl_8040F790, 10, 0);
}

__declspec(section ".ctors") extern void* const fn_80282040_ctor = (void*)fn_80282040;
