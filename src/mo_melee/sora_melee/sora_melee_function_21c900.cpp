#include <mt/mt_vector.h>
#include <orch_helpers.h>
#pragma force_active on

struct Entry {
    u8 pad0[6];
    u16 flags;
    u8 pad8[4];
    Vec3f pos;
    u8 pad18[12];
};

struct Base {
    Entry entries[32];
    s32 count;
};

extern f32 lbl_27_rodata_3288;

extern "C" Entry* fn_27_21C900(Base* base, Vec3f* pos, f32* out) {
    s32 i;
    Entry* e;
    s32 count = base->count;
    if (count > 0) {
    s32 best = -1;
    f32 bestDist = lbl_27_rodata_3288;
    e = base->entries;
    for (i = 0; i < 32; i++, e++) {
        if ((e->flags & 1) && !(e->flags & 4)) {
            Vec3f d;
            Vec3fSub_v0420ad(&d, &e->pos, pos);
            f32 dist = d.m_x * d.m_x + d.m_y * d.m_y + d.m_z * d.m_z;
            if (best < 0 || bestDist > dist) {
                bestDist = dist;
                best = i;
            }
            count--;
            if (count <= 0) {
                break;
            }
        }
    }
    if (best >= 0) {
        if (out != NULL) {
            *out = bestDist;
        }
        return &base->entries[best];
    }
    }
    return NULL;
}
