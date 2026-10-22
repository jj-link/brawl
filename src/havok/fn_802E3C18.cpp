#pragma force_active on
extern "C" void fn_8027C808(void*, void*, void*, unsigned, unsigned, unsigned, unsigned, unsigned, void*, unsigned, unsigned);
extern char lbl_80412DE0[], lbl_80412EA8[], lbl_80412F34[], lbl_80533030[], lbl_80533068[], lbl_8053308C[];

extern "C" void fn_802E3C18() {
    fn_8027C808(lbl_80533068, lbl_80412F34, 0, 0x20, 0, 0, 0, 0, lbl_80412DE0, 2, 0);
    fn_8027C808(lbl_8053308C, lbl_80412F34 + 0x24, lbl_80533030, 0x70, 0, 0, 0, 0, lbl_80412EA8, 7, 0);
}

__declspec(section ".ctors") extern void* const fn_802E3C18_ctor = (void*)fn_802E3C18;
