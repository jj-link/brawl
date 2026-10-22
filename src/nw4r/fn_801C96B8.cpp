#include <types.h>
#pragma force_active on

extern "C" {

class VA {
public:
    virtual s32 a2(s32 x) = 0;
    virtual s32 a3() = 0;
};

struct Ent {
    u32 a;
    u32 b;
};

struct Obj {
    char pad[0x10];
    VA* m10;
    Ent* m14;
    VA* m18;
};

s32 fn_801C6C24(VA* self, s32 idx, u32 v, u32* out);
s32 fn_801C6C2C(VA* self, s32 arg, u32* out);
s32 fn_801C6C34(VA* self, s32 arg, u32 i, u32* out);

s32 fn_801C96B8(Obj* self, s32 arg1) {
    u32 sp20[8];
    u32 sp10[4];
    u32 sp8[2];
    s32 v;
    u32 i;
    s32 r;
    Ent* t;
    u32 idx;

    r = self->m10->a3();
    if (r != 0) {
        return r;
    }
    if (self->m18 != 0) {
        r = self->m18->a2(arg1);
        if (r != 0) {
            return r;
        }
    }
    if (fn_801C6C2C(self->m10, arg1, sp10) == 0) {
        return 0;
    }
    for (i = 0; i < sp10[3]; i++) {
        if (fn_801C6C34(self->m10, arg1, i, sp8) != 0) {
            idx = sp8[0];
            t = self->m14;
            if (t == 0) {
                v = 0;
            } else if (idx >= t->a) {
                v = 0;
            } else {
                v = t[idx].b;
            }
            if (v != 0 && fn_801C6C24(self->m10, idx, sp8[1], sp20) != 0) {
                return v + sp20[1];
            }
        }
    }
    return 0;
}

}
