#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C();
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C();
    virtual void fn_96_23D44();
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual void fn_96_23D14();
    virtual void fn_96_23D04();
    virtual void fn_96_23CF4();
    virtual void fn_96_23CE4();
};
struct EnergyFlags {
    char pad[5];
    unsigned char enabled : 1;
};
extern "C" {
extern const float lbl_96_rodata_94;
extern const char lbl_96_data_AF64[], lbl_96_data_5E00[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
}
extern "C" void fn_96_173B4(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000017)) {
        float y = accesser->getWorkManageModule().getFloat(0x21000007);
        float x = accesser->getWorkManageModule().getFloat(0x21000006);
        Vec2f input;
        input.m_x = x;
        input.m_y = y;
        if (input.m_y > lbl_96_rodata_94) {
            if (accesser->getSituationModule().getKind() == 0)
                accesser->getStatusModule().changeStatusRequest(0x11c, accesser);
        } else if (input.m_y < lbl_96_rodata_94) {
            if (accesser->getGroundModule().isPassableGround(0))
                accesser->getStatusModule().changeStatusRequest(0x122, accesser);
        } else if (lbl_96_rodata_94 != input.m_x) {
            if (accesser->getSituationModule().getKind() == 0) {
                soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
                    accesser->getKineticModule().getEnergy(3), 0,
                    lbl_96_data_AF64, lbl_96_data_5E00, 1));
                float xv;
                Vec2f speed;
                speed.m_x = lbl_96_rodata_94;
                speed.m_y = lbl_96_rodata_94;
                xv = input.m_x;
                float sign = (float)(xv < lbl_96_rodata_94 ? -1 : 1);
                float scale = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
                speed.m_x = scale * sign;
                Vec3f rot;
                energy->resetEnergy(0, &speed, fn_96_BC54(&rot, lbl_96_rodata_94, lbl_96_rodata_94, lbl_96_rodata_94), accesser);
                reinterpret_cast<EnergyFlags*>(energy)->enabled = 1;
            }
        }
        accesser->getWorkManageModule().offFlag(0x22000017);
    }
}
