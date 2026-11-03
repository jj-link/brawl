#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_80414DD8[];
extern char lbl_80414E28[];
extern char lbl_80533500[];

void fn_8032E8EC(void) {
    fn_8027C808(lbl_80533500, lbl_80414E28, 0, 0x50, 0, 0, 0, 0, (u32)lbl_80414DD8, 4, 0);
}
}

__declspec(section ".ctors") extern void* const fn_8032E8EC_ctor = (void*)fn_8032E8EC;
