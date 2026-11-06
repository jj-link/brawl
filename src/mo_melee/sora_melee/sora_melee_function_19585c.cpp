#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_26B0;
extern const float lbl_27_rodata_26C0;
}

struct GroundPad {
    int pad0;
    int pad4;
};

class GroundCall : public GroundPad {
public:
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4();
    virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9();
    virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14();
    virtual void g15(); virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
    virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23(); virtual void g24();
    virtual void g25(); virtual void g26();
    virtual u32 g27(u32 a, const void* b);
    virtual u32 g28(void* out, u32 b);
};

class EffectCall {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void req(u32 id, void* pos, void* rot, float scale, u32 a, int b, float x, float z);
};

class EnergyCall {
public:
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4();
    virtual void e5(); virtual void e6(); virtual void e7();
    virtual void setVec(void* v);
};

class KineticCall {
public:
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3();
    virtual void k4(); virtual void k5();
    virtual EnergyCall* getEnergy(int index);
};

class SoundCall {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void play(u32 id, u32 a, int b, int c);
};

extern "C" int fn_27_19585C(soModuleAccesser* self) {
    Vec3f pos;
    Vec3f zero;
    Vec3f c;
    Vec2f v;

    if (((GroundCall*)self->m_enumerationStart->m_groundModule)->g27(0, self->m_enumerationStart) == 1) {
        if (((GroundCall*)self->m_enumerationStart->m_groundModule)->g28(&v, 0) == 1) {
            zero.m_x = lbl_27_rodata_26B0;
            zero.m_y = lbl_27_rodata_26B0;
            zero.m_z = lbl_27_rodata_26B0;
            pos.m_x = v.m_x;
            pos.m_y = v.m_y;
            pos.m_z = lbl_27_rodata_26B0;
            EffectCall* effect = (EffectCall*)self->m_enumerationStart->m_effectModule;
            effect->req(0x4F0003, &pos, &zero, lbl_27_rodata_26C0, 0, -1, v.m_x, lbl_27_rodata_26B0);
            float k = soValueAccesser::getConstantFloat(self, 0xCDC, 0);
            c.m_x = k;
            c.m_y = k;
            c.m_z = lbl_27_rodata_26B0;
            KineticCall* kinetic = (KineticCall*)self->m_enumerationStart->m_kineticModule;
            EnergyCall* energy = kinetic->getEnergy(4);
            energy->setVec(&c);
            SoundCall* sound = (SoundCall*)self->m_enumerationStart->m_soundModule;
            sound->play(0x1CE1, 0, 0, 0);
            return 1;
        }
    }
    return 0;
}
