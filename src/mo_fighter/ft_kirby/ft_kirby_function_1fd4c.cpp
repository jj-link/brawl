#include <cstddef>
#pragma force_active on

// Shapes of the .bss residents referenced below.
struct KirbyDestructorChain {
    void* next;
    void* destructor;
    void* object;
};
struct KirbyHandlerBlob {
    void* vtable;
};

extern "C" {
extern KirbyDestructorChain lbl_96_bss_E50;
extern signed char lbl_96_bss_FD8;
extern KirbyHandlerBlob lbl_96_bss_FDC;

void fn_27_328A0C(void* handler);
void fn_27_328A48(void* handler, short destroy);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_1FD4C() {
    if (lbl_96_bss_FD8 == 0) {
        fn_27_328A0C(&lbl_96_bss_FDC);
        __register_global_object(&lbl_96_bss_FDC, reinterpret_cast<void*>(fn_27_328A48),
                                 &lbl_96_bss_E50);
        lbl_96_bss_FD8 = 1;
    }
    return &lbl_96_bss_FDC;
}
