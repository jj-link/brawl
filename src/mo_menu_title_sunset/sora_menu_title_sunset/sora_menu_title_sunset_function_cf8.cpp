#pragma force_active on
extern "C" const float lbl_25_rodata_20;
extern "C" const float lbl_25_rodata_24;
extern "C" char lbl_25_data_278[];

struct Entry {
    float v[4];
    char* ptr;
};

struct Dst {
    unsigned char a;
    unsigned char b;
    unsigned short pad;
    float f4;
    float f8;
    float v1[4];
    int p1;
    float v2[4];
    int p2;
    float v3[4];
    int p3;
};

extern "C" void fn_25_CF8(Dst* dst, const Entry* src) {
    float zero = lbl_25_rodata_20;
    float val = lbl_25_rodata_24;
    Entry e3, e2, e1;

    dst->a = 1;
    dst->b = 0;
    dst->f4 = val;
    dst->f8 = val;

    e1.ptr = lbl_25_data_278;
    e1.v[0] = zero;
    e1.v[1] = zero;
    e1.v[2] = zero;
    e1.v[3] = zero;

    dst->v1[0] = e1.v[0];
    dst->v1[1] = e1.v[1];
    dst->v1[2] = e1.v[2];
    dst->v1[3] = e1.v[3];

    e2.ptr = lbl_25_data_278;
    e2.v[0] = zero;
    e2.v[1] = zero;
    e2.v[2] = zero;
    e2.v[3] = zero;

    dst->v2[0] = e2.v[0];
    dst->v2[1] = e2.v[1];
    dst->v2[2] = e2.v[2];
    dst->v2[3] = e2.v[3];

    e3.ptr = lbl_25_data_278;
    e3.v[0] = zero;
    e3.v[1] = zero;
    e3.v[2] = zero;
    e3.v[3] = zero;

    dst->v3[0] = e3.v[0];
    dst->v3[1] = e3.v[1];
    dst->v3[2] = e3.v[2];
    dst->v3[3] = e3.v[3];

    dst->v3[0] = src->v[0];
    dst->v3[1] = src->v[1];
    dst->v3[2] = src->v[2];
    dst->v3[3] = src->v[3];
}
