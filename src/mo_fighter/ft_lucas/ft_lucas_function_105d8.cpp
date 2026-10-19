#include <types.h>
#pragma force_active on

struct LucasClassInfoBlock {
    void* vtable;
    s32 pad;
    void* self_ptr;
};

extern "C" {
void __ct__11ftClassInfoFb(void* self, bool isNull);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, s32 kind, void* info);
extern char lbl_114_data_808C[];

LucasClassInfoBlock* fn_114_105D8(LucasClassInfoBlock* self) {
    __ct__11ftClassInfoFb(self, false);
    self->self_ptr = lbl_114_data_808C;
    self->vtable = lbl_114_data_808C + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x1a, self);
    return self;
}
}
