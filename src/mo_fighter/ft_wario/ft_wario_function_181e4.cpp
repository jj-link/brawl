#pragma force_active on
typedef struct DestructorChain DestructorChain;

extern "C" unsigned int lbl_110_bss_354;
extern "C" unsigned int lbl_110_bss_348;
extern "C" void fn_110_1822C(void*);
extern "C" void* fn_110_181A4(void*, short);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);

extern "C" void fn_110_181E4(void) {
    fn_110_1822C(&lbl_110_bss_354);
    __register_global_object(
        &lbl_110_bss_354,
        (void*)fn_110_181A4,
        (DestructorChain*)&lbl_110_bss_348
    );
}

__declspec(section ".ctors") extern void* const fn_110_181E4_ctor = (void*)fn_110_181E4;
