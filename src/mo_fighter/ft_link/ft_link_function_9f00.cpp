#include <so/so_module_accesser.h>
#pragma force_active on

class SoWork {
public:
    virtual void w0() = 0;
    virtual void w1() = 0;
    virtual void w2() = 0;
    virtual void w3() = 0;
    virtual int getInt(unsigned long) = 0;
    virtual void w5() = 0;
    virtual void w6() = 0;
    virtual void a(unsigned long) = 0;
    virtual void w8() = 0;
    virtual void w9() = 0;
    virtual void w10() = 0;
    virtual void w11() = 0;
    virtual void w12() = 0;
    virtual void setFloat(float, unsigned long) = 0;
    virtual void w13() = 0;
    virtual void w15() = 0;
    virtual void w16() = 0;
    virtual void w17() = 0;
    virtual void b(unsigned long) = 0;
    virtual void c(unsigned long) = 0;
};

class SoMotion {
public:
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void setVal(float) = 0;
    virtual void m11() = 0;
    virtual float getOther() = 0;
    virtual void m13() = 0;
    virtual float getSomething(unsigned long) = 0;
};

class Energy {
public:
    virtual void e0() = 0;
    virtual void e1() = 0;
    virtual void e2() = 0;
    virtual void e3() = 0;
    virtual void e4() = 0;
    virtual void e5() = 0;
    virtual void update() = 0;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_93_data_3018[];
extern const char lbl_93_data_30FC[];
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_93_10AB0(soModuleAccesser*);
}

extern "C" void fn_93_9F00(void*, void*, soModuleAccesser* accesser) {
    int kind = accesser->m_enumerationStart->m_statusModule->getStatusKind();

    switch (kind) {
    case 0x33: {
        switch (((SoWork*)accesser->m_enumerationStart->m_workManageModule)
                    ->getInt(0x20000000)) {
        case 0x66: {
            SoWork* work =
                (SoWork*)accesser->m_enumerationStart->m_workManageModule;
            SoMotion* motion =
                (SoMotion*)accesser->m_enumerationStart->m_motionModule;

            work->b(0x1200003e);
            work->c(0x1200003f);
            work->a(0x10000040);

            void* energyObject =
                accesser->m_enumerationStart->m_kineticModule->getEnergy(1);
            Energy* energy = (Energy*)__dynamic_cast(
                energyObject, 0, lbl_93_data_3018, lbl_93_data_30FC, 1);
            energy->update();

            float value = motion->getSomething(0x66);
            float constant =
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0xfb0, 0);
            float limit = value - constant;

            if (motion->getOther() > limit)
                motion->setVal(limit);

            work->setFloat(constant, 0x11000015);
            break;
        }
        }
        break;
    }

    case 0x11b:
        fn_93_10AB0(accesser);
        break;
    }
}
