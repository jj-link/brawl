#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_27_data_4BDC8[];
extern "C" const char lbl_27_data_4BEC0[];
extern "C" void fn_27_236400(void*, void*);

extern "C" void fn_27_233B58(void* self, void* p) {
    if (__dynamic_cast(*(void**)((char*)self + 0x18), 4, lbl_27_data_4BDC8, lbl_27_data_4BEC0, 0)) {
        fn_27_236400(__dynamic_cast(*(void**)((char*)self + 0x18), 4, lbl_27_data_4BDC8, lbl_27_data_4BEC0, 0), p);
    }
}
