#include <types.h>
#pragma force_active on

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_225A14(void*);

extern "C" void fn_27_227B68(void* this_, u8 arg) {
    u8* self = (u8*)this_;
    if (self[4] == 1) {
        if (*(void**)(self + 0x0C))
            Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)(self + 0x0C));
        if (*(void**)(self + 0x10))
            Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)(self + 0x10));
    }
    if (*(void**)(self + 0x50))
        __dl__FPv(*(void**)(self + 0x50));
    fn_27_225A14(this_);
    self[0x62] = arg;
    self[0x61] = 1;
}
