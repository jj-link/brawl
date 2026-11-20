#include <types.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>

#pragma force_active on
#pragma scheduling off
#pragma optimization_level 2

class MyTurn {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual unsigned isTurn(const soModuleEnumeration* e);
};

class MyWork {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual f32 getFloat(u32 index);
    virtual void setFloat(f32 value, u32 index);
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual unsigned isFlag(u32 index);
    virtual void m19();
    virtual void m20();
    virtual void setFlag(unsigned on, u32 index);
};

class MyKinetic {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void* getEnergy(int index);
    virtual void m7();
    virtual void m8();
    virtual void clearSpeedAll();
    virtual void m11();
    virtual void m12();
    virtual void unableEnergyAll();
};

static inline MyTurn* getTurn(MyTurn* turn, MyKinetic*& kinetic, const soModuleEnumeration* e) {
    kinetic = reinterpret_cast<MyKinetic*>(e->m_kineticModule);
    return turn;
}

static inline void setNegative(MyWork* work, f32 value, u32 index) {
    work->setFloat(-value, index);
}

extern "C" {

extern const f32 lbl_118_rodata_30[];
extern const char lbl_118_data_620C[];
extern const char lbl_118_data_17B0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_118_C3EC(void*, const Vec2f*);
unsigned long long fn_118_100CC(f32 angle, f32 scale);
f32 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser* accesser, u32 id, u32 index);

void fn_118_FA18(soModuleAccesser* accesser) {
    f32 v;
    const f32* rodata = lbl_118_rodata_30;
    const soModuleEnumeration* e = accesser->m_enumerationStart;
    MyWork* work = reinterpret_cast<MyWork*>(e->m_workManageModule);
    MyTurn* turn = reinterpret_cast<MyTurn*>(e->m_turnModule);
    MyKinetic* kinetic;

    unsigned nowTurn = getTurn(turn, kinetic, e)->isTurn(e);
    unsigned prevTurn = work->isFlag(0x22000015);
    work->setFlag(nowTurn, 0x22000015);

    if (nowTurn != prevTurn && nowTurn == 0) {
        f32 angle = work->getFloat(0x21000005);
        f32 s = (f32)sin(angle);
        f32 c = (f32)cos(angle);
        v = (f32)atan2(s, -c);
        f32 absv = (f32)(double)nw4r::math::FAbs(v);
        if (absv <= rodata[7]) {
            v = rodata[0];
        } else {
            f32 diff = (f32)(double)nw4r::math::FAbs(rodata[4] - absv);
            if (diff <= rodata[7]) {
                v = rodata[4];
            }
        }
        work->setFloat(v, 0x21000005);
        f32 scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFBD, 0);
        Vec2f speed;
        unsigned long long bits = fn_118_100CC(v, scale);
        u8* bp = reinterpret_cast<u8*>(&bits);
        speed.m_x = *reinterpret_cast<f32*>(bp);
        speed.m_y = *reinterpret_cast<f32*>(bp + 4);
        kinetic->clearSpeedAll();
        kinetic->unableEnergyAll();
        void* energy = kinetic->getEnergy(3);
        void* stop = __dynamic_cast(energy, 0, lbl_118_data_620C, lbl_118_data_17B0, 1);
        fn_118_C3EC(reinterpret_cast<char*>(stop) + 8, &speed);
        reinterpret_cast<u8*>(stop)[5] |= 0x80;
        setNegative(work, work->getFloat(0x21000004), 0x21000004);
        setNegative(work, work->getFloat(0x21000008), 0x21000008);
        setNegative(work, work->getFloat(0x21000006), 0x21000006);
    }
}

}
