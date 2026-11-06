#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_80414004[];
extern char lbl_80414018[];
extern char lbl_80532340[];
extern char lbl_80533260[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_802F0B40() {
    fn_8027C808(lbl_80533260, lbl_80414018, (u32)lbl_80532340, 12, 0, 0, 0, 0, (u32)lbl_80414004, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802F0B40_ctor = (void*)fn_802F0B40;
