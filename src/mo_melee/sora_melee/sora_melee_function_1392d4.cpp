#include <types.h>
#include <so/so_module_accesser.h>

#pragma force_active on

#define D(n) virtual void slot##n();

class Object_vptr_0 {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7)
    D(8) D(9) D(10) D(11)
    virtual float slot12(unsigned);
    virtual void slot13(float, unsigned);
    D(14)
    virtual void slot15(float, unsigned);
    D(16)
    virtual unsigned slot17(unsigned);
    D(18)
    virtual void slot19(unsigned);
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27)
    D(28) D(29) D(30) D(31) D(32) D(33) D(34) D(35)
    D(36) D(37) D(38) D(39) D(40) D(41) D(42) D(43) D(44)
    virtual unsigned slot45(int, int, int);
    D(46) D(47)
    virtual void slot48(float, float, float, int, int, int, int);
    virtual void slot49(float, int);
    D(50)
    virtual float slot51(int);
    D(52) D(53)
    virtual void slot54(int, int, int);
    virtual void slot55(float, float, int);
    D(56)
    virtual void slot57(float, int);
};

struct Owner {
    char pad[0x60];
    soModuleAccesser* accesser;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
extern "C" const float lbl_27_rodata_1048;
extern "C" const float lbl_27_rodata_107C;

#define WORK reinterpret_cast<Object_vptr_0*>(a->m_enumerationStart->m_workManageModule)
#define CTRL reinterpret_cast<Object_vptr_0*>(a->m_enumerationStart->m_controllerModule)
#define OTHER reinterpret_cast<Object_vptr_0*>(a->m_enumerationStart->m_itemManageModule)

extern "C" void fn_27_1392D4(
    Owner* owner, unsigned mode, int arg, unsigned reset, float x, float y)
{
    soModuleAccesser* a = owner->accesser;

    if (mode == 1) {
        if (WORK->slot17(0x12000009) == 1) {
            float old = CTRL->slot51(1);
            float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xd84, 0);
            float v = old + x;
            if (v > limit)
                v = limit;
            CTRL->slot49(v, 1);
        } else if (OTHER->slot45(0x2f, 0, arg) == 1) {
            float v = x + (float)getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0x5a69, 0);
            float hi = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xd83, 0);
            float lo = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xd82, 0);
            CTRL->slot48(v, lo, hi, 0, -1, 1, 0);
        }

        if (WORK->slot17(0x12000009) == 1) {
            WORK->slot15(y, 0x11000006);
            Object_vptr_0* w = WORK;
            float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xd88, 0);
            float rate = w->slot12(0x11000006);
            scale = rate * scale;
            float base = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xd86, 0);
            float v = base + scale;
            float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xd87, 0);
            if (v > limit)
                v = limit;
            float k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                a, 0xbe9, 0);
            OTHER->slot57(v * k, 0x2f);
        }
    } else if (WORK->slot17(0x12000009) == 1) {
        WORK->slot19(0x12000009);
        WORK->slot13(lbl_27_rodata_1048, 0x11000006);
        if (reset == 1) {
            OTHER->slot55(lbl_27_rodata_107C, lbl_27_rodata_1048, 0x2f);
        } else {
            OTHER->slot54(0x2f, 1, 0);
        }
    }
}