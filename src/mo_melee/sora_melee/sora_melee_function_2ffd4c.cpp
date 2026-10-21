#include <types.h>
#pragma force_active on

extern char lbl_27_bss_7620[];
extern char lbl_27_data_81608[];
extern char lbl_27_bss_7614[];

extern "C" {
    void fn_27_1E82E8(void* self, int flag);
    void fn_27_1E847C(void* self, int size, void* self2);
    void fn_27_2FFDC8(void* self);
    void __register_global_object(void* obj, void* dtor, void* handle);

    void fn_27_2FFD4C() {
        fn_27_1E82E8(lbl_27_bss_7620, 0);
        *(void**)(lbl_27_bss_7620 + 8) = lbl_27_data_81608;
        *(void**)(lbl_27_bss_7620 + 0) = lbl_27_data_81608 + 8;
        fn_27_1E847C(lbl_27_bss_7620, 0x53, lbl_27_bss_7620);
        __register_global_object(lbl_27_bss_7620, (void*)fn_27_2FFDC8, lbl_27_bss_7614);
    }
}

__declspec(section ".ctors") extern void* const fn_27_2FFD4C_ctor = (void*)fn_27_2FFD4C;
