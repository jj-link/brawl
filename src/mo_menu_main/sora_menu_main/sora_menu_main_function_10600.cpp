#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <snd/snd_system.h>

#pragma force_active on
#pragma fp_contract off

extern "C" {
extern const float lbl_2_rodata_408[];
float rsqrtf__Ff(float);
void fn_8003DBA8(Vec2f*);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
void fn_2_109F0(void*);
}

struct Item {
    Vec2f pos;
    float z;
};

struct Model {
    char pad[12];
    void* ptr;
};

struct Menu {
    char p0[0x54];
    unsigned selected;
    char p1[0xb0];
    unsigned group;
    char p2[0x208];
    Item items[1000];
    unsigned offsets[1000];
    unsigned counts[2];
    char p3[0x1020];
    Model* models[1];
};

#define CASE(N, X, Y)                                                        \
    case N: {                                                                \
        dir.m_x = X;                                                         \
        dir.m_y = Y;                                                         \
        if (first) {                                                         \
            best = (delta.m_x * dir.m_x + delta.m_y * dir.m_y) / distance;  \
            if (best >= k[24]) {                                             \
                selected = i;                                                \
                first = 0;                                                   \
            }                                                                \
        } else {                                                             \
            float score =                                                    \
                (delta.m_x * dir.m_x + delta.m_y * dir.m_y) / distance;      \
            if (score > best) {                                              \
                best = score;                                                \
                selected = i;                                                \
            }                                                                \
        }                                                                    \
        break;                                                               \
    }

extern "C" int fn_2_10600(Menu* self, int direction) {
    const float* k = lbl_2_rodata_408;
    unsigned* counts = &self->counts[self->group];
    unsigned count = counts[0] + counts[1];
    unsigned selected = 0;
    int first = 1;
    Vec2f dir;
    Vec2f delta;
    Vec2f origin;
    Vec2f* start = &self->items[self->selected + self->offsets[self->group]].pos;
    origin.m_y = start->m_y;
    origin.m_x = start->m_x;
    float best;

    for (unsigned i = 0; i < count; ++i) {
        if (i != self->selected) {
            Vec2f* pos = &self->items[i + self->offsets[self->group]].pos;
            float py = pos->m_y;
            float ox = origin.m_x;
            float px = pos->m_x;
            float y = py - origin.m_y;
            float x = px - ox;
            delta.m_y = y;
            delta.m_x = x;
            float sq = delta.m_x * delta.m_x + delta.m_y * delta.m_y;
            float distance;
            if ((float)(double)nw4r::ut::Abs(sq) <= k[22])
                distance = k[5];
            else
                distance = sq * rsqrtf__Ff(sq);
            distance *= k[23];
            fn_8003DBA8(&delta);

            switch (direction) {
                CASE(0, k[5], k[3])
                CASE(1, k[5], k[4])
                CASE(2, k[4], k[5])
            case 3: {
                dir.m_x = k[3];
                dir.m_y = k[5];
                if (first) {
                    best = (delta.m_x * dir.m_x + delta.m_y * dir.m_y) / distance;
                    if (best >= k[24]) {
                        selected = i;
                        first = 0;
                    }
                } else {
                    float score =
                        (delta.m_x * dir.m_x + delta.m_y * dir.m_y) / distance;
                    if (score > best) {
                        selected = i;
                        best = score;
                    }
                }
                break;
            }
            }
        }
    }

    if (!first) {
        direction = (int)self->models[self->selected];
        fn_801AAFF0(((Model*)direction)->ptr, 0x13);
        fn_801AB014(((Model*)direction)->ptr, 0x13);
        self->selected = selected;
        fn_2_109F0(self);
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        return 1;
    }
    return 0;
}
