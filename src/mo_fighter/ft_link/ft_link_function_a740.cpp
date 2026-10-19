#include <types.h>
#pragma force_active on

extern "C" {

struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
};

void fn_27_2DE758(void* p);
void* fn_27_2DE768(void* p, s32 n);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern signed char lbl_93_bss_134;
extern unsigned char lbl_93_bss_138[8];
extern DestructorChain lbl_93_bss_120;

void* fn_93_A740() {
    if (!lbl_93_bss_134) {
        fn_27_2DE758(lbl_93_bss_138);
        __register_global_object(lbl_93_bss_138, (void*)fn_27_2DE768, &lbl_93_bss_120);
        lbl_93_bss_134 = 1;
    }
    return lbl_93_bss_138;
}
}
