#pragma force_active on
extern "C" {
extern void* lbl_92_bss_224;
extern char lbl_92_bss_218[12];
void fn_92_F5EC(void** object);
void* fn_92_F564(void* ptr, short count);
void* __register_global_object(void* object, void* (*destructor)(void*, short), void* chain);
}

extern "C" void fn_92_F5A4() {
    fn_92_F5EC(&lbl_92_bss_224);
    __register_global_object(&lbl_92_bss_224, fn_92_F564, lbl_92_bss_218);
}

__declspec(section ".ctors") extern void* const fn_92_F5A4_ctor = (void*)fn_92_F5A4;
