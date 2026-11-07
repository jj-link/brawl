#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);

extern char lbl_804107A8[];
extern char lbl_80410998[];
extern char lbl_80532730[];
extern char lbl_805327F8[];

void fn_802D4688(void) {
    fn_8027C808(lbl_805327F8, lbl_80410998, (u32)lbl_80532730, 0x60, 0, 0,
                (u32)lbl_804107A8 + 0xF4, 1, (u32)lbl_804107A8 + 0x158, 6,
                (u32)lbl_804107A8 + 0x1D0);
}
}

__declspec(section ".ctors") extern void* const fn_802D4688_ctor = (void*)fn_802D4688;
