#include <types.h>
#pragma force_active on

extern "C" {

s32 fn_801832FC(void*, s32);

class Virt {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual s32 v6(s32) = 0;
};

struct Obj {
    u8 _pad[0xFC];
    void* m_arr;
    u8 m_count;
};

s32 fn_80185B14(Obj* self, s32 arg1) {
    s32 r = fn_801832FC(self, arg1);
    if (r != 0) return r;
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    while (i < (s32)self->m_count) {
        Virt* v = *(Virt**)((char*)self->m_arr + off + 4);
        s32 r2 = v->v6(arg1);
        if (r2 != 0) return r2;
        off += 8;
        i++;
    }
    return 0;
}

}
