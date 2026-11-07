#include <types.h>
#pragma force_active on
#pragma fp_contract on

extern "C" {

extern float lbl_805A4068;

struct Vec4 {
    float x, y, z, w;
};

struct Seg {
    char pad[0x10];
    Vec4 a;
    Vec4 b;
};

struct Out {
    float x, y, z;
    union {
        float w;
        int id;
    };
};

void fn_802CEC68(Seg* s, Vec4* dir, Out* out) {
    __declspec(align(16)) Vec4 d;
    d.x = s->b.x - s->a.x;
    d.y = s->b.y - s->a.y;
    d.z = s->b.z - s->a.z;
    d.w = s->b.w - s->a.w;
    float dot = d.x * dir->x + d.y * dir->y + d.z * dir->z;
    int id;
    if (dot < lbl_805A4068) {
        out->x = s->a.x;
        id = 0;
        out->y = s->a.y;
        out->z = s->a.z;
        out->w = s->a.w;
    } else {
        out->x = s->b.x;
        id = 0x10;
        out->y = s->b.y;
        out->z = s->b.z;
        out->w = s->b.w;
    }
    out->id = id;
}

}
