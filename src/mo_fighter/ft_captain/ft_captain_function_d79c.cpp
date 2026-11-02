#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Class_6F8C {
public:
    virtual void fn_100_6C60();
    virtual void fn_100_12D58();
    virtual void fn_100_132A0();
    virtual void fn_100_1329C();
    virtual void fn_100_13298();
    virtual void fn_100_13294();
    virtual void* fn_100_1328C(int);
    virtual void fn_100_132D4();
    virtual void fn_100_132CC();
    virtual void fn_100_132C4();
    virtual void fn_100_132BC();
    virtual void fn_100_132B4();
    virtual void fn_100_1324C();
    virtual void fn_100_13280();
    virtual void fn_100_13274();
    virtual void fn_100_1326C();
    virtual void fn_100_13260();
    virtual void fn_100_13258();
};

class Class_7164 {
public:
    virtual void fn_100_6C60();
    virtual void fn_100_12CFC();
    virtual void fn_100_1348C();
    virtual void fn_100_13484();
    virtual void fn_100_1347C();
    virtual void fn_100_13474();
    virtual void fn_100_1346C();
    virtual void fn_100_13464();
    virtual void fn_100_1345C();
    virtual void fn_100_13454();
    virtual void fn_100_1344C();
    virtual void fn_100_13444();
    virtual void fn_100_1343C();
    virtual void fn_100_13434();
    virtual void fn_100_133E4();
    virtual void fn_100_1342C();
    virtual void fn_100_1341C();
    virtual bool fn_100_1340C(unsigned long);
};

extern "C" {
extern const char lbl_100_data_617C[], lbl_100_data_16D4[];
extern const float lbl_100_rodata_20;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_100_D79C(
    soModuleAccesser* accesser, unsigned long a, unsigned long b)
{
    soWorkManageModule& work = accesser->getWorkManageModule();
    void* energy = __dynamic_cast(
        accesser->getKineticModule().getEnergy(3),
        0, lbl_100_data_617C, lbl_100_data_16D4, 1);

    float x;
    if (work.isFlag(0x22000010))
        x = soValueAccesser::getConstantFloat(accesser, a, 0);
    else
        x = soValueAccesser::getConstantFloat(accesser, b, 0);

    Vec2f v(x, lbl_100_rodata_20);
    Vec2f* out = reinterpret_cast<Vec2f*>(static_cast<char*>(energy) + 0x20);
    out->m_x = v.m_x;
    out->m_y = v.m_y;
}
