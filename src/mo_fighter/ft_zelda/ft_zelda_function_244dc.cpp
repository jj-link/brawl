#pragma force_active on
struct DestructorChain {
    void* mNext;
    void* mDestructor;
    void* mObject;
};

extern "C" {
void fn_104_24524(void*);
void* fn_104_2449C(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern void* lbl_104_bss_614;
extern unsigned char lbl_104_bss_608[12];
}

extern "C" void fn_104_244DC() {
    fn_104_24524(&lbl_104_bss_614);
    __register_global_object(&lbl_104_bss_614, (void*)fn_104_2449C,
                             (DestructorChain*)&lbl_104_bss_608);
}

__declspec(section ".ctors") extern void* const fn_104_244DC_ctor = (void*)fn_104_244DC;
