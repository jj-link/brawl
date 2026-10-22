#pragma force_active on
typedef unsigned char u8;

extern int __ptmf_test(void *);
extern int lbl_804937C4[];
extern float lbl_805A4B04;

struct Obj {
    int m00;
    u8 pad04[0x14];
    float m18;
    float m1C;
    u8 pad20[0x0C];
    float m2C;
    float m30;
    u8 pad34[4];
    u8 m38;
    u8 m39;
    u8 m3A;
    u8 pad3B[5];
    int m40;
    int m44;
    u8 pad48[4];
    int m4C;
    u8 pad50[0x14];
    int m64;
    u8 pad68[4];
    int m6C;
    u8 pad70[4];
    int m74;
    int m78;
    int m7C;
    int m80;
};

void fn_803EF3CC(struct Obj *p, int arg1) {
    float z;
    if (p->m00 != 0) {
        if (__ptmf_test(lbl_804937C4) != 0) {
            p->m3A = 0;
        }
        z = lbl_805A4B04;
        p->m80 = arg1 + 8;
        p->m39 = 1;
        p->m4C = 0;
        p->m40 = 3;
        p->m44 = 0;
        p->m74 = 0;
        p->m78 = 0;
        p->m7C = 0;
        p->m6C = 0;
        p->m18 = z;
        p->m2C = z;
        p->m64 = 0;
        p->m1C = z;
        p->m30 = z;
        p->m38 = 0;
    }
}
