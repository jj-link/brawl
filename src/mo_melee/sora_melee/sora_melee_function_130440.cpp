#include <ft/ft_manager.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/ground/so_ground_util.h>
#include <so/link/so_link_module_impl.h>
#include <so/model/so_model_module_simple.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <types.h>

#pragma force_active on
#pragma fp_contract off

struct Vec2Words {
    unsigned int x;
    unsigned int y;
};

class VectorModuleIface : public soNullable {
public:
    virtual void s0C() = 0;
    virtual void s10() = 0;
    virtual void s14() = 0;
    virtual void s18() = 0;
    virtual void s1C() = 0;
    virtual void s20() = 0;
    virtual void s24() = 0;
    virtual void s28() = 0;
    virtual void s2C() = 0;
    virtual void s30() = 0;
    virtual void s34() = 0;
    virtual void s38() = 0;
    virtual unsigned long long getVector(short*) = 0;
};

class GroundModuleIface : public soNull, public soNullable {
public:
    virtual void s1() = 0; virtual void s2() = 0; virtual void s3() = 0; virtual void s4() = 0;
    virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0; virtual void s8() = 0;
    virtual void s9() = 0; virtual void s10() = 0; virtual void s11() = 0; virtual void s12() = 0;
    virtual void s13() = 0; virtual void s14() = 0; virtual void s15() = 0; virtual void s16() = 0;
    virtual void s17() = 0; virtual void s18() = 0; virtual void s19() = 0; virtual void s20() = 0;
    virtual void s21() = 0; virtual void s22() = 0; virtual void s23() = 0; virtual void s24() = 0;
    virtual void s25() = 0; virtual void s26() = 0; virtual void s27() = 0; virtual void s28() = 0;
    virtual void s29() = 0; virtual void s30() = 0; virtual void s31() = 0; virtual void s32() = 0;
    virtual void s33() = 0; virtual void s34() = 0; virtual void s35() = 0; virtual void s36() = 0;
    virtual void s37() = 0; virtual void s38() = 0; virtual void s39() = 0; virtual void s40() = 0;
    virtual void s41() = 0; virtual void s42() = 0; virtual void s43() = 0; virtual void s44() = 0;
    virtual void s45() = 0; virtual void s46() = 0; virtual void s47() = 0; virtual void s48() = 0;
    virtual void s49() = 0; virtual void s50() = 0; virtual void s51() = 0; virtual void s52() = 0;
    virtual void s53() = 0; virtual void s54() = 0; virtual void s55() = 0; virtual void s56() = 0;
    virtual void s57() = 0; virtual void s58() = 0; virtual void s59() = 0; virtual void s60() = 0;
    virtual void s61() = 0; virtual void s62() = 0; virtual void s63() = 0; virtual void s64() = 0;
    virtual void s65() = 0; virtual void s66() = 0; virtual void s67() = 0;
    virtual u32 getSlot70(float, u32) = 0;
};

extern "C" {
void fn_27_15746C(void* self, int arg1, unsigned char* arg2);
float rsqrtf__Ff(float);
extern const float lbl_27_rodata_1018[];
}

extern "C" int fn_27_130440(void* arg0) {
            Vec2Words v;
    const float* k = lbl_27_rodata_1018;
    soModuleAccesser* acc = *reinterpret_cast<soModuleAccesser**>(static_cast<char*>(arg0) + 0x60);
    int r29 = -1;

    if (!acc->m_enumerationStart->m_workManageModule->isFlag(0x12000001) &&
        acc->m_enumerationStart->m_situationModule->getKind() != 5) {
        Vec3f pos;
        if (!acc->m_enumerationStart->m_linkModule->isModelConstraint()) {
            pos = acc->m_enumerationStart->m_postureModule->getPos();
        } else {
            soModelModule* model = acc->m_enumerationStart->m_modelModule;
            int nodeId = model->getCorrectNodeId(0x12D);
            pos = model->getNodeGlobalPosition(nodeId, false);
        }

        int dead = soGroundUtil::checkDeadArea(&pos, k[12], k[12]);
        switch (dead) {
        case 2: r29 = 2; break;
        case 3: r29 = 3; break;
        case 0: r29 = 0; break;
        case 1: r29 = 1; break;
        }

        if (r29 != -1) {
            union { short value; int align; } flag;
            flag.value = 2;
            unsigned long long bits = reinterpret_cast<VectorModuleIface*>(acc->m_enumerationStart->m_kineticModule)->getVector(&flag.value);
            v = *reinterpret_cast<Vec2Words*>(&bits);
            float sum = reinterpret_cast<Vec2f*>(&v)->m_x * reinterpret_cast<Vec2f*>(&v)->m_x
                      + reinterpret_cast<Vec2f*>(&v)->m_y * reinterpret_cast<Vec2f*>(&v)->m_y;
            float mag;
            if ((float)(double)nw4r::math::FAbs(sum) <= k[23]) {
                mag = k[12];
            } else {
                mag = sum * rsqrtf__Ff(sum);
            }
            if (mag < k[24] ||
                (reinterpret_cast<unsigned char*>(g_ftManager)[0x68] == 1 &&
                 acc->m_enumerationStart->m_workManageModule->isFlag(0x12000034) == 1)) {
                unsigned char sp8 = 0;
                fn_27_15746C(static_cast<char*>(arg0) + 0x13C, r29, &sp8);
                if (sp8 == 1) r29 = -1;
            }
            if (r29 == 0) {
                if (acc->m_enumerationStart->m_workManageModule->isFlag(0x12000029)) {
                    r29 = -1;
                } else {
                    if (((reinterpret_cast<unsigned char*>(g_ftManager)[0x6E] >> 1) & 1) == 0) {
                        int kind = acc->m_enumerationStart->m_situationModule->getKind();
                        if (kind != 0 && kind != 1) {
                            float c = soValueAccesser::getConstantFloat(acc, 0xCE6, 0);
                            if (reinterpret_cast<Vec2f*>(&v)->m_y <= c) {
                                if (!acc->m_enumerationStart->m_workManageModule->isFlag(0x22000004)) {
                                    if (!acc->m_enumerationStart->m_stopModule->isDamage()) {
                                        r29 = -1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (reinterpret_cast<unsigned char*>(g_ftManager)[0x68] == 1) {
            if (((static_cast<unsigned char*>(arg0)[0x139] >> 6) & 1u) == 1u ||
                reinterpret_cast<GroundModuleIface*>(acc->m_enumerationStart->m_groundModule)->getSlot70(k[15], 0) == 1) {
                r29 = 4;
            }
            static_cast<unsigned char*>(arg0)[0x139] = static_cast<unsigned char>(static_cast<unsigned char*>(arg0)[0x139] & 0xFFFFFFBF);
        }
    }
    return r29;
}
