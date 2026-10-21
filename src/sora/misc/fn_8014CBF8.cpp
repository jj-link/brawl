#pragma force_active on
extern "C" {
void OSInitMutex(void*);
void __register_global_object(void*, void (*)(void*), void*);
void fn_80020AF8(void);
extern char lbl_8049EC90[];
extern char lbl_8049ECA0[];
}

extern "C" void fn_8014CBF8() {
    OSInitMutex(&lbl_8049ECA0);
    __register_global_object(&lbl_8049ECA0, (void (*)(void*))fn_80020AF8, &lbl_8049EC90);
}

__declspec(section ".ctors") extern void* const fn_8014CBF8_ctor = (void*)fn_8014CBF8;
