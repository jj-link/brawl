#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_80413F38[];
extern char lbl_80413FB0[];
extern char lbl_80413EF8[];
extern char lbl_80532340[];
extern char lbl_80533238[];

void fn_802F06A8(void) {
    fn_8027C808(lbl_80533238, lbl_80413FB0, (u32)lbl_80532340, 0x58, 0, 0, (u32)lbl_80413EF8, 1, (u32)lbl_80413F38, 6, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802F06A8_ctor = (void*)fn_802F06A8;
