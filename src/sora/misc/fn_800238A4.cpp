#pragma force_active on
extern "C" {
extern char lbl_80421720[];
extern void* lbl_8059FFF0;

void fn_800238A4(void) {
    lbl_8059FFF0 = &lbl_80421720;
}
}

__declspec(section ".ctors") extern void* const fn_800238A4_ctor = (void*)fn_800238A4;
