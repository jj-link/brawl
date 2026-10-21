#pragma force_active on
extern "C" {
void fn_113_25E7C(void* p);
void fn_113_25DF4(void* p, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern unsigned int lbl_113_bss_214;
extern unsigned int lbl_113_bss_208[3];

extern "C" void fn_113_25E34() {
    fn_113_25E7C(&lbl_113_bss_214);
    __register_global_object(&lbl_113_bss_214, (void*)fn_113_25DF4, &lbl_113_bss_208);
}

__declspec(section ".ctors") extern void* const fn_113_25E34_ctor = (void*)fn_113_25E34;
