#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_804103AC[];
extern char lbl_804103C0[];
extern char lbl_80532698[];
extern char lbl_80532730[];
void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
}

extern "C" void fn_802CE588(void) {
    fn_8027C808(lbl_80532698, lbl_804103C0, (u32)lbl_80532730, 0x20, 0, 0, 0, 0, (u32)lbl_804103AC, 1, 0);
}

__declspec(section ".ctors") extern void* const fn_802CE588_ctor = (void*)fn_802CE588;
