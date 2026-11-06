#include <types.h>
#pragma force_active on

extern "C" {

class ArrInterface {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void size(s32* out) = 0;
    virtual f32* data() = 0;
};

struct MainObj {
    char pad[0x14];
    ArrInterface* m_arr;
    char pad2[0x8];
    f32 m_f0;
    f32 m_f1;
    f32 m_f2;
    f32 m_f3;
};

f32* fn_802D1358(MainObj* self, f32* dest) {
    f32* src = self->m_arr->data();
    f32* dst = dest;
    s32 count;
    self->m_arr->size(&count);
    for (s32 i = 0; i < count; i++) {
        dst[0] = src[0] + self->m_f0;
        dst[1] = src[1] + self->m_f1;
        dst[2] = src[2] + self->m_f2;
        dst[3] = src[3] + self->m_f3;
        src += 4;
        dst += 4;
    }
    return dest;
}

}
