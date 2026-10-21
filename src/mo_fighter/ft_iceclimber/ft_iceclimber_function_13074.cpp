#pragma force_active on
typedef unsigned char u8;

struct DestructorChain
{
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
extern u8 lbl_105_bss_27C[];
extern u8 lbl_105_bss_270[];
void fn_105_130BC(void*);
void* fn_105_13024(void*, short);
void* __register_global_object(void*, void*, DestructorChain*);
}

extern "C" void fn_105_13074()
{
    fn_105_130BC(lbl_105_bss_27C);
    __register_global_object(
        lbl_105_bss_27C,
        (void*)fn_105_13024,
        (DestructorChain*)lbl_105_bss_270);
}

__declspec(section ".ctors") extern void* const fn_105_13074_ctor = (void*)fn_105_13074;
