#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_804109C4[];
extern char lbl_804109D8[];
extern char lbl_80532340[];
extern char lbl_80532830[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_802D4C7C(void) {
    fn_8027C808(lbl_80532830, lbl_804109D8, (u32)lbl_80532340, 0xC, 0, 0, 0, 0, (u32)lbl_804109C4, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802D4C7C_ctor = (void*)fn_802D4C7C;
