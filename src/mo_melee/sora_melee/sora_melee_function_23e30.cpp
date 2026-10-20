#include <types.h>
#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Src {
    u8 pad0[0xc];
    float a;
    u8 pad1[0xc];
    float b;
    u8 pad2[0xc];
    float c;
};

class Target {
public:
    virtual ~Target();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf7(Vec3* v);
    u8 pad[0x64 - 4];
    u32 m_id;
};

extern "C" {
void fn_27_23E30(Target* self, u32 id, Src* src) {
    if (id == self->m_id) {
        Vec3 v;
        float c = src->c;
        float b = src->b;
        float a = src->a;
        v.y = b;
        v.x = a;
        v.z = c;
        self->vf7(&v);
    }
}
}
