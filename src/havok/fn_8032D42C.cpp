#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_804146F0[];
extern char lbl_80414718[];
extern char lbl_80532340[];
extern char lbl_80533310[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_8032D42C(void) {
    fn_8027C808(lbl_80533310, lbl_80414718, (u32)lbl_80532340, 0x18, 0, 0, 0, 0, (u32)lbl_804146F0, 2, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032D42C_ctor = (void*)fn_8032D42C;
