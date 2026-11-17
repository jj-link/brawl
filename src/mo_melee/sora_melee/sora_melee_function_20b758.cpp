#pragma force_active on
extern "C" {
void* fn_27_1F1F58(void*);
void fn_27_20B9E0(void*, float*, void*, float);
float fn_27_21F1BC(void*);
extern const float lbl_27_rodata_2F68[];
}

struct Vec3f {
    float x, y, z;
};

extern "C" float fn_27_20B758(void* arg0, void* arg1, float farg0) {
    const float* k = lbl_27_rodata_2F68;
    char* self = (char*)arg0;
    char* tgt = (char*)fn_27_1F1F58(arg1);
    float v;
    Vec3f sp8;
    float f31;
    float f1;
    if (farg0 <= k[30]) {
        v = *(float*)(self + 0xA0) * (*(float*)(tgt + 0x5C) - *(float*)(self + 0x5C));
    } else {
        fn_27_20B9E0(arg0, (float*)&sp8, arg1, farg0);
        v = sp8.x * *(float*)(self + 0xA0);
    }
    if (v >= k[0]) {
        if (*(int*)(self + 0x4C) != 0) {
            f31 = fn_27_21F1BC(arg1);
            f1 = fn_27_21F1BC(arg0);
            v -= f1 + f31;
        }
        if (v < k[31]) {
            v = k[31];
        }
    } else {
        if (*(int*)(self + 0x4C) != 0) {
            f31 = fn_27_21F1BC(arg1);
            f1 = fn_27_21F1BC(arg0);
            v += f1 + f31;
        }
        if (v > k[32]) {
            v = k[32];
        }
    }
    return v;
}