#pragma force_active on
extern "C" {
extern int lbl_124_bss_25C;
extern unsigned char lbl_124_bss_250[];
void fn_124_C490(void* p);
void fn_124_C408(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_124_C448(void) {
    fn_124_C490((void*)&lbl_124_bss_25C);
    __register_global_object((void*)&lbl_124_bss_25C, (void*)fn_124_C408, (void*)lbl_124_bss_250);
}
}

__declspec(section ".ctors") extern void* const fn_124_C448_ctor = (void*)fn_124_C448;
