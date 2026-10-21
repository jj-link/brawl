#pragma force_active on
struct DestructorChain;

extern "C" {
extern unsigned char lbl_124_bss_24C[];
extern unsigned char lbl_124_bss_240[];
void fn_124_BCE4(void*);
void* fn_124_BC5C(void*, short);
void* __register_global_object(void*, void*, DestructorChain*);
}

extern "C" void fn_124_BC9C()
{
    fn_124_BCE4(lbl_124_bss_24C);
    __register_global_object(
        lbl_124_bss_24C,
        reinterpret_cast<void*>(fn_124_BC5C),
        reinterpret_cast<DestructorChain*>(lbl_124_bss_240));
}

__declspec(section ".ctors") extern void* const fn_124_BC9C_ctor = (void*)fn_124_BC9C;
