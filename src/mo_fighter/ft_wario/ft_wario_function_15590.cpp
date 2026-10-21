#pragma force_active on

extern "C" {
typedef struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern void* fn_110_155D8(void*);
extern void* fn_110_15550(void*, short);
extern void* __register_global_object(void*, void*, DestructorChain*);
extern unsigned char lbl_110_bss_314[];
extern unsigned char lbl_110_bss_308[];

void fn_110_15590() {
    fn_110_155D8(lbl_110_bss_314);
    __register_global_object(
        lbl_110_bss_314,
        (void*)fn_110_15550,
        (DestructorChain*)lbl_110_bss_308
    );
}
}

__declspec(section ".ctors") extern void* const fn_110_15590_ctor = (void*)fn_110_15590;
