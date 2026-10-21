#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" {
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
void fn_120_E0D8(void* p);
void* fn_120_E048(void* p, short n);
extern int lbl_120_bss_2B4;
extern DestructorChain lbl_120_bss_2A8;
}

extern "C" void fn_120_E090() {
    fn_120_E0D8(&lbl_120_bss_2B4);
    __register_global_object(&lbl_120_bss_2B4, (void*)fn_120_E048, &lbl_120_bss_2A8);
}

__declspec(section ".ctors") extern void* const fn_120_E090_ctor = (void*)fn_120_E090;
