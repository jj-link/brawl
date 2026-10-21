#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern char lbl_80494EE8[];
void fn_800259A0(void*);
extern int lbl_805A0020;
}

extern "C" void fn_80025978(void) {
    lbl_805A0020 = 0;
    __construct_array(lbl_80494EE8, fn_800259A0, 0, 0x68, 7);
}

__declspec(section ".ctors") extern void* const fn_80025978_ctor = (void*)fn_80025978;
