#pragma force_active on

#include <types.h>
#include <nw4r/ut/ut_algorithm.h>

struct Env {
    u32 f20;
    u32 f24;
    u32 f18;
    u32 f1c;
};

struct State {
    char pad[0xBC];
    Env* env;
    u8 status;
};

extern "C" {
extern const float lbl_27_rodata_2F68[];
float fn_27_21F1BC(s8*);
}

extern "C" float fn_27_20BCBC(State* arg0, float* arg1, float farg0) {
    const float* k = lbl_27_rodata_2F68;
    float result;
    float f30 = k[1];
    char* p = (char*)arg0->env + 0x18;
    Env v;
    v.f18 = *(u32*)p;
    v.f1c = *(u32*)(p + 4);
    v.f20 = *(u32*)(p + 8);
    v.f24 = *(u32*)(p + 12);

    if (arg0->status == 2) {
        float f3 = *arg1;
        if (f3 < *(float*)&v.f18) {
            f30 = k[13];
            result = nw4r::ut::Abs(f3 - *(float*)&v.f18);
        } else if (f3 > *(float*)&v.f20) {
            f30 = k[13];
            result = nw4r::ut::Abs(f3 - *(float*)&v.f20);
        } else {
            float e = nw4r::ut::Abs(f3 - *(float*)&v.f18);
            float g = nw4r::ut::Abs(f3 - *(float*)&v.f20);
            float h;
            if (e < g) {
                h = -e * farg0;
            } else {
                h = g * farg0;
            }
            result = nw4r::ut::Abs(h);
        }
    } else {
        float lo;
        if (farg0 > k[0]) {
            lo = *(float*)&v.f20;
        } else {
            lo = *(float*)&v.f18;
        }
        result = farg0 * (lo - *arg1);
    }

    result -= fn_27_21F1BC((s8*)arg0);
    if (result < k[30]) {
        result = k[30];
    }
    return result * f30;
}
