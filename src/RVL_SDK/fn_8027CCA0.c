#pragma force_active on
typedef unsigned int u32;

extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_8040F26C[];
extern char lbl_8040F2F8[];
extern char lbl_80532410[];

void fn_8027CCA0(void) {
    fn_8027C808(lbl_80532410, lbl_8040F2F8, 0, 0x24, 0, 0, 0, 0, (u32)lbl_8040F26C, 7, 0);
}

__declspec(section ".ctors") extern void* const fn_8027CCA0_ctor = (void*)fn_8027CCA0;
