#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_80412278[];
extern char lbl_804122DC[];
extern char lbl_80532E98[];

void fn_802DD5D8(void) {
    fn_8027C808(lbl_80532E98, lbl_804122DC, 0, 0x40, 0, 0, 0, 0, (u32)lbl_80412278, 5, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802DD5D8_ctor = (void*)fn_802DD5D8;
