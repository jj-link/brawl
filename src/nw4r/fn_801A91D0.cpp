#pragma force_active on
typedef void (*FnPtr)(void*, int);
extern FnPtr lbl_8040AAD8[];
extern FnPtr lbl_8040AAF4[];
extern float lbl_805A33A0;
extern float lbl_805A33A4;

struct Fn91D0Obj {
    char pad[0x20];
    float f20;
    float f24;
    float f28;
    float f2c;
};

extern "C" {
int fn_801A91D0(struct Fn91D0Obj* arg0, int arg1, int arg2, unsigned int arg3) {
    unsigned int idx = (arg3 >> 1) & 7;
    float w;
    float z;
    int ret;
    if (idx == 7) {
        return 0;
    }
    if (arg1 != 0) {
        lbl_8040AAD8[idx](arg0, arg2);
    } else {
        lbl_8040AAF4[idx](arg0, arg2);
    }
    z = lbl_805A33A0;
    ret = 1;
    w = lbl_805A33A4;
    arg0->f20 = z;
    arg0->f24 = z;
    arg0->f28 = w;
    arg0->f2c = z;
    return ret;
}
}
