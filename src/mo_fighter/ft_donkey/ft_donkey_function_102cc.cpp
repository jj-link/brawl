#pragma force_active on
extern "C" {
extern char lbl_92_bss_294[4];
extern char lbl_92_bss_288[12];
void* fn_92_10314(void* object);
void* fn_92_1028C(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_92_102CC() {
    fn_92_10314(lbl_92_bss_294);
    __register_global_object(lbl_92_bss_294, (void*)fn_92_1028C, lbl_92_bss_288);
}
}

__declspec(section ".ctors") extern void* const fn_92_102CC_ctor = (void*)fn_92_102CC;
