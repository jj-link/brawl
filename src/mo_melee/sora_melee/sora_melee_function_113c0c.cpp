#include <types.h>
#pragma force_active on

struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };
struct Inner {
    char pad0[8];
    u32 top : 3;
    u32 mode : 3;
    u32 type : 3;
    u32 sub : 3;
    u32 flag : 1;
    u32 rest : 19;
    char padC[0x10];
    Vec3 pos;
    float value;
    Vec4 a;
    Vec4 b;
    char pad4C[0x14];
    Vec3 zero;
};
struct Self {
    char pad0[0x28];
    void* work;
    char pad2C[0x2c];
    u32 type;
    char pad5C[0x134];
    Inner* inner;
    s32 result;
};
extern "C" {
s32 fn_27_1125B0(void*);
void fn_8009EEDC(Inner*);
void fn_8009EF8C(Inner*, const Vec3*);
void fn_8009EFA8(Inner*, const Vec4*);
void fn_8009EFCC(Inner*);
}
extern float lbl_27_rodata_FB8;

extern "C" void fn_27_113C0C(Self* self, Vec4* arg1, Vec3* arg2, s32 arg3, float farg0) {
    if (self->inner != 0) {
        fn_8009EEDC(self->inner);
        self->inner->mode = 3;
        if (fn_27_1125B0(self->work) == 0)
            self->inner->type = 5;
        else
            self->inner->type = 4;
        self->inner->sub = self->type;
        fn_8009EFA8(self->inner, arg1);
        {
            Inner* p = self->inner;
            float w, z, y, x;
            x = arg1->x;
            y = arg1->y;
            p->b.x = x;
            z = arg1->z;
            p->b.y = y;
            w = arg1->w;
            p->b.z = z;
            p->b.w = w;
        }
        self->inner->value = farg0;
        fn_8009EF8C(self->inner, arg2);
        Inner* p = self->inner;
        float value, z, y, x;
        x = arg2->x;
        y = arg2->y;
        p->pos.x = x;
        z = arg2->z;
        p->pos.y = y;
        value = lbl_27_rodata_FB8;
        p->pos.z = z;
        Vec3 zero = {value, value, value};
        self->inner->zero = zero;
        self->inner->flag = 0;
        self->inner->top = 0;
        fn_8009EFCC(self->inner);
        self->result = arg3;
    }
}
