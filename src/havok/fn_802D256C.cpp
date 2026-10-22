#pragma force_active on
extern "C" void fn_8027C808(void*, void*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" char lbl_80410650[];
extern "C" char lbl_804106DC[];
extern "C" char lbl_80410740[];
extern "C" char lbl_80532730[];
extern "C" char lbl_805327A0[];
extern "C" char lbl_805327C4[];

extern "C" void fn_802D256C(void) {
    fn_8027C808(lbl_805327A0, lbl_80410740, 0, 0x30, 0, 0, 0, 0, (unsigned int)lbl_80410650, 3, 0);
    fn_8027C808(lbl_805327C4, (void*)((char*)lbl_80410740 + 0x21), (unsigned int)lbl_80532730, 0x50, 0, 0, 0, 0, (unsigned int)lbl_804106DC, 5, 0);
}

__declspec(section ".ctors") extern void* const fn_802D256C_ctor = (void*)fn_802D256C;
