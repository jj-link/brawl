#pragma force_active on
extern float lbl_805A3640;
extern float lbl_805A3644;

struct FnObj {
    char pad[0xb1];
    unsigned char flags;
    char pad2[0xec - 0xb2];
    float vals[1];
};

extern "C" void fn_801D1594(FnObj* obj, int idx, float f1) {
    float hi = lbl_805A3640;
    float t = f1 + hi;
    float r;
    if (t > hi) {
        r = hi;
    } else if (t < lbl_805A3644) {
        r = lbl_805A3644;
    } else {
        r = t;
    }
    if (r == obj->vals[idx]) {
        return;
    }
    obj->vals[idx] = r;
    obj->flags |= 0x10;
}
