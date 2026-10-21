#pragma force_active on
struct ftCommonDataAccesser {
    ~ftCommonDataAccesser();
};

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern ftCommonDataAccesser g_ftCommonDataAccesser;
extern "C" void fn_27_149B98(void* p, int n);
extern DestructorChain lbl_27_bss_3200;

extern "C" void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern "C" void fn_27_149B7C() {
    __register_global_object(&g_ftCommonDataAccesser, (void*)fn_27_149B98, &lbl_27_bss_3200);
}

__declspec(section ".ctors") extern void* const fn_27_149B7C_ctor = (void*)fn_27_149B7C;
