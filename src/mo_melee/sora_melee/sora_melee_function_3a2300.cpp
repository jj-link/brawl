#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_9C878[];
extern char lbl_27_bss_8A38[12];
void* fn_27_3A22C0(void* p, s32 n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8A44;

extern "C" void fn_27_3A2300(void) {
    lbl_27_bss_8A44.vtable = 0;
    lbl_27_bss_8A44.vtable = (void*)&lbl_27_data_9C878;
    __register_global_object(&lbl_27_bss_8A44, (void*)fn_27_3A22C0, lbl_27_bss_8A38);
}

__declspec(section ".ctors") extern void* const fn_27_3A2300_ctor = (void*)fn_27_3A2300;
