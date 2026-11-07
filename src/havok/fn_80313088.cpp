#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern char lbl_804143C0[];
extern char lbl_804143D4[];
extern char lbl_805332C8[];

void fn_80313088(void) {
    fn_8027C808(lbl_805332C8, lbl_804143D4, 0, 4, 0, 0, 0, 0, (u32)lbl_804143C0, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_80313088_ctor = (void*)fn_80313088;
