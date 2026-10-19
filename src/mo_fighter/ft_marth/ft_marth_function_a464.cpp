#include <types.h>
#pragma force_active on

extern "C" {
void __ct__11ftClassInfoFb(void* self, bool isNull);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, s32 kind, void* info);
extern char lbl_106_data_53B4[];
}

struct MarthClassInfoSelf {
    char* vtbl;
    u32 pad;
    char* base;
};

extern "C" {
MarthClassInfoSelf* fn_106_A464(MarthClassInfoSelf* self) {
    __ct__11ftClassInfoFb(self, false);
    self->base = lbl_106_data_53B4;
    self->vtbl = lbl_106_data_53B4 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x11, self);
    return self;
}
}
