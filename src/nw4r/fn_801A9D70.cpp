#pragma force_active on
extern "C" {
extern float lbl_805A33B8;
extern float lbl_805A33BC;

typedef void (*func_ptr)(void*, int);
extern func_ptr lbl_8040AB10[];
extern func_ptr lbl_8040AB2C[];

int fn_801A9D70(void* arg0, int arg1, int arg2, unsigned arg3) {
    unsigned idx = (arg3 >> 1) & 7;
    if (idx == 7) return 0;
    if (arg1 != 0) {
        lbl_8040AB10[idx](arg0, arg2);
    } else {
        lbl_8040AB2C[idx](arg0, arg2);
    }
    float b, a;
    a = lbl_805A33B8;
    b = lbl_805A33BC;
    float* p = (float*)((char*)arg0 + 0x20);
    p[0] = a;
    p[1] = a;
    p[2] = b;
    p[3] = a;
    return 1;
}
}
