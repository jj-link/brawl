#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_804101E8[];
extern char lbl_80410210[];
extern char lbl_80532600[];
extern char lbl_80532628[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_802CD5A8(void) {
    fn_8027C808(lbl_80532600, lbl_80410210, (u32)lbl_80532628, 0x9c, 0, 0, 0, 0, (u32)lbl_804101E8, 2, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802CD5A8_ctor = (void*)fn_802CD5A8;
