#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

typedef unsigned long long u64;

struct Vec2 { float x, y; };
inline Vec2 unpack(u64 bits) { return *(Vec2*)&bits; }

struct Pad8 { char pad[8]; };

// slot k lives at vtable offset 0x8 + 4k (vptr at offset 0)
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual u64 slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(unsigned int);
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13(float, unsigned int);
    virtual unsigned int slot14(unsigned int, bool);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17(unsigned int, int, bool);
    virtual void slot18(unsigned int, int);
    virtual void slot19();
    virtual void slot20(unsigned int, float);
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual float slot26(unsigned int, bool);
};

// vptr at offset 0x8
class Object_vptr_8 : public Pad8 {
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
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float rsqrtf__Ff(float);
double atan2(double, double);
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_2198[];

void fn_27_16D248(void*, soModuleAccesser* self) {
    const float* c = lbl_27_rodata_2198;
    if (((Object_vptr_0*)self->m_enumerationStart->m_collisionAttackModule)->slot14(0, false) == 1) {
        if (((Object_vptr_0*)self->m_enumerationStart->m_workManageModule)->slot12(0x21000007) == c[3]) {
            ((Object_vptr_0*)self->m_enumerationStart->m_workManageModule)->slot13(
                ((Object_vptr_0*)self->m_enumerationStart->m_collisionAttackModule)->slot26(0, false),
                0x21000007);
            Object_vptr_0* attack = (Object_vptr_0*)self->m_enumerationStart->m_collisionAttackModule;
            float size = soValueAccesser::getConstantFloat(self, 0xBE8, 0);
            attack->slot20(0, size);
        }
        ((Object_vptr_8*)self->m_enumerationStart->m_damageModule)->slot32();
        void* energyRaw = ((Object_vptr_0*)self->m_enumerationStart->m_kineticModule)->slot6(4);
        Object_vptr_0* energy = (Object_vptr_0*)__dynamic_cast(
            energyRaw, 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
        float a = soValueAccesser::getConstantFloat(self, 0xCEC, 0);
        float b = soValueAccesser::getConstantFloat(self, 0xCED, 0);
        u64 bits = energy->slot2();
        Vec2 v = unpack(bits);
        float sq = v.x * v.x + v.y * v.y;
        float len;
        if ((float)(double)nw4r::math::FAbs(sq) <= c[4]) {
            len = c[3];
        } else {
            len = sq * rsqrtf__Ff(sq);
        }
        if (len < b || a < b) {
            ((Object_vptr_0*)self->m_enumerationStart->m_collisionAttackModule)->slot5(0);
            return;
        }
        float w = ((Object_vptr_0*)self->m_enumerationStart->m_workManageModule)->slot12(0x21000007);
        float t = w * ((len - b) / (a - b));
        if (t > w) {
            t = w;
        }
        ((Object_vptr_0*)self->m_enumerationStart->m_collisionAttackModule)->slot17(0, (int)t, false);
        float lr = -((Object_vptr_0*)self->m_enumerationStart->m_postureModule)->slot9();
        float ang = (float)atan2(v.y, v.x * lr);
        int deg = (int)(c[10] * ang);
        if (deg < 0) {
            deg += 0x168;
        }
        ((Object_vptr_0*)self->m_enumerationStart->m_collisionAttackModule)->slot18(0, deg);
    }
}
}
