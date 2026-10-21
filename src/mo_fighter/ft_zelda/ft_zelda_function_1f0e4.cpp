#pragma force_active on
struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
void fn_104_1F12C(void* ptr);
void* fn_104_1F0A4(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
extern void* lbl_104_bss_514;
extern DestructorChain lbl_104_bss_508;
}

extern "C" void fn_104_1F0E4(void)
{
    fn_104_1F12C(&lbl_104_bss_514);
    __register_global_object(&lbl_104_bss_514, (void*)fn_104_1F0A4, &lbl_104_bss_508);
}

__declspec(section ".ctors") extern void* const fn_104_1F0E4_ctor = (void*)fn_104_1F0E4;
