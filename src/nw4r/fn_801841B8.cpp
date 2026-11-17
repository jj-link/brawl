#pragma force_active on
extern "C" const float lbl_805A30D0;
extern "C" const float lbl_805A30D4;

struct Src {
    char pad[0x18];
    float x;
    float y;
    unsigned char flag;
};

struct Dst {
    float a, b, c, d;
    void set(float l, float t, float r, float b2) {
        a = l;
        b = t;
        c = r;
        d = b2;
    }
};

extern "C" void fn_801841B8(Dst* dst, Src* src) {
    if (src->flag == 1) {
        dst->set(-src->x * lbl_805A30D4, src->y * lbl_805A30D4, src->x * lbl_805A30D4, -src->y * lbl_805A30D4);
        return;
    }
    float z = lbl_805A30D0;
    float x;
    float y;
    y = src->y;
    x = src->x;
    dst->a = z;
    dst->b = z;
    dst->c = x;
    dst->d = y;
}
