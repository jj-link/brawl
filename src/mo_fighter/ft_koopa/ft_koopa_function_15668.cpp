#pragma force_active on
typedef void (*Destructor)(void*, short);

struct DestructorChain
{
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
extern void* lbl_102_bss_4EC;
extern DestructorChain lbl_102_bss_4E0;
void fn_102_156B0(void**);
void* fn_102_15628(void*, short);
void* __register_global_object(void*, void*, DestructorChain*);
}

extern "C" void fn_102_15668()
{
    fn_102_156B0((void**)&lbl_102_bss_4EC);
    __register_global_object(&lbl_102_bss_4EC, (void*)fn_102_15628,
                             &lbl_102_bss_4E0);
}

__declspec(section ".ctors") extern void* const fn_102_15668_ctor = (void*)fn_102_15668;
