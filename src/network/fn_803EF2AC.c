#pragma force_active on
extern int __ptmf_test(void *);
extern int lbl_804937B8[];
extern float lbl_805A4B04;

struct Obj {
    int m00;
    char pad04[0x14];
    float m18;
    float m1C;
    char pad20[0x0C];
    float m2C;
    float m30;
    char pad34[4];
    char m38;
    char m39;
    char m3A;
    char pad3B[5];
    int m40;
    int m44;
    char pad48[4];
    int m4C;
    char pad50[0x14];
    int m64;
    char pad68[4];
    int m6C;
    char pad70[4];
    int m74;
    int m78;
    int m7C;
    void *m80;
    short arr[35];
};

void fn_803EF2AC(struct Obj *p, short *input) {
    int i;
    if (p->m00 == 0) return;
    for (i = 0; i < 32; i++) {
        short val = input[i];
        p->arr[i] = val;
        if (val == 0xD3) {
            p->arr[i] = 0xCB;
            p->arr[i+1] = 0xCB;
            p->arr[i+2] = 0xCB;
            p->arr[i+3] = 0xD3;
            goto init;
        }
        if (i == 31) return;
    }
init:
    if (__ptmf_test(lbl_804937B8) != 0) {
        p->m3A = 0;
    }
    {
        float z = lbl_805A4B04;
        p->m80 = &p->arr[0];
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