#pragma force_active on
extern "C" {
void fn_93_14C0C(void **object);
void* fn_93_14B84(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);

extern void* lbl_93_bss_274;
extern unsigned char lbl_93_bss_268[0xC];

void fn_93_14BC4() {
    fn_93_14C0C(&lbl_93_bss_274);
    __register_global_object(&lbl_93_bss_274, (void*)fn_93_14B84, lbl_93_bss_268);
}
}

__declspec(section ".ctors") extern void* const fn_93_14BC4_ctor = (void*)fn_93_14BC4;
