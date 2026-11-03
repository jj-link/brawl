#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Class_6DA4 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10ECC();
    virtual void fn_109_116D8();
    virtual void fn_109_116D4();
    virtual void fn_109_116D0();
    virtual void fn_109_116CC();
    virtual void* fn_109_116C4(int);
    virtual void fn_109_1170C();
    virtual void fn_109_11704();
    virtual void fn_109_116FC();
    virtual void fn_109_116F4();
    virtual void fn_109_116EC();
    virtual void fn_109_11684();
    virtual void fn_109_116B8();
    virtual void fn_109_116AC();
    virtual void fn_109_116A4();
    virtual void fn_109_11698();
    virtual void fn_109_11690();
};

class Class_71D8 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10E70();
    virtual void fn_109_119D4();
    virtual void fn_109_119CC();
    virtual void fn_109_119C4();
    virtual void fn_109_119BC();
    virtual void fn_109_119B4();
    virtual void fn_109_119AC();
    virtual void fn_109_119A4();
    virtual void fn_109_1199C();
    virtual void fn_109_11994();
    virtual void fn_109_1198C();
    virtual void fn_109_11984();
    virtual void fn_109_1197C();
    virtual void fn_109_1192C();
    virtual void fn_109_11974();
    virtual void fn_109_11964();
    virtual bool fn_109_11954(unsigned long);
};

extern "C" {
extern const char lbl_109_data_6108[], lbl_109_data_1670[];
extern const float lbl_109_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_109_D6F8(
    soModuleAccesser* accesser, unsigned long a, unsigned long b)
{
    soWorkManageModule& work = accesser->getWorkManageModule();
    void* energy = __dynamic_cast(
        accesser->getKineticModule().getEnergy(3),
        0, lbl_109_data_6108, lbl_109_data_1670, 1);

    float x;
    if (work.isFlag(0x22000010))
        x = soValueAccesser::getConstantFloat(accesser, a, 0);
    else
        x = soValueAccesser::getConstantFloat(accesser, b, 0);

    Vec2f v(x, lbl_109_rodata_20);
    Vec2f* out = reinterpret_cast<Vec2f*>(static_cast<char*>(energy) + 0x20);
    out->m_x = v.m_x;
    out->m_y = v.m_y;
}