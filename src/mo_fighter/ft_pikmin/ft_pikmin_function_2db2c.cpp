#pragma force_active on
extern "C" {
extern void* lbl_113_bss_37C;
extern char lbl_113_bss_370[];
void fn_113_2DB74(void* p);
void* fn_113_2DAEC(void* ptr, short size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_113_2DB2C(void) {
    fn_113_2DB74(&lbl_113_bss_37C);
    __register_global_object(&lbl_113_bss_37C, (void*)fn_113_2DAEC, lbl_113_bss_370);
}
}

__declspec(section ".ctors") extern void* const fn_113_2DB2C_ctor = (void*)fn_113_2DB2C;
