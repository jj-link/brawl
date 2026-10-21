#pragma force_active on
extern "C" {
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};
extern DestructorChain *__global_destructor_chain;
void fn_121_110C0(void *);
void *fn_121_11038(void *, short);
void *__register_global_object(void *, void *, DestructorChain *);
extern unsigned char lbl_121_bss_1BC[4];
extern unsigned char lbl_121_bss_1B0[12];
}

extern "C" void fn_121_11078()
{
    fn_121_110C0(lbl_121_bss_1BC);
    __register_global_object(lbl_121_bss_1BC,
                             (void *)fn_121_11038,
                             (DestructorChain *)lbl_121_bss_1B0);
}

__declspec(section ".ctors") extern void* const fn_121_11078_ctor = (void*)fn_121_11078;
