#include <types.h>
#pragma force_active on

class Class_80486468 {
public:
    virtual void fn_80280E3C();
    virtual void fn_80080A64();
    virtual u32 fn_80281234();
    virtual s32 fn_802810D0(char* data, s32 size);
};

struct Ctx {
    u8 pad[0x8];
    Class_80486468* src;
    char* data;
    s32 off;
    s32 cur;
    s32 end;
};

extern "C" {
void fn_80280F00(Ctx* self);

s32 fn_80280FF4(Ctx* self) {
    s8 z = (s8)((s8)(self->src->fn_80281234() >> 24) == 0);
    if (z) {
        return 1;
    }
    fn_80280F00(self);
    s32 remain = self->end - self->cur;
    s32 total = 0;
    while (total < remain) {
        s32 n = self->src->fn_802810D0(self->data + self->off, remain);
        total += n;
        self->cur += n;
        if (n != remain) {
            return total == 0;
        }
    }
    return 0;
}
}
