#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;

extern "C" {
float fn_801622A0(float);
void fn_801628B4(MTX34*, MTX34*, VEC3*, float);
void fn_801629AC(MTX34*, float, float, float);
void fn_80166B8C(void*, MTX34*);
void fn_80166CE8(void*);
void fn_8016F564(MTX34*, float*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
void fn_801EC41C(const MTX34*, MTX34*);
void fn_801EC8DC(MTX34*, MTX34*, float, float, float);
extern const float lbl_805A2C88;
extern const float lbl_805A2C94;
extern const float lbl_805A2CA0;
}

struct Holder {
    char pad00[0x20];
    char* p20;
};

struct Obj {
    char pad00[0x0C];
    int state;
    char pad10[0x14];
    unsigned int flags;
    char pad28[0x74];
    float sx;
    float sy;
    float sz;
    float rot[3];
    char padB4[0x08];
    Holder* holder;
    char padC0[0x44];
    unsigned char f104;
};

extern "C" void fn_8016675C(Obj* self) {
    if (self->state != 1 && self->state != 2) {
        return;
    }
    if ((self->flags & 0x10000) || (self->flags & 0x8000)) {
        self->f104 = 1;
        self->rot[2] = lbl_805A2C88;
        self->rot[1] = lbl_805A2C88;
        self->rot[0] = lbl_805A2C88;

        MTX34 mA8;
        MTX34 m78;
        MTX34 m48;
        MTX34 m18;
        VEC3 v8;

        fn_80166B8C(self, &mA8);
        fn_801EC1B8((const MTX34*)(self->holder->p20 + 0x502C), &mA8, &m78);
        m48 = m78;

        float lsq0 = m48[2][0] * m48[2][0] + (m48[0][0] * m48[0][0] + m48[1][0] * m48[1][0]);
        float len0;
        if (lsq0 <= lbl_805A2C88) {
            len0 = lbl_805A2C88;
        } else {
            len0 = lsq0 * fn_801622A0(lsq0);
        }
        m48[0][0] = len0;
        m48[2][0] = lbl_805A2C88;
        m48[1][0] = lbl_805A2C88;

        float lsq1 = m48[2][1] * m48[2][1] + (m48[0][1] * m48[0][1] + m48[1][1] * m48[1][1]);
        float len1;
        if (lsq1 <= lbl_805A2C88) {
            len1 = lbl_805A2C88;
        } else {
            len1 = lsq1 * fn_801622A0(lsq1);
        }
        m48[1][1] = len1;
        m48[2][1] = lbl_805A2C88;
        m48[0][1] = lbl_805A2C88;

        float lsq2 = m48[2][2] * m48[2][2] + (m48[0][2] * m48[0][2] + m48[1][2] * m48[1][2]);
        float len2;
        if (lsq2 <= lbl_805A2C88) {
            len2 = lbl_805A2C88;
        } else {
            len2 = lsq2 * fn_801622A0(lsq2);
        }
        m48[2][2] = len2;
        m48[1][2] = lbl_805A2C88;
        m48[0][2] = lbl_805A2C88;

        if (self->flags & 0x8000) {
            fn_801629AC(&m18, lbl_805A2CA0, lbl_805A2C88, lbl_805A2C88);
            fn_801EC1B8(&m48, &m18, &m48);
        }
        fn_801EC41C(&m78, &m78);
        fn_801EC1B8(&m78, &m48, &m78);
        v8.x = lbl_805A2C94 / self->sx;
        v8.y = lbl_805A2C94 / self->sy;
        v8.z = lbl_805A2C94 / self->sz;
        fn_801628B4(&m78, &m78, &v8, lbl_805A2C94);
        fn_801EC8DC(&m78, &m78, self->sx, self->sy, self->sz);
        fn_8016F564(&m78, self->rot);
        fn_80166CE8(self);
    }
}
