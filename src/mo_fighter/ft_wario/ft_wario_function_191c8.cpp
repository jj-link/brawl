#pragma force_active on
extern "C" {
extern unsigned char lbl_110_bss_394[];
extern unsigned char lbl_110_bss_388[];
void fn_110_19210(void* p);
void* fn_110_19188(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_110_191C8() {
    unsigned char* p = lbl_110_bss_394;
    fn_110_19210(p);
    __register_global_object(p, (void*)fn_110_19188, lbl_110_bss_388);
}
}

__declspec(section ".ctors") extern void* const fn_110_191C8_ctor = (void*)fn_110_191C8;
