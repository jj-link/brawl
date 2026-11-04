#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_80413290[];
extern char lbl_804132B8[];
extern char lbl_805331A0[];
extern char lbl_80533238[];
void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
}

extern "C" void fn_802E90B4(void) {
    fn_8027C808(lbl_805331A0, lbl_804132B8, (u32)lbl_80533238, 0x70, 0, 0, 0, 0, (u32)lbl_80413290, 2, 0);
}

__declspec(section ".ctors") extern void* const fn_802E90B4_ctor = (void*)fn_802E90B4;
