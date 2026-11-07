#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_8040FFE8[];
extern char lbl_80410038[];
extern char lbl_805325C8[];
extern char lbl_805332C8[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_802CB41C(void) {
    fn_8027C808(lbl_805325C8, lbl_80410038, (u32)lbl_805332C8, 0xc, 0, 0, 0, 0, (u32)lbl_8040FFE8, 4, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802CB41C_ctor = (void*)fn_802CB41C;
