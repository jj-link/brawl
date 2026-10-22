#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, void* h, u32 i, u32 j);

extern char lbl_804155CC[];
extern char lbl_80415618[];
extern char lbl_8041562C[];
extern char lbl_805336C0[];
extern char lbl_805336E4[];

void fn_80333698(void) {
    fn_8027C808(lbl_805336C0, lbl_8041562C, 0, 0x10, 0, 0, 0, 0, lbl_804155CC, 3, 0);
    fn_8027C808(lbl_805336E4, lbl_8041562C + 0x21, 0, 8, 0, 0, 0, 0, lbl_80415618, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_80333698_ctor = (void*)fn_80333698;
