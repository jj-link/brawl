#pragma force_active on
typedef unsigned int u32;
extern "C" {
extern char lbl_804141C4[];
extern char lbl_804141D8[];
extern char lbl_80532588[];
extern char lbl_80533288[];
void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void fn_80300794(void) {
    fn_8027C808(lbl_80533288, lbl_804141D8, (u32)lbl_80532588, 0x30, 0, 0, 0, 0, (u32)lbl_804141C4, 1, 0);
}
}

__declspec(section ".ctors") extern void* const fn_80300794_ctor = (void*)fn_80300794;
