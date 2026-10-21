#pragma force_active on
extern "C" {
extern unsigned char lbl_100_bss_194[4];
extern unsigned char lbl_100_bss_188[12];
void fn_100_D478(void* output);
void* fn_100_D3E4(void* ptr, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
void fn_100_D430();
}

void fn_100_D430() {
    fn_100_D478(lbl_100_bss_194);
    __register_global_object(lbl_100_bss_194, (void*)fn_100_D3E4, lbl_100_bss_188);
}

__declspec(section ".ctors") extern void* const fn_100_D430_ctor = (void*)fn_100_D430;
