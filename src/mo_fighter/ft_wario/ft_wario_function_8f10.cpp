#include <stddef.h>
#pragma force_active on

struct WarioDestructorChain {
    void* next;
    void* destructor;
    void* object;
};

struct WarioHandlerBlob {
    void* vtable;
    unsigned int m_state;
};

struct WarioDispatch {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(void*, void*);
};

extern "C" {
extern signed char lbl_110_bss_17C;
extern WarioHandlerBlob lbl_110_bss_180;
extern WarioDestructorChain lbl_110_bss_168;

void fn_27_356820(void*);
void fn_27_356830(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_135EDC(void*, void*, void*);
}

extern "C" void fn_110_8F10(void* arg1, void* arg2, void* arg3) {
    if (lbl_110_bss_17C == 0) {
        fn_27_356820(&lbl_110_bss_180);
        __register_global_object(&lbl_110_bss_180,
                                 reinterpret_cast<void*>(fn_27_356830),
                                 &lbl_110_bss_168);
        lbl_110_bss_17C = 1;
    }
    reinterpret_cast<WarioDispatch*>(&lbl_110_bss_180)->v10(arg2, arg3);
    fn_27_135EDC(arg1, arg2, arg3);
}
