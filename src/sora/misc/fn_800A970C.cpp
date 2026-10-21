#pragma force_active on
struct Src {
    float v0;
    float v4;
    float v8;
    float vC;
    float v10;
    float v14;
    int v18;
    float v1C;
    float v20;
    float v24;
};

struct Dst {
    unsigned char pad[0x28];
    float v28;
    float v2C;
    float v30;
    float v34;
    float v38;
    float v3C;
    int v40;
    float v44;
    float v48;
    float v4C;
};

extern "C" {
void fn_800A970C(Dst* dst, const Src* src) {
    dst->v28 = src->v0;
    dst->v2C = src->v4;
    dst->v30 = src->v8;
    dst->v34 = src->vC;
    dst->v38 = src->v10;
    dst->v3C = src->v14;
    dst->v40 = src->v18;
    dst->v44 = src->v1C;
    dst->v48 = src->v20;
    dst->v4C = src->v24;
}
}
