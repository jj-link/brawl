#include <types.h>
#pragma force_active on

extern const float lbl_805A4848;
extern const float lbl_805A4850;

struct Element {
    float f[36];
};

struct Object {
    Element* data;
    int arg;
    unsigned int flags;
    int pad;
    Element elements[3];
};

struct Vec4 {
    float x, y, z, w;
};

extern "C" void fn_8032CC20(Object* obj, int arg) {
    const float zero = lbl_805A4848;
    const float one = lbl_805A4850;
    Element* p = obj->elements;
    obj->data = p;
    obj->arg = arg;
    obj->flags = 0x80000003;
    do {
        p->f[0] = zero;
        p->f[1] = zero;
        p->f[7] = zero;
        p->f[6] = zero;
        p->f[5] = zero;
        p->f[4] = zero;
        p->f[8] = zero;
        p->f[9] = zero;
        p->f[10] = zero;
        p->f[11] = zero;
        p->f[12] = zero;
        p->f[13] = zero;
        p->f[14] = zero;
        p->f[15] = zero;
        p->f[16] = zero;
        p->f[17] = zero;
        p->f[18] = zero;
        p->f[19] = zero;
        p->f[21] = zero;
        p->f[22] = zero;
        p->f[23] = zero;
        p->f[24] = zero;
        p->f[26] = zero;
        p->f[27] = zero;
        p->f[28] = zero;
        p->f[29] = zero;
        p->f[31] = zero;
        p->f[20] = one;
        p->f[25] = one;
        p->f[30] = one;
        p->f[35] = zero;
        p->f[34] = zero;
        p->f[33] = zero;
        p->f[32] = zero;
        ++p;
        __declspec(align(16)) Vec4 b;
        __declspec(align(16)) Vec4 a;
        a.w = zero;
        a.z = zero;
        a.y = zero;
        a.x = zero;
        b.w = zero;
        b.z = zero;
        b.y = zero;
        b.x = zero;
    } while (p < obj->elements + 3);
}
