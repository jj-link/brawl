#pragma force_active on
extern "C" {
void OSInitMutex(void* mutex);
void __register_global_object(void* obj, void (*dtor)(void*), void* ctx);
void fn_80020AF8(void* self);
extern char lbl_8049ECB8[];
extern char lbl_8049ECC8[];
}

extern "C" void fn_8014E2FC() {
    OSInitMutex(lbl_8049ECC8);
    __register_global_object(lbl_8049ECC8, fn_80020AF8, lbl_8049ECB8);
}

__declspec(section ".ctors") extern void* const fn_8014E2FC_ctor = (void*)fn_8014E2FC;
