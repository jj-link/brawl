#pragma force_active on
typedef unsigned char u8;

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
extern u8 lbl_104_bss_654[];
extern u8 lbl_104_bss_648[];
extern void fn_104_24D00(void*);
extern void* fn_104_24C78(void*, short);
extern void* __register_global_object(void*, void*, DestructorChain*);

void fn_104_24CB8() {
    fn_104_24D00(lbl_104_bss_654);
    __register_global_object(
        lbl_104_bss_654,
        (void*)fn_104_24C78,
        (DestructorChain*)lbl_104_bss_648
    );
}
}

__declspec(section ".ctors") extern void* const fn_104_24CB8_ctor = (void*)fn_104_24CB8;
