#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" void fn_110_EB44(void*);
extern "C" void* fn_110_EABC(void*, short);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);
extern "C" unsigned char lbl_110_bss_214[];
extern "C" unsigned char lbl_110_bss_208[];

extern "C" void fn_110_EAFC() {
    fn_110_EB44(lbl_110_bss_214);
    __register_global_object(
        lbl_110_bss_214,
        (void*)fn_110_EABC,
        (DestructorChain*)lbl_110_bss_208
    );
}

__declspec(section ".ctors") extern void* const fn_110_EAFC_ctor = (void*)fn_110_EAFC;
