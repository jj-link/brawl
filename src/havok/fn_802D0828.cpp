#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_80410530[];
extern char lbl_80410544[];
extern char lbl_80532708[];
extern char lbl_80532830[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_802D0828(void) {
    fn_8027C808(lbl_80532708, lbl_80410544, (u32)lbl_80532830, 0x14, 0, 1, 0, 0, (u32)lbl_80410530, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802D0828_ctor = (void*)fn_802D0828;
