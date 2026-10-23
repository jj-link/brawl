#pragma force_active on

struct Vec4 {
    float x, y, z, w;
};

struct Dst {
    int v0;
    void* v4;
    int v8;
    float vC;
    unsigned char v10;
    unsigned char pad11[3];
    float v14, v18;
    int v1C;
    Vec4 v20;
    unsigned char pad30[0x18];
    float v48;
    int v4C, v50;
    float v54, v58;
};

extern Vec4 lbl_80407A30;
extern int lbl_80455048[4];
extern const float lbl_805A2170;
extern const float lbl_805A2174;
extern const float lbl_805A2178;
extern const float lbl_805A217C;

extern "C" void fn_800AA9F8(Dst* p) {
    p->v0 = 0;
    p->v4 = &lbl_80455048;
    p->v8 = 0;
    p->vC = lbl_805A2170;

    Vec4 v = lbl_80407A30;
    p->v20.x = v.x;
    p->v20.y = v.y;
    p->v20.z = v.z;
    p->v20.w = v.w;

    p->v14 = lbl_805A2170;
    p->v18 = lbl_805A2170;
    p->v4C = -1;
    p->v50 = -1;
    p->v54 = lbl_805A2174;
    p->v58 = lbl_805A2178;
    p->v48 = lbl_805A217C;
    p->v10 = 0;
}
