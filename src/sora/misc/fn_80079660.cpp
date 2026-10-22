#include <types.h>
#pragma force_active on

extern "C" void fn_801C6050(void* self, void* src);
extern float lbl_805A1B08;

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

class snd3DGenerator {
public:
    void setPos(Vec3f* v);
    void* m_00;
};

static inline u32 expBits(f32 f) {
    union {
        f32 f;
        u32 u;
    } c;
    c.f = f;
    return (c.u >> 23) & 0xFF;
}

void snd3DGenerator::setPos(Vec3f* v) {
    if (m_00 != 0) {
        s32 ok;
        ok = 1;
        if (expBits(v->x) == 0xFF) {
            ok = 0;
        }
        if (ok != 0) {
            ok = 1;
            if (expBits(v->y) == 0xFF) {
                ok = 0;
            }
            if (ok != 0) {
                ok = 1;
                if (expBits(v->z) == 0xFF) {
                    ok = 0;
                }
                if (ok != 0) {
                    goto call;
                }
            }
        }
        {
            f32 zero = lbl_805A1B08;
            v->x = zero;
            v->y = zero;
            v->z = zero;
        }
    call:
        fn_801C6050(m_00, v);
    }
}
