#include <types.h>
#pragma force_active on

extern "C" {
void* __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern u8 lbl_106_data_50[];
}

struct MarthParamAccesser {
    void* a;
    u32 b;
    void* c;
};

extern "C" MarthParamAccesser* fn_106_A41C(MarthParamAccesser* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x11);
    self->c = lbl_106_data_50;
    self->a = lbl_106_data_50 + 8;
    return self;
}
