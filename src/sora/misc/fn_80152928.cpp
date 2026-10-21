#pragma force_active on
extern "C" {
void OSInitMutex(void* mutex);
void __register_global_object(void* obj, void (*dtor)(void*), void* ctx);
void fn_80020AF8(void* p);
extern char lbl_8049ECF8[];
extern char lbl_8049ED08[];
}

extern "C" void fn_80152928(void) {
    OSInitMutex(lbl_8049ED08);
    __register_global_object(lbl_8049ED08, fn_80020AF8, lbl_8049ECF8);
}

__declspec(section ".ctors") extern void* const fn_80152928_ctor = (void*)fn_80152928;
