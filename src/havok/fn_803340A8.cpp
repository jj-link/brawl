#pragma force_active on
extern "C" {
extern char lbl_8059F048;

void fn_803340A8(void) {
    ((char*)&lbl_8059F048)[1] = 0;
}
}

__declspec(section ".ctors") extern void* const fn_803340A8_ctor = (void*)fn_803340A8;
