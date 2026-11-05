#include <nw4r/math/math_types.h>
#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_common.h>
#include <math.h>
#pragma force_active on

extern const float lbl_805A1CA8;
extern const float lbl_805A1CDC;

struct Node {
    char pad0[0x34];
    nw4r::math::VEC3 previous;
    nw4r::math::VEC3 position;
    char pad4c[0x34];
    float limit;
    char pad84[0x2c];
    float value;
};

struct Object {
    Node** nodes;
    int count;
    char pad08[0x3b];
    unsigned char active;
    char pad44[0x11];
    unsigned char flag;
    char pad56[0xa];
    float value;
};

extern "C" void fn_80091F28(Object* self) {
    self->value = self->nodes[1]->value;

    if (self->flag == 0) {
        for (int i = (int)((unsigned)self->count - self->active - 1U);
             i >= 0; --i) {
            self->nodes[i]->value = lbl_805A1CA8;
        }
    } else {
        if (self->active <= self->count && self->active >= 2) {
            nw4r::math::VEC3 delta;
            delta = self->nodes[self->active - 1]->position
                  - self->nodes[self->active - 2]->position;

            float sq = delta.z * delta.z
                     + (delta.x * delta.x + delta.y * delta.y);
            float length;
            if ((float)fabs(sq) <= lbl_805A1CDC) {
                length = lbl_805A1CA8;
            } else {
                length = sq * rsqrtf(sq);
            }

            Node* preceding = self->nodes[self->active - 2];
            if (length < preceding->limit) {
                delta = preceding->previous
                      - self->nodes[self->active - 1]->position;
                nw4r::math::VEC3Add(
                    &self->nodes[self->active - 1]->position,
                    &self->nodes[self->active - 1]->position,
                    &delta);
                nw4r::math::VEC3Add(
                    &self->nodes[self->active - 1]->previous,
                    &self->nodes[self->active - 1]->previous,
                    &delta);
            }
        }

        int i = self->active;
        while (i < self->count) {
            self->nodes[i]->value = lbl_805A1CA8;
            ++i;
        }
    }
}