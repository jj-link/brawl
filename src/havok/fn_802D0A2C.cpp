#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_80410558[];
extern char lbl_8041056C[];
extern char lbl_80532730[];
extern char lbl_80532940[];
void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
}

extern "C" void fn_802D0A2C(void) {
    fn_8027C808(lbl_80532730, lbl_8041056C, (u32)lbl_80532940, 0x10, 0, 0, 0, 0, (u32)lbl_80410558, 1, 0);
}

__declspec(section ".ctors") extern void* const fn_802D0A2C_ctor = (void*)fn_802D0A2C;
