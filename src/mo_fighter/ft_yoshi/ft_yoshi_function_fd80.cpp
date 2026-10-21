#pragma force_active on
typedef struct DestructorChain DestructorChain;
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};

extern "C" void fn_95_FDC8(void *);
extern "C" void fn_95_FD40(void *, int);
extern "C" void *__register_global_object(void *, void *, DestructorChain *);

extern "C" {
extern unsigned char lbl_95_bss_3BC[];
extern DestructorChain lbl_95_bss_3B0;
}

extern "C" void fn_95_FD80(void)
{
    fn_95_FDC8(lbl_95_bss_3BC);
    __register_global_object(lbl_95_bss_3BC, (void *)fn_95_FD40, &lbl_95_bss_3B0);
}

__declspec(section ".ctors") extern void* const fn_95_FD80_ctor = (void*)fn_95_FD80;
