#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
void getHipPos__23ftExternalValueAccesserFP7Fighter(void*, void*);
extern const float lbl_27_rodata_FB8[4];

void* fn_27_115E3C(void* self, float* target, int idx, float* out_min, float f) {
    const float* constants = lbl_27_rodata_FB8;
    Vec3f hip;
    float high;
    float base;
    float min;
    void* ent;
    void* result = 0;
    unsigned char count;

    min = constants[2];

    if (idx == 0)
        count = 1;
    else
        count = *(unsigned char*)((char*)self + 8);

    high = constants[3];
    int counter = 0;
    base = constants[0];

    for (; counter < (int)count; counter++) {
        if (counter == 0)
            ent = *(void**)((char*)self + *(unsigned char*)((char*)self + 0xa) * 8 + 0x34);
        else
            ent = *(void**)((char*)self + 0x3c);

        getHipPos__23ftExternalValueAccesserFP7Fighter(&hip, ent);

        if (base != f) {
            if (high == f) {
                if (hip.m_x > target[0])
                    break;
            } else {
                if (hip.m_x < target[0])
                    break;
            }
        }

        Vec2f goal;
        Vec2f current;
        Vec2f delta;
        current.m_x = hip.m_x;
        current.m_y = hip.m_y;
        goal.m_x = target[0];
        goal.m_y = target[1];
        delta.m_x = goal.m_x - current.m_x;
        delta.m_y = goal.m_y - current.m_y;
        float dist2 = delta.m_x * delta.m_x + delta.m_y * delta.m_y;

        if (dist2 < min) {
            min = dist2;
            result = ent;
        }
    }

    *out_min = min;
    return result;
}
}
