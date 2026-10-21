#pragma force_active on
typedef void (*Destructor)(void*, int);

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
extern unsigned char lbl_110_bss_1E4[];
extern DestructorChain lbl_110_bss_1D8;
extern void fn_110_E0E4(void*);
extern void* fn_110_E05C(void*, short);
extern void* __register_global_object(void*, void*, DestructorChain*);
}

extern "C" void fn_110_E09C() {
    fn_110_E0E4(lbl_110_bss_1E4);
    __register_global_object(
        lbl_110_bss_1E4,
        reinterpret_cast<void*>(fn_110_E05C),
        &lbl_110_bss_1D8
    );
}

__declspec(section ".ctors") extern void* const fn_110_E09C_ctor = (void*)fn_110_E09C;
