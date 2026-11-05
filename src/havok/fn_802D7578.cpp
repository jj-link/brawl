#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_80410FF0[];
extern char lbl_80411040[];
extern char lbl_80532340[];
extern char lbl_80532978[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_802D7578(void) {
    fn_8027C808(lbl_80532978, lbl_80411040, (u32)lbl_80532340, 0x18, 0, 0, 0, 0, (u32)lbl_80410FF0, 4, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802D7578_ctor = (void*)fn_802D7578;
