#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_804105D8[];
extern char lbl_80410600[];
extern char lbl_80532730[];
extern char lbl_80532768[];

void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);

void fn_802D1520(void) {
    fn_8027C808(lbl_80532768, lbl_80410600, (u32)lbl_80532730, 0x30, 0, 0, 0, 0, (u32)lbl_804105D8, 2, 0);
}
}

extern void* const fn_802D1520_ctor;

__declspec(section ".ctors") extern void* const fn_802D1520_ctor = (void*)fn_802D1520;
