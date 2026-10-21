#pragma force_active on

struct VFT2 {
    unsigned long _[16];
};

struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};

extern "C" void fn_107_13FA4(VFT2 **object);
extern "C" void *fn_107_13F1C(void *ptr, int flag);
extern "C" void *__register_global_object(void *object, void *destructor, DestructorChain *chain);

extern "C" extern VFT2 *lbl_107_bss_22C;
extern "C" extern DestructorChain lbl_107_bss_220;

extern "C" void fn_107_13F5C() {
    fn_107_13FA4(&lbl_107_bss_22C);
    __register_global_object(&lbl_107_bss_22C, (void *)fn_107_13F1C, &lbl_107_bss_220);
}

__declspec(section ".ctors") extern void* const fn_107_13F5C_ctor = (void*)fn_107_13F5C;
