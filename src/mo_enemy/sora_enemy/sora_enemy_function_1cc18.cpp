#include <mt/mt_vector.h>
#pragma force_active on

class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
};
class Class_740 {
public:
    virtual void fn_41_BDA0();
    virtual void fn_41_BE5C();
};
class soNullable {
public:
    virtual void isNull();
    virtual int* slot1(unsigned int);
};
class Class_5F58 {
public:
    virtual void fn_41_33C34();
    virtual void fn_41_33E48();
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
};

struct EnemyData {
    unsigned char pad0[5];
    unsigned char flag : 1;
    unsigned char otherFlags : 7;
    unsigned char pad6[0x42];
    unsigned char f48;
    float f4C, f50, f54, f58, f5C, f60;
    unsigned char f64;
    float f68, f6C;
    int f70, f74;
    float f78, f7C;
    int f80;
    float f84, f88;
    int f8C, f90;
    Vec3f f94, fA0;
    float fAC;
    unsigned char fB0;
    Vec2f fB4;
    Vec3f fBC;
    soNullable* fC8;
};

extern "C" {
    void fn_41_1CBCC(void*);
    Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
    void fn_41_534C(Vec3f*, const Vec3f*);
    void fn_41_1BEA8(Vec2f*, const Vec2f*);
    extern float lbl_41_rodata_C9C;
    extern float lbl_41_rodata_CAC;
}

inline void resetEntry(int* entry) { *entry = -1; }

extern "C" void fn_41_1CC18(EnemyData* self) {
    Vec3f t1, t2, t3;
    fn_41_1CBCC((char*)self + 8);
    self->f48 = 0;
    float zero = lbl_41_rodata_C9C;
    self->f4C = zero;
    self->f50 = zero;
    self->f54 = zero;
    self->f58 = zero;
    float value = lbl_41_rodata_CAC;
    self->f5C = value;
    self->f60 = value;
    self->f64 = 0;
    self->f68 = zero;
    self->f6C = zero;
    self->f70 = 0;
    self->f74 = -1;
    self->f78 = zero;
    self->f7C = zero;
    self->f80 = 0;
    self->f84 = value;
    self->f88 = value;
    self->f8C = -1;
    self->f90 = 0;
    fn_41_534C(&self->f94, fn_41_5AC4(&t1, zero, zero, zero));
    fn_41_534C(&self->fA0, fn_41_5AC4(&t2, lbl_41_rodata_C9C, lbl_41_rodata_C9C, lbl_41_rodata_C9C));
    float zero2 = lbl_41_rodata_C9C;
    self->fAC = zero2;
    self->fB0 = 0;
    Vec2f v(zero2, zero2);
    fn_41_1BEA8(&self->fB4, &v);
    fn_41_534C(&self->fBC, fn_41_5AC4(&t3, lbl_41_rodata_C9C, lbl_41_rodata_C9C, lbl_41_rodata_C9C));
    self->flag = 0;
    for (unsigned int i = 0; i < 2; ++i)
        resetEntry(self->fC8->slot1(i));
}
