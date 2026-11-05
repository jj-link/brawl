#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_804149F0[];
extern char lbl_80414A54[];
extern char lbl_80533418[];

void fn_8032D700(void) {
    fn_8027C808(lbl_80533418, lbl_80414A54, 0, 0x28, 0, 0, 0, 0, (u32)lbl_804149F0, 5, 0);
}
}

extern void* const fn_8032D700_ctor;

__declspec(section ".ctors") extern void* const fn_8032D700_ctor = (void*)fn_8032D700;
