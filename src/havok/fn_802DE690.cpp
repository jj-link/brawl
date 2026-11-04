#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_804126D8[];
extern char lbl_80412688[];
extern char lbl_80532EE8[];

void fn_802DE690(void) {
    fn_8027C808(lbl_80532EE8, lbl_804126D8, 0, 0x10, 0, 0, 0, 0, (u32)lbl_80412688, 4, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802DE690_ctor = (void*)fn_802DE690;
