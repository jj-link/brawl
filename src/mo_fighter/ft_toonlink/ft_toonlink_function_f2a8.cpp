#pragma force_active on
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};

extern "C" {
extern unsigned char lbl_121_bss_14C[];
extern DestructorChain lbl_121_bss_140[];
void fn_121_F2F0(void *);
void *fn_121_F264(void *, short);
void *__register_global_object(void *, void *, DestructorChain *);

void fn_121_F2A8() {
    fn_121_F2F0(lbl_121_bss_14C);
    __register_global_object(
        lbl_121_bss_14C,
        (void *)fn_121_F264,
        lbl_121_bss_140
    );
}
}

__declspec(section ".ctors") extern void* const fn_121_F2A8_ctor = (void*)fn_121_F2A8;
