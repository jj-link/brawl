#include <types.h>
#pragma force_active on

struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
    void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
    void* fn_52_6998(void* p, s32 n);

    extern char lbl_52_bss_3C;
    extern unsigned char lbl_52_data_14D0[];
    extern unsigned char lbl_52_data_1528[];
    extern struct {
        char flag;
        char pad[3];
        void* ptr;
    } lbl_52_bss_40;
    extern DestructorChain lbl_52_bss_18;
}

extern "C" void* fn_52_68D4() {
    if (!lbl_52_bss_3C) {
        lbl_52_bss_40.ptr = (void*)lbl_52_data_1528;
        lbl_52_bss_40.flag = 1;
        lbl_52_bss_40.ptr = (void*)lbl_52_data_14D0;
        __register_global_object((void*)&lbl_52_bss_40, (void*)fn_52_6998, &lbl_52_bss_18);
        lbl_52_bss_3C = 1;
    }
    return (void*)&lbl_52_bss_40;
}
