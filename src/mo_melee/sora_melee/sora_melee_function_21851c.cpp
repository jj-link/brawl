#include <types.h>
#include <cm/cm_camera_controller.h>
#include <mt/mt_vector.h>
#include <orch_helpers.h>

#pragma force_active on

struct Entry {
    u32 id;
    int kind;
    u16 flags;
    s8 a, b;
    int c;
    Vec3f v10, v1c, v28, v34, v40;
    float f4c, radius;
    s8 p54, p55, p56;
    char pad57;
    int p58, p5c, p60;
};

struct Self {
    Entry entries[64];
    char pad1900[0x14];
    int count;
    int active;
};

extern "C" const float lbl_27_rodata_31B8[];
extern "C" void fn_27_219364(Entry*, s8, const Vec3f*, s8, int, float);

extern "C" void fn_27_21851C(
    Self* self, const Vec3f* pos, s8 p2, s8 p3,
    s8 p4, s8 p5, int kind, u8* used, float radius,
    u32 id, int flags, int p5c, int p60)
{
    const float* k = lbl_27_rodata_31B8;
    Vec3f delta;
    Vec3f temp;
    Entry* e = self->entries;
    int i;

    if (self->active > 0) {
        for (i = 0; i < 64; ++i, ++e) {
            if (used[i] && e->id == id)
                break;
        }
    }

    if (self->active <= 0 || i >= 64) {
        e = self->entries;
        for (i = 0; i < 64; ++i, ++e) {
            if (!(e->flags & 1))
                break;
        }

        if (i >= 64)
            return;

        e->id = id;
        e->flags = flags | 1;
        e->a = p4;
        e->kind = kind;

        e->v10 = e->v1c = e->v28 = *pos;
        e->f4c = k[2];
        e->v34 = e->v40 = (Vec3f(k[2], k[2], k[2]));
        e->f4c = k[2];
        e->p54 = p2;
        e->p58 = 0;
        e->b = 16;
        e->radius = radius;
        e->p55 = p3;
        e->c = 0;
        self->count++;
    } else {
        CameraController* camera = CameraController::getInstance();
        Vec3fSub_v0420ad(&temp, pos, &e->v28);
        delta = temp;

        if (pos->m_x + radius < camera->unk158) {
            if (delta.m_x < k[2])
                return;
        } else if (pos->m_x - radius > camera->unk15C) {
            if (delta.m_x > k[2])
                return;
        }

        if (pos->m_y + radius < camera->unk164) {
            if (delta.m_y < k[2])
                return;
        } else if (pos->m_y - radius > camera->unk160) {
            if (delta.m_y > k[2])
                return;
        }

        switch (p4) {
        case 0:
            switch (kind) {
            case 41:
                if (radius < k[14] &&
                    delta.m_z * delta.m_z +
                        (delta.m_x * delta.m_x + delta.m_y * delta.m_y) < k[15])
                    radius = k[16];
                break;
            case 42:
                radius = k[16];
                break;
            }
        }

        fn_27_219364(e, p4, pos, p2, flags, radius);
        used[i] = 0;
    }

    e->p5c = p5c;
    e->p60 = p60;
    e->p56 = p5;
}
