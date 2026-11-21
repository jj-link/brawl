#include <mt/mt_vector.h>
#include <orch_helpers.h>
#pragma force_active on

extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);

struct Entry {
    char pad0[8];
    unsigned short flags;
    signed char type;
    char pad1[0x1D];
    Vec3f pos;
    char pad2[0x30];
};

struct Self {
    Entry entries[64];
    unsigned char bits[8];
    int count;
    int a;
    int b;
    int size;
};

extern "C" int fn_27_218ED0(Self* self, Vec3f* pos, float radius) {
    self->a = 0;
    self->b = 0;
    if (self->size <= 0) {
        self->count = 0;
        return 0;
    }

    gfMemFill__FPvUcUl(self->bits, 0, 8);

    float rsq = radius * radius;
    int count = 0;
    int i = 0;
    Entry* e = self->entries;
    for (; i < 64; ++i, ++e) {
        if ((e->flags & 1) && e->type == 2) {
            Vec3f diff;
            Vec3fSub_v0420ad(&diff, pos, &e->pos);
            float len2 = diff.m_x * diff.m_x + diff.m_y * diff.m_y + diff.m_z * diff.m_z;
            if (!(len2 > rsq)) {
                ++count;
                self->bits[i / 8] |= 1 << (i % 8);
            }
        }
    }
    self->count = count;
    return count;
}
