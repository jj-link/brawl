#pragma force_active on
#pragma fp_contract off

#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <types.h>

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" float fn_27_192278(void*, unsigned long);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7DB0;

struct StageVtBase {
    char pad[0x3c];
};

class StageVt : public StageVtBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual int s40();
};

extern "C" void fn_27_397B04(void* arg0, soModuleAccesser* arg1) {
    if (arg1->m_enumerationStart->m_workManageModule->isFlag(0x22000017)) {
        Vec2f v1(arg1->m_enumerationStart->m_workManageModule->getFloat(0x21000006),
                 arg1->m_enumerationStart->m_workManageModule->getFloat(0x21000007));
        int r29;
        int r28;
        if (((StageVt*)arg1->m_stageObject)->s40() == 5) {
            r29 = 0x198;
            r28 = 0x19e;
        } else {
            r29 = 0x11c;
            r28 = 0x122;
        }
        if (v1.m_y > lbl_27_rodata_7DB0) {
            if (arg1->m_enumerationStart->m_situationModule->getKind() == 0) {
                arg1->m_enumerationStart->m_statusModule->changeStatusRequest(r29, arg1);
            }
        } else if (v1.m_y < lbl_27_rodata_7DB0) {
            if (arg1->m_enumerationStart->m_groundModule->isPassableGround(0)) {
                arg1->m_enumerationStart->m_statusModule->changeStatusRequest(r28, arg1);
            }
        } else if (lbl_27_rodata_7DB0 != v1.m_x) {
            if (arg1->m_enumerationStart->m_situationModule->getKind() == 0) {
                soKineticEnergy* e = (soKineticEnergy*)__dynamic_cast(
                    arg1->m_enumerationStart->m_kineticModule->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
                float sp10 = v1.m_x;
                Vec2f v2;
                Vec3f v3;
                v2.m_x = lbl_27_rodata_7DB0;
                v2.m_y = lbl_27_rodata_7DB0;
                int sign = (sp10 < lbl_27_rodata_7DB0) ? -1 : 1;
                float fsign = (float)sign;
                float speed = fn_27_192278(arg1, 0xfa3);
                v2.m_x = speed * fsign;
                v3.m_x = lbl_27_rodata_7DB0;
                v3.m_y = lbl_27_rodata_7DB0;
                v3.m_z = lbl_27_rodata_7DB0;
                e->resetEnergy(0, &v2, &v3, arg1);
                ((unsigned char*)e)[5] |= 0x80;
            }
        }
        arg1->m_enumerationStart->m_workManageModule->offFlag(0x22000017);
    }
}
