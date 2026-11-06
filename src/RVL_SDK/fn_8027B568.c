#pragma force_active on
typedef unsigned int u32;
extern char lbl_8040EA18[];
extern char lbl_8040EA40[];
extern char lbl_80532318[];
extern char lbl_80532340[];
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_8027B568(void) {
    fn_8027C808(lbl_80532340, lbl_8040EA40, (u32)lbl_80532318, 8, 0, 0, 0, 0, (u32)lbl_8040EA18, 2, 0);
}

__declspec(section ".ctors") extern void* const fn_8027B568_ctor = (void*)fn_8027B568;
