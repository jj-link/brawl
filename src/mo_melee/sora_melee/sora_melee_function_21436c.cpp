#include <orch_helpers.h>
#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

#pragma fp_contract off

extern "C" {
void* fn_27_1F1F58(signed char* id);
void fn_27_1F9FBC(void* self, int mode, signed char* id, unsigned int script, int argument);
void fn_27_1FAC54(void* p, int argument);
float rsqrtf__Ff(float x);
extern const float lbl_27_rodata_3000[];
}

extern "C" void fn_27_21436C(void* arg0) {
    char* self = (char*)arg0;
    float* rod = (float*)lbl_27_rodata_3000;

    if (*(unsigned short*)(self + 0x78) == 0x10A0 &&
        (*(unsigned char*)((char*)fn_27_1F1F58(
             (signed char*)(*(char**)(self + 0x70) + 0x110)) + 0x1BA) == 4 ||
         *(unsigned char*)((char*)fn_27_1F1F58(
             (signed char*)(*(char**)(self + 0x70) + 0x110)) + 0x1BA) == 6)) {
        unsigned short value = *(unsigned short*)(self + 0x78);
        if (value != 0) {
            *(unsigned short*)(self + 0x7C) = value;
        }
        *(unsigned short*)(self + 0x78) = 0;
        fn_27_1FAC54(*(void**)(self + 0x70), 0);
        return;
    }

    float bestDistance = rod[0x140 / 4];
    float epsilon = rod[0x10 / 4];
    signed char id[4];
    int i = 0;
    int bestId;

    for (; i < 7; ++i) {
        id[0] = (signed char)i;
        char* state = (char*)fn_27_1F1F58(&id[0]);
        unsigned char kind;
        unsigned int flags = *(unsigned int*)(state + 0x50);

        if (!(flags & 0x8000)) {
            kind = *(unsigned char*)(state + 0x1BA);
            if (kind != 5 && kind != 4 && !(flags & 0x40000000) &&
                kind != 9 && !(flags & 0x400000) && kind != 0xE &&
                *(int*)(state + 0xCC) != *(int*)(*(char**)(self + 0x74) + 0xCC)) {
                Vec3f difference;
                Vec3fSub_v0420ad(&difference, (const Vec3f*)(state + 0x5C),
                                 (const Vec3f*)(*(char**)(self + 0x74) + 0x5C));

                float squaredDistance =
                    difference.m_z * difference.m_z +
                    (difference.m_x * difference.m_x + difference.m_y * difference.m_y);
                float absoluteDistance = (float)(double)nw4r::math::FAbs(squaredDistance);
                float distance = absoluteDistance <= epsilon
                                     ? rod[0]
                                     : squaredDistance * rsqrtf__Ff(squaredDistance);

                if (bestDistance > distance) {
                    bestDistance = distance;
                    bestId = i;
                }
            }
        }
    }

    if (bestDistance < rod[0x58 / 4] &&
        bestId != *(signed char*)(*(char**)(self + 0x70) + 0x110)) {
        signed char resultId = (signed char)bestId;
        fn_27_1F9FBC(*(void**)(self + 0x70), 1, &resultId, 0, 1);
        *(unsigned char*)(*(char**)(self + 0x70) + 0x111) = 1;
        *(unsigned short*)(self + 0x7E) = 1;
    }
}
