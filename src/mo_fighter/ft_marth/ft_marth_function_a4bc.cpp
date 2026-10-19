#include <types.h>
#pragma force_active on

struct MarthInfoHolder {
    void* vtbl;   // 0x00
    u32 pad04;    // 0x04
    void* base;   // 0x08
};

extern "C" {
extern char lbl_106_data_53B4[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, s32 kind, void* info);
void* __dt__11ftClassInfoFv(void* self, s16 flag);
void __dl__FPv(void* p);
}

extern "C" MarthInfoHolder* fn_106_A4BC(MarthInfoHolder* self, s16 flag) {
    if (self != 0) {
        self->base = lbl_106_data_53B4;
        self->vtbl = lbl_106_data_53B4 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x11, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
