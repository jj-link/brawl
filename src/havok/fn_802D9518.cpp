#pragma force_active on
extern "C" {
typedef unsigned int u32;
extern char lbl_80411148[];
extern char lbl_80411170[];
extern char lbl_804111AC[];
extern char lbl_805329C8[];
extern char lbl_805329EC[];
void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);

void fn_802D9518(void) {
    fn_8027C808(lbl_805329C8, lbl_804111AC, 0, 8, 0, 0, 0, 0, (u32)lbl_80411148, 1, 0);
    fn_8027C808(lbl_805329EC, lbl_804111AC + 0x10, 0, 0x10, 0, 0, 0, 0, (u32)lbl_80411170, 3, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802D9518_ctor = (void*)fn_802D9518;
