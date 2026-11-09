#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_804125F8[];
extern char lbl_80412610[];
extern char lbl_80412624[];
extern char lbl_80532340[];
extern char lbl_80532EC0[];

void fn_802DE624(void) {
    fn_8027C808(lbl_80532EC0, lbl_80412624, (u32)lbl_80532340, 0xC, 0, 0, (u32)lbl_804125F8, 1, (u32)lbl_80412610, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802DE624_ctor = (void*)fn_802DE624;
