#include <types.h>
#pragma force_active on

extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_114_data_44[];

extern "C" void* fn_114_10590(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x1a);
    void** words = reinterpret_cast<void**>(self);
    words[2] = lbl_114_data_44;
    words[0] = lbl_114_data_44 + 8;
    return self;
}
