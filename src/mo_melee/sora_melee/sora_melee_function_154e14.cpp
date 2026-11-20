#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_1547F4();
    virtual void fn_27_154FA8();
    virtual void fn_27_154E14();
};

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

inline float clampValue(float value, float lower, float upper) {
    float t = nw4r::math::FSelect(value - lower, value, lower);
    return nw4r::math::FSelect(t - upper, upper, t);
}

#define SLOTS \
    virtual void slot0(); \
    virtual void slot1(); \
    virtual void slot2(); \
    virtual void slot3(); \
    virtual void slot4(); \
    virtual void slot5(); \
    virtual void slot6(int, int); \
    virtual void slot7(); \
    virtual void slot8(); \
    virtual void slot9(); \
    virtual void slot10(); \
    virtual void slot11(); \
    virtual void slot12(); \
    virtual void slot13(); \
    virtual void slot14(); \
    virtual void slot15(); \
    virtual void slot16(); \
    virtual void slot17(); \
    virtual void slot18(); \
    virtual void slot19(int, int); \
    virtual void slot20(); \
    virtual void slot21(); \
    virtual void slot22(); \
    virtual void slot23(); \
    virtual void slot24(int, Vec3*);

class Object_vptr_0 {
public:
    SLOTS
};

struct Pad8 {
    char pad[8];
};

class Object_vptr_8 : public Pad8 {
public:
    SLOTS
};

struct Out {
    u16 id;
    float value, angle, f2, f3, f4;
    u32 a, b;
};

extern "C" {
extern void* lbl_27_bss_5780;
extern float lbl_27_rodata_1F10[];

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
unsigned int fn_27_22B290(void*, u32, Out*);
void fn_8003DC64(Vec2*, float, Vec2*);

void fn_27_154E14(void*, void* obj, void* arg2, void* arg3) {
    float* constants = lbl_27_rodata_1F10;

    if (lbl_27_bss_5780 == 0) {
        void* m = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (m != 0) {
            m = fn_27_22A914(m);
        }
        lbl_27_bss_5780 = m;
    }

    Out info;
    if (fn_27_22B290(lbl_27_bss_5780, *(u32*)((char*)arg3 + 4), &info) == 1 &&
        info.value > constants[1] &&
        info.a != *(u32*)(*(char**)((char*)obj + 8) + 0x28)) {
        (*(Object_vptr_0**)(*(char**)((char*)obj + 0xd8) + 0x14))->slot6(2, 0);
        (*(Object_vptr_8**)(*(char**)((char*)obj + 0xd8) + 0x10))->slot19(5, 0);

        float angle = info.angle;
        if (*(u16*)((char*)arg2 + 2) == 15) {
            float v = constants[2] * *(float*)((char*)arg3 + 0x10);
            angle += clampValue(v, constants[4], constants[3]);
        }

        Vec2 out;
        Vec2 in = { info.value, constants[1] };
        fn_8003DC64(&in, constants[5] * angle, &out);

        Vec3 result;
        float y = out.y;
        result.x = out.x;
        result.y = y;
        result.z = constants[1];
        (*(Object_vptr_0**)(*(char**)((char*)obj + 0xd8) + 0x7c))->slot24(2, &result);
    }
}
}
