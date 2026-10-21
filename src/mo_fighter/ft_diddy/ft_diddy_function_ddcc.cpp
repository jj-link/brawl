#pragma force_active on
extern "C" {

typedef struct Object
{
    void *vtable;
} Object;

typedef struct DestructorChain
{
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern Object lbl_115_bss_264;
extern DestructorChain lbl_115_bss_258;

void fn_115_DE14(Object *object);
void *fn_115_DD8C(void *ptr, short size);
void *__register_global_object(void *object, void *destructor, DestructorChain *chain);

void fn_115_DDCC(void)
{
    fn_115_DE14(&lbl_115_bss_264);
    __register_global_object(&lbl_115_bss_264, (void *)fn_115_DD8C, &lbl_115_bss_258);
}

}

__declspec(section ".ctors") extern void* const fn_115_DDCC_ctor = (void*)fn_115_DDCC;
