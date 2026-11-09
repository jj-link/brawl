#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual f32 slot12(u32 id);
    virtual void slot13(u32 id, f32 v);
    virtual void slot14();
    virtual void slot15(f32* v, int n);
    virtual int slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
};

class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(u32 cmd);
};

struct Vec2 {
    f32 x;
    f32 y;
};

extern "C" {
extern void* g_cmAIController;
extern const f32 lbl_27_rodata_46C8[];
f32 rsqrtf__Ff(f32 x);
}

extern "C" void fn_27_29E0D8(void* unused, u8* p) {
    const f32* k = lbl_27_rodata_46C8;
    soNullable* s = *(soNullable**)(*(u8**)(p + 0x1a4) + 0x70);
    if (s->slot16() == 6) {
        Target* t = *(Target**)(*(u8**)(*(u8**)(p + 0x60) + 0xd8) + 0x64);
        u8* ai = (u8*)g_cmAIController;
        if (ai != 0) {
            Vec2 v = *(Vec2*)(ai + 0xb0);
            f32 sum = v.x * v.x + v.y * v.y;
            f32 mag;
            if ((f32)(double)nw4r::math::FAbs(sum) <= k[6]) {
                mag = k[5];
            } else {
                mag = sum * rsqrtf__Ff(sum);
            }
            if (mag < k[0]) {
                t->slot18(0x12000000);
                v.x = v.x * k[5];
                v.y = v.y * k[5];
            } else {
                v.x = v.x * k[45];
                v.y = v.y * k[45];
            }
            *(Vec2*)(ai + 0xb0) = v;
        }
    }
}
