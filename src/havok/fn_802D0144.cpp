#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_80410474[];
extern char lbl_80410480[];
extern char lbl_804104A8[];
extern char lbl_805326E0[];
extern char lbl_80532730[];
void fn_802D0144() {
    fn_8027C808(lbl_805326E0, lbl_804104A8, (u32)lbl_80532730, 0x30, 0, 0, (u32)lbl_80410474, 1, (u32)lbl_80410480, 2, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802D0144_ctor = (void*)fn_802D0144;
