#pragma force_active on

extern "C" {
extern const float lbl_805A1CA8;
extern const float lbl_805A1CAC;
extern void* lbl_8049DEC8[3];
extern void* lbl_805A0268;
void fn_8009B8A0(void*);
void fn_80080B40(void*, int, void*);
void fn_801EC158(void*);
}

struct V3 {
    float v[3];
};

struct Obj {
    int u0; int u4; int u8;
    unsigned char uC, uD, uE, uF, u10, u11;
    float u14; float u18; int u1C;
    unsigned char u20;
    int u24; int u28; int u2C; int u30; int u34; int u38;
    float u3C;
    unsigned char u40, u41, u42, u43;
    V3 u44;
    float u50;
    unsigned char u54, u55, u56, u57, u58, u59, u5A, u5B, u5C, u5D, u5E;
    float u60;
    unsigned char u64, u65;
    char pad66[0xC8 - 0x66];
    unsigned char uC8, uC9, uCA;
    int uCC; int uD0; int uD4; int uD8; int uDC; int uE0; int uE4;
    unsigned char uE8, uE9;
    int padEC;
    float uF0;
};

extern "C" Obj* fn_8008AE90(Obj* self, int a1, int a2, int a3) {
    char tmp[4];
    V3 v;
    v.v[0] = lbl_805A1CA8;
    v.v[1] = lbl_805A1CA8;
    v.v[2] = lbl_805A1CA8;
    self->u0 = 0; self->u4 = 0; self->u8 = 0x80000000;
    self->uC = 0; self->uD = 0; self->uE = 0; self->uF = 0; self->u10 = 0; self->u11 = 0;
    self->u14 = lbl_805A1CA8; self->u18 = lbl_805A1CAC;
    self->u1C = 0; self->u20 = 0;
    self->u24 = -1; self->u28 = a3; self->u2C = -1;
    self->u30 = 0; self->u34 = 0; self->u38 = a2;
    self->u3C = lbl_805A1CAC;
    self->u40 = 0; self->u41 = 0; self->u42 = 0; self->u43 = 0;
    self->u44 = v;
    self->u50 = lbl_805A1CA8;
    self->u54 = 0; self->u55 = 0; self->u56 = 0; self->u57 = 0; self->u58 = 0; self->u59 = 0;
    self->u5A = 0; self->u5B = 0; self->u5C = 0; self->u5D = 0; self->u5E = 0;
    self->u60 = lbl_805A1CA8;
    self->u64 = 0; self->u65 = 0;
    self->uC8 = 0; self->uC9 = 0; self->uCA = 0;
    self->uCC = 0; self->uD0 = 0; self->uD4 = 0x80000000;
    self->uD8 = 0; self->uDC = 0; self->uE0 = 0x80000000;
    self->uE4 = 0; self->uE8 = 0; self->uE9 = 0;
    self->uF0 = lbl_805A1CAC;
    fn_8009B8A0(lbl_8049DEC8[0]);
    fn_80080B40(tmp, a1, self);
    if (lbl_805A0268 == 0) {
        lbl_805A0268 = self;
    }
    fn_801EC158((char*)self + 0x68);
    fn_801EC158((char*)self + 0x98);
    return self;
}
