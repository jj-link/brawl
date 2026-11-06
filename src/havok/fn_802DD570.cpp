#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_80412220[];
extern char lbl_80412248[];
extern char lbl_80532E70[];
extern char lbl_80532EC0[];

void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);

void fn_802DD570(void) {
    fn_8027C808(lbl_80532E70, lbl_80412248, (u32)lbl_80532EC0, 0x58, 0, 0, 0, 0, (u32)lbl_80412220, 2, 0);
}
}

__declspec(section ".ctors") extern void* const fn_802DD570_ctor;

__declspec(section ".ctors") extern void* const fn_802DD570_ctor = (void*)fn_802DD570;
