#pragma force_active on
typedef unsigned char u8;

#include <gf/gf_shutdown_manager.h>

extern "C" {
extern u8 lbl_16_data_3568[];
void fn_16_228C(void*, void*);
void remove__26gfReturnStatusCallbackListFP22gfReturnStatusCallback(void*, void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_16_220C(u8* object, int flag) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_16_data_3568;
        fn_16_228C(object, lbl_16_data_3568);
        remove__26gfReturnStatusCallbackListFP22gfReturnStatusCallback(&g_gfShutdownManager.unk8, object + 0x46C);
        __dt__6gfTaskFv(object, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
