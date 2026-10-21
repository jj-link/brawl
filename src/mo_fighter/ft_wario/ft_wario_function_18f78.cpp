#pragma force_active on
extern "C" {
extern unsigned int lbl_110_bss_384;
extern unsigned int lbl_110_bss_378[3];
void fn_110_18FC0(void* p);
void fn_110_18F38(void* p, short size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_110_18F78(void) {
    fn_110_18FC0(&lbl_110_bss_384);
    __register_global_object(&lbl_110_bss_384, (void*)fn_110_18F38, &lbl_110_bss_378);
}
}

__declspec(section ".ctors") extern void* const fn_110_18F78_ctor = (void*)fn_110_18F78;
