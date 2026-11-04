#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_804152BC[];
extern char lbl_804152F8[];
extern char lbl_80533638[];

void fn_8032F5E8(void) {
    fn_8027C808(lbl_80533638, lbl_804152F8, 0, 0x10, 0, 0, 0, 0, (u32)lbl_804152BC, 3, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032F5E8_ctor = (void*)fn_8032F5E8;
