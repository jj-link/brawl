#pragma force_active on
typedef struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" void* fn_123_107F0(void*, short);
extern "C" void* fn_123_10878(void*);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);
extern "C" unsigned char lbl_123_bss_318[12];
extern "C" unsigned char lbl_123_bss_324[4];

extern "C" void fn_123_10830() {
    fn_123_10878(lbl_123_bss_324);
    __register_global_object(
        lbl_123_bss_324,
        (void*)fn_123_107F0,
        (DestructorChain*)lbl_123_bss_318
    );
}

__declspec(section ".ctors") extern void* const fn_123_10830_ctor = (void*)fn_123_10830;
