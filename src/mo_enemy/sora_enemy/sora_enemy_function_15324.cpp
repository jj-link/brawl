#pragma force_active on
extern "C" {

extern char lbl_41_bss_7C[];
extern char lbl_41_bss_70[];

void fn_41_137C0(void* p);
void* fn_41_13818(void* p, int n);
void __register_global_object(void* obj, void* dtor, void* handle);

void fn_41_15324() {
    fn_41_137C0(lbl_41_bss_7C);
    __register_global_object(lbl_41_bss_7C, (void*)fn_41_13818, lbl_41_bss_70);
}

}

__declspec(section ".ctors") extern void* const fn_41_15324_ctor = (void*)fn_41_15324;
