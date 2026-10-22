#pragma force_active on
typedef unsigned int u32;

extern char lbl_80414900[];
extern char lbl_80414948[];
extern char lbl_80414998[];
extern char lbl_805333D0[];
extern char lbl_805333F4[];

extern "C" {
void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, void* h, u32 i, u32 j);

void fn_8032D648(void) {
    fn_8027C808(lbl_805333D0, lbl_80414998, 0, 8, 0, 0, 0, 0, lbl_80414900, 1, 0);
    fn_8027C808(lbl_805333F4, lbl_80414998 + 0x15, 0, 0x18, 0, 0, 0, 0, lbl_80414948, 4, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032D648_ctor = (void*)fn_8032D648;
