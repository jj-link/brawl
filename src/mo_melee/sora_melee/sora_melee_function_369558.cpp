#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on

class WorkMod {
public:
    virtual ~WorkMod() {}
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int m6(unsigned long);
    virtual void m7(int, unsigned long);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual float m14(unsigned long);
    virtual void m15(unsigned long, float);
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void m20(unsigned long);
};

class Unk50Mod {
public:
    virtual ~Unk50Mod() {}
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int m10(int, int, int);
    virtual void m11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void m16(int, int, float);
};

class Unk5CMod {
public:
    virtual ~Unk5CMod() {}
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual float m20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void m57(int, int, int, int);
};

struct ObjectBase { char pad[8]; };
class ObjectMod : public ObjectBase {
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
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29(int, float*);
};

struct Modules {
    char pad0[4];
    ObjectMod* unk4;
    char pad1[0x48];
    Unk50Mod* unk50;
    char pad2[8];
    Unk5CMod* unk5C;
    char pad3[4];
    WorkMod* unk64;
};

struct Accesser {
    char pad[0xd8];
    Modules* mods;
};

extern "C" {
float fn_27_192278(void*, unsigned long);
int fn_27_1922CC(void*, unsigned long);
extern const float lbl_27_rodata_7B38;
extern const float lbl_27_rodata_7B3C;
}

inline float clampValue(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_27_369558(void* unused, Accesser* a) {
    int st = a->mods->unk64->m6(0x20000002);
    if (st != a->mods->unk64->m6(0x20000003)) {
        a->mods->unk64->m7(st, 0x20000003);
        if (st == 2) {
            a->mods->unk50->m11();
        }
    }
    switch (st) {
    case 1: {
        float lo = fn_27_192278(a, 0xFA9);
        float ratio = fn_27_192278(a, 0xFA8);
        ratio = (a->mods->unk64->m14(0x11000016) - lo) / (ratio - lo);
        int cnt = a->mods->unk64->m6(0x20000000);
        if (cnt >= 3 && a->mods->unk64->m6(0x20000007) == -1) {
            a->mods->unk64->m7(a->mods->unk50->m10(a->mods->unk64->m6(0x20000006), 0, 0), 0x20000007);
        } else if (cnt >= 0xB && a->mods->unk64->m6(0x20000009) == -1) {
            a->mods->unk64->m7(a->mods->unk50->m10(a->mods->unk64->m6(0x20000008), 0, 0), 0x20000009);
        }
        int idx = a->mods->unk64->m6(0x20000004);
        if (idx == 0) {
            a->mods->unk64->m20(0x22000013);
            int r28 = a->mods->unk64->m6(0x20000009);
            if (r28 != -1) {
                float v = ratio;
                float t = fn_27_192278(a, 0xFB0);
                if (ratio < t) {
                    v = t;
                }
                a->mods->unk50->m16(r28, 0, v);
            }
            Unk5CMod* o = a->mods->unk5C;
            int sel;
            int* selPtr = &sel;
            if (ratio > lbl_27_rodata_7B38) {
                *selPtr = 0;
            } else {
                *selPtr = 1;
            }
            o->m57(sel, 0, 1, -1);        }
        int nxt = idx + 1;
        if (nxt >= fn_27_1922CC(a, 0x5DC2)) {
            nxt = 0;
        }
        a->mods->unk64->m7(nxt, 0x20000004);
        a->mods->unk64->m7(cnt + 1, 0x20000000);
        float f28 = a->mods->unk64->m14(0x21000004);
        float val = a->mods->unk5C->m20();
        if ((float)(double)nw4r::math::FAbs(val) > lbl_27_rodata_7B38) {
            float f30 = fn_27_192278(a, 0xFA2);
            float f31 = fn_27_192278(a, 0xFA3);
            float scale = fn_27_192278(a, 0xFA4);
            f28 += scale * val;
            f28 = clampValue(f28, -f31, f30);
            a->mods->unk64->m15(0x21000004, f28);
        }
        int r28b = a->mods->unk64->m6(0x2000000A);
        if (r28b != 0) {
            float fa5 = fn_27_192278(a, 0xFA5);
            float prod = -f28 * fa5;
            float v[3];
            v[0] = prod;
            v[1] = lbl_27_rodata_7B3C;
            v[2] = lbl_27_rodata_7B3C;
            a->mods->unk4->slot29(r28b, v);
        }
        break;
    }
    }
}
