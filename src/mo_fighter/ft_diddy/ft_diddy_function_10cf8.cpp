#pragma force_active on
struct DestructorChain
{
    DestructorChain *next;
    void *destructor;
    void *object;
};

extern "C" {
extern char lbl_115_bss_2F4[];
extern DestructorChain lbl_115_bss_2E8;

void *fn_115_10D40(void *object);
void *fn_115_10CB8(void *slot, short destroy);
void *__register_global_object(void *object, void *destructor, DestructorChain *chain);

void fn_115_10CF8(void)
{
    fn_115_10D40(lbl_115_bss_2F4);
    __register_global_object(lbl_115_bss_2F4,
                             (void *) fn_115_10CB8,
                             &lbl_115_bss_2E8);
}
}

__declspec(section ".ctors") extern void* const fn_115_10CF8_ctor = (void*)fn_115_10CF8;
