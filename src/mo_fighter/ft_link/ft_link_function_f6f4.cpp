#pragma force_active on
extern "C" {
extern unsigned int lbl_93_bss_16C;
extern char lbl_93_bss_160[12];
void fn_93_F73C(unsigned int* arg0);
void* fn_93_F6B4(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_93_F6F4() {
    fn_93_F73C(&lbl_93_bss_16C);
    __register_global_object(&lbl_93_bss_16C, (void*)fn_93_F6B4, (void*)lbl_93_bss_160);
}

__declspec(section ".ctors") extern void* const fn_93_F6F4_ctor = (void*)fn_93_F6F4;
