#pragma force_active on
extern "C" void fn_800415E8(float *, unsigned char *, int, float);
extern "C" int lbl_8059FF8C;
extern "C" float lbl_805A13A0;

struct Obj {
    unsigned char pad0[0x1C];
    unsigned char flags;
    unsigned char pad1[3];
    float f20;
    float f24;
    unsigned char pad2[0x18];
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    unsigned char b43;
    unsigned char pad3[4];
    float f48;
    float f4c;
    float f50;
};

extern "C" {
void fn_80011758(Obj *arg0) {
    unsigned char spb[4];
    int sp8;
    float vec[3];

    vec[0] = arg0->f48 + arg0->f20;
    vec[1] = arg0->f4c + arg0->f24;
    vec[2] = arg0->f50;
    if ((arg0->flags >> 7) & 1) {
        spb[0] = arg0->b40;
        spb[1] = arg0->b41;
        spb[2] = arg0->b42;
        spb[3] = arg0->b43;
        fn_800415E8(vec, spb, 1, lbl_805A13A0);
        return;
    }
    sp8 = lbl_8059FF8C;
    fn_800415E8(vec, (unsigned char *)&sp8, 0, lbl_805A13A0);
}
}
