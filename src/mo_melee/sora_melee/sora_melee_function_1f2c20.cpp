#include <types.h>
#pragma force_active on

struct FnObj {
    u8 pad[0x3c];
    u16 flags;
    u8 pad2[0x48 - 0x3e];
    s32 type;
};

struct FnOwner {
    u8 pad[0x4c];
    FnObj* arr[14];
};

extern "C" {
s32 fn_27_1F2C20(FnOwner* self, s32 idx) {
    if (&self->arr[0] != 0) {
        if (idx >= 0 && idx < 7) {
            s32 i = idx + 7;
            FnObj* obj = self->arr[i];
            if (obj != 0 && obj->type == 0x79 && !(obj->flags & 0x08)) {
                return 1;
            }
        }
    }
    return 0;
}
}
