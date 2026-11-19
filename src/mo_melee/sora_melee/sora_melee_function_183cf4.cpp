#include <types.h>
#include <mt/mt_vector.h>
#include <so/so_value_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

struct Vec2 {
    float x;
    float y;
};

class VtA {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void m5(Vec3f*);
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual float m22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
};

struct Pad8 {
    int a;
    int b;
};

class VtC : public Pad8 {
public:
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
    virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
    virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11();
    virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
    virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
    virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23();
    virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27();
    virtual void g28(); virtual void g29(); virtual void g30(); virtual void g31();
    virtual void g32(); virtual void g33(); virtual void g34(); virtual void g35();
    virtual void g36(); virtual void g37(); virtual void g38(); virtual void g39();
    virtual void g40(); virtual void g41(); virtual void g42(); virtual void g43();
    virtual void g44(); virtual void g45(); virtual void g46(); virtual void g47();
    virtual void g48(); virtual void g49(); virtual void g50(); virtual void g51();
    virtual void g52(); virtual void g53(); virtual void g54(); virtual void g55();
    virtual void g56(); virtual void g57(); virtual void g58(); virtual void g59();
    virtual void g60(); virtual void g61(); virtual void g62(); virtual void g63();
    virtual void g64(); virtual void g65(); virtual void g66(); virtual void g67();
    virtual void g68(); virtual void g69(); virtual void g70(); virtual void g71();
    virtual void g72(); virtual void g73(); virtual void g74(); virtual void g75();
    virtual void g76(); virtual void g77(); virtual void g78(); virtual void g79();
    virtual void g80(); virtual void g81(); virtual void g82(); virtual void g83();
    virtual void g84(); virtual void g85(); virtual void g86(); virtual void g87();
    virtual void g88(); virtual void g89(); virtual void g90(); virtual void g91();
    virtual void g92(); virtual void g93(); virtual void g94(); virtual void g95();
    virtual void g96(); virtual void g97(); virtual void g98(); virtual void g99();
    virtual void g100(); virtual void g101(); virtual void g102(); virtual void g103();
    virtual void g104(); virtual void g105(); virtual void g106(); virtual void g107();
    virtual void g108(); virtual void g109(); virtual void g110();
    virtual float m111();
};

class VtD {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
    virtual void d32();
    virtual float m33(int);
    virtual void d34();
    virtual void d35();
    virtual Vec3f m36(int, int, int);
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual float m40(int);
};

class VtE {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual int m4(int);
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual float m12(int);
    virtual void m13(int, float);
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual int m17(int);
    virtual void m18(int, void*);
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void e36();
    virtual void e37();
    virtual void e38();
    virtual void e39();
    virtual void e40();
};

struct Data {
    char pad0[0xc];
    VtA* atC;
    VtC* at10;
    char pad1[0x40];
    VtD* at54;
    char pad2[0xc];
    VtE* at64;
};

struct Accesser {
    char pad[0xd8];
    Data* d8;
};

extern "C" {
extern const float lbl_27_rodata_2470[];
}

static inline float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void* acc, unsigned long id, unsigned long idx)
{
    return soValueAccesser::getConstantFloat((soModuleAccesser*)acc, id, idx);
}

static inline Vec2f getParentOffset(Accesser* acc) {
    Vec2f offset;
    if (acc->d8->at64->m4(0x20000001) == 5) {
        offset.m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd35, 0);
        offset.m_y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd36, 0);
    } else if (acc->d8->at64->m4(0x20000001) == 0x20) {
        offset.m_x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd4c, 0);
        offset.m_y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd4d, 0);
    }
    return offset;
}

extern "C" void fn_27_183CF4(void* self, Accesser* acc) {
    const float heights[2] = {3.4f, 8.4f};
    float shortHeight = 3.4f;
    float tallHeight = 8.4f;
    float lenSq;
    Vec2 lim;
    float f30;

    if (acc->d8->at64->m4(0x20000001) == 0x20 ||
        acc->d8->at64->m17(0x22000013) != 0) {
        lim.x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd4e, 0);
        lim.y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd4f, 0);
        f30 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd50, 0);
    } else if (acc->d8->at64->m4(0x20000001) == 5) {
        lim.x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd37, 0);
        lim.y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd38, 0);
        f30 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd39, 0);
    }

    Vec2 vel;
    vel.x = acc->d8->at64->m12(0x21000007);
    vel.y = acc->d8->at64->m12(0x21000008);
    lenSq = vel.x * vel.x + vel.y * vel.y;

    float len;
    if ((float)(double)nw4r::math::FAbs(lenSq) <= 1.1754943508222875e-38f) {
        len = 0.0f;
    } else {
        len = lenSq * rsqrtf(lenSq);
    }

    int r30 = 0;
    if (len <= f30) {
        r30 = 1;
    } else {
        int r29 = 1;
        int r28 = 1;
        Vec2 step = vel;

        if (nw4r::ut::Abs(step.x) > lim.x) {
            int s = (vel.x < 0.0f) ? -1 : 1;
            r29 = 0;
            step.x = lim.x * (float)s;
        }

        if (nw4r::ut::Abs(step.y) > lim.y) {
            int s = (vel.y < 0.0f) ? -1 : 1;
            r28 = 0;
            step.y = lim.y * (float)s;
        }

        vel.x = vel.x - step.x;
        vel.y = vel.y - step.y;
        acc->d8->at64->m13(0x21000007, vel.x);
        acc->d8->at64->m13(0x21000008, vel.y);

        Vec3f p = acc->d8->at54->m36(0, 0, 1);

        Vec2f scaled;
        Vec2f::copy(scaled, getParentOffset(acc));
        float k33 = acc->d8->at54->m33(0);
        p.m_x += (scaled.m_x * k33) * acc->d8->at54->m40(0);
        p.m_y += scaled.m_y * k33;
        float r31 = acc->d8->atC->m22();

        Vec3f q;
        q.m_x = p.m_x + vel.x;
        float v = (acc->d8->at64->m4(0x20000001) == 5) ? 3.4f : 8.4f;
        q.m_y = (p.m_y + vel.y) - r31 * v;
        q.m_z = acc->d8->at10->m111();
        acc->d8->atC->m5(&q);

        if (r29 != 0 && r28 != 0) {
            r30 = 1;
        }
    }

    if (r30 != 0) {
        acc->d8->at64->m18(0x22000012, acc->d8);
    }
}
