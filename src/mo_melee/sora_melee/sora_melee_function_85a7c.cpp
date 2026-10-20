#include <types.h>
#pragma force_active on

extern "C" {
    extern signed char lbl_27_bss_1688;
    extern char lbl_27_bss_168C[];
    extern char lbl_27_data_1F88[];
    extern char lbl_27_bss_FBC[];
    void fn_27_86D8C(void* p, int n);
    void* __register_global_object(void* object, void* destructor, void* chain);

    void* fn_27_85A7C() {
        if (lbl_27_bss_1688 == 0) {
            char* p = lbl_27_bss_168C;
            char* v = lbl_27_data_1F88;
            *(int*)(p + 8) = 0;
            *(char**)(p + 4) = v;
            *(int*)(p + 0xC) = 0;
            *(int*)(p + 0x10) = 0;
            __register_global_object(p, (void*)fn_27_86D8C, lbl_27_bss_FBC);
            lbl_27_bss_1688 = 1;
        }
        return lbl_27_bss_168C;
    }
}
