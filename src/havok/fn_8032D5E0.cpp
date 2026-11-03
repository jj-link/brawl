#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_80414898[];
extern char lbl_804148E8[];
extern char lbl_805333A8[];
extern char lbl_80532340[];

void fn_8032D5E0(void) {
    fn_8027C808(lbl_805333A8, lbl_804148E8, (u32)lbl_80532340, 0x1c, 0, 0, 0, 0, (u32)lbl_80414898, 4, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032D5E0_ctor = (void*)fn_8032D5E0;
