#include <ft/fighter.h>
#include <ft/ft_manager.h>
#include <ft/ft_owner.h>
#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/damage/so_damage_module_impl.h>

#pragma force_active on
#pragma fp_contract off

extern "C" {
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void* fn_27_5BCD0(void*);
    unsigned int fn_27_5BE80(void*);
    float fn_27_112B98(ftOwner*);
    float fn_27_112BA4(ftOwner*);
    bool fn_27_111E00(ftOwner*);
    unsigned int fn_27_111F1C(ftOwner*);
    int fn_27_10A35C(ftManager*);
    unsigned int* fn_27_14554C(void*, unsigned int, unsigned int);
    void fn_27_138458(Fighter*, int, int, int, int);
    void fn_27_4AB8(Fighter*);
    void fn_27_13E97C(Fighter*);

    extern void* lbl_27_bss_F0;
    extern const float lbl_27_rodata_1048;
    extern const float lbl_27_rodata_1058;
}

class SoundSlots {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void stop(int, int);
};

class EffectSlots {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42();
    virtual void s43(int);
    virtual void s44(int);
};

struct SlowBase {
    char padding[8];
};

class SlowSlots : public SlowBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10();
    virtual int s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16();
    virtual void s17(); virtual void s18();
    virtual int s19();
};

struct GroundBase {
    char padding[8];
};

class GroundSlots : public GroundBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(int, int);
};

struct UpdateFlags {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

extern "C" void fn_27_12DCA8(Fighter* fighter)
{
    soModuleAccesser* accesser = fighter->m_moduleAccesser;

    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0)
            singleton = fn_27_5BCD0(singleton);
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        if (!accesser->m_enumerationStart->m_stopModule->isStop()) {
            ftOwner* owner = fighter->getOwner();
            soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;

            work->countDownInt(0x10000002, 0);
            work->countDownInt(0x10000004, 0);
            work->countDownInt(0x10000006, 0);
            work->countDownInt(0x10000009, 0);
            work->countDownInt(0x1000000a, 0);
            work->countDownInt(0x1000000b, 0);
            work->countDownInt(0x1000000e, 0);
            work->countDownInt(0x1000000f, 0);
            work->countDownInt(0x10000010, 0);
            work->countDownInt(0x10000011, 0);
            work->countDownInt(0x10000012, 0);
            work->countDownInt(0x10000026, 0);
            work->countDownInt(0x10000027, 0);
            work->countDownInt(0x10000020, 0);
            work->countDownInt(0x10000031, 0);
            work->countDownInt(0x10000039, 0);

            int timer = accesser->m_enumerationStart->m_workManageModule->getInt(0x10000038);
            if (timer > 0) {
                accesser->m_enumerationStart->m_workManageModule->setInt(timer - 1, 0x10000038);
                if (timer - 1 <= 0) {
                    soModuleAccesser* a = fighter->m_moduleAccesser;
                    a->m_enumerationStart->m_workManageModule->setInt(0, 0x10000038);
                    a->m_enumerationStart->m_workManageModule->setInt(0, 0x1000002c);
                    a->m_enumerationStart->m_workManageModule->setFloat(lbl_27_rodata_1048, 0x1100000d);
                    a->m_enumerationStart->m_workManageModule->setInt(0, 0x1000003d);
                }
            }

            int status = accesser->m_enumerationStart->m_statusModule->getStatusKind();
            unsigned int* data = fn_27_14554C(
                &g_ftCommonDataAccesser, fighter->getFtKind(), status);

            if (((data[1] >> 23) & 1) == 0) {
                float value = accesser->m_enumerationStart->m_workManageModule->getFloat(0x11000003);
                float ownerMax = fn_27_112B98(owner);
                float max = soValueAccesser::getConstantFloat(accesser, 0xca1, 0);
                max += ownerMax;
                float ownerAdd = fn_27_112BA4(owner);
                float increment = soValueAccesser::getConstantFloat(accesser, 0xca6, 0);
                increment += ownerAdd;
                value += increment;
                if (value > max)
                    value = max;
                accesser->m_enumerationStart->m_workManageModule->setFloat(value, 0x11000003);
            }

            if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x1200000e) == 1) {
                int time = accesser->m_enumerationStart->m_workManageModule->getInt(0x1000001e);
                accesser->m_enumerationStart->m_workManageModule->setInt(time - 1, 0x1000001e);
                if (time - 1 < soValueAccesser::getConstantInt(accesser, 0x5a78, 0)) {
                    int sound = accesser->m_enumerationStart->m_workManageModule->getInt(0x1000001f);
                    if (sound != -1) {
                        ((SoundSlots*)accesser->m_enumerationStart->m_soundModule)->stop(sound, 0);
                        accesser->m_enumerationStart->m_workManageModule->setInt(-1, 0x1000001f);
                    }
                }
                if (time - 1 <= 0)
                    fighter->setSuperStar(false, -1, false);
            }

            if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x12000012) == 1) {
                int time = accesser->m_enumerationStart->m_workManageModule->getInt(0x10000025);
                accesser->m_enumerationStart->m_workManageModule->setInt(time - 1, 0x10000025);
                if ((time - 1 <= 0 ||
                     accesser->m_enumerationStart->m_workManageModule->getFloat(0x1100000c) <= lbl_27_rodata_1048) &&
                    !fn_27_111E00(owner)) {
                    fighter->setMetal(false, lbl_27_rodata_1058, -1);
                }
            }

            unsigned char* flags = (unsigned char*)fighter + 0x138;
            if ((unsigned int)((*flags >> 3) & 1) == 1 &&
                !owner->isSubOwner() &&
                (((0u - (((unsigned int)*(unsigned char*)((char*)g_ftManager + 0x6c) << 24) >> 31)) |
                  (((unsigned int)*(unsigned char*)((char*)g_ftManager + 0x6c) << 24) >> 31)) >> 31) == 1) {
                soDamageModule* damage = accesser->m_enumerationStart->m_damageModule;
                float limit = soValueAccesser::getConstantFloat(accesser, 0xc8d, 0);
                if (damage->getDamage(0) < limit) {
                    int count = accesser->m_enumerationStart->m_workManageModule->getInt(0x1000002d);
                    int nextCount = count;
                    ++nextCount;
                    if (nextCount >= soValueAccesser::getConstantInt(accesser, 0x5a14, 0)) {
                        nextCount = 0;
                        float amount = soValueAccesser::getConstantFloat(accesser, 0xc8e, 0);
                        accesser->m_enumerationStart->m_damageModule->addDamage(amount, 0);
                    }
                    accesser->m_enumerationStart->m_workManageModule->setInt(nextCount, 0x1000002d);
                }
            }

            if (!owner->isSubOwner() && fn_27_111F1C(owner) == 1) {
                soModuleAccesser* a = fighter->m_moduleAccesser;
                bool allowed;
                if (a->m_enumerationStart->m_situationModule->getKind() == 5)
                    allowed = false;
                else
                    allowed = a->m_enumerationStart->m_workManageModule->isFlag(0x12000006) != 1;

                if (allowed == 1 && !fn_27_10A35C(g_ftManager)) {
                    unsigned char managerBits = *((unsigned char*)g_ftManager + 0x6c);
                    if (((0u - ((managerBits >> 6) & 1u)) |
                         ((managerBits >> 6) & 1u)) >> 31 == 1)
                        g_ftManager->setFinal(fighter->m_entryId, false);
                }
            }
        }

        if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x12000026) == 1 &&
            ((SlowSlots*)accesser->m_enumerationStart->m_slowModule)->s11() <= 0) {
            fn_27_138458(fighter, 0, 1, 0, 0);
        }

        if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x12000028) == 1 &&
            ((SlowSlots*)accesser->m_enumerationStart->m_slowModule)->s19() <= 0) {
            soModuleAccesser* a = fighter->m_moduleAccesser;
            if (a->m_enumerationStart->m_workManageModule->isFlag(0x12000028) == 1) {
                ((EffectSlots*)a->m_enumerationStart->m_effectModule)->s44(8);
                ((EffectSlots*)a->m_enumerationStart->m_effectModule)->s43(9);
                a->m_enumerationStart->m_workManageModule->offFlag(0x12000028);
                ((SlowSlots*)a->m_enumerationStart->m_slowModule)->s16();
            }
        }
    }

    fn_27_4AB8(fighter);

    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0)
            singleton = fn_27_5BCD0(singleton);
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1 &&
        !accesser->m_enumerationStart->m_stopModule->isStop() &&
        accesser->m_enumerationStart->m_situationModule->getKind() == 2) {
        unsigned int* data = fn_27_14554C(
            &g_ftCommonDataAccesser, fighter->getFtKind(),
            accesser->m_enumerationStart->m_statusModule->getStatusKind());
        if (((data[0] >> 26) & 1) != 0) {
            soControllerModule* controller = accesser->m_enumerationStart->m_controllerModule;
            if (controller->getStickY() < -soValueAccesser::getConstantFloat(accesser, 0xc5e, 0))
                ((GroundSlots*)accesser->m_enumerationStart->m_groundModule)->s24(0, 0);
            else
                ((GroundSlots*)accesser->m_enumerationStart->m_groundModule)->s24(1, 0);
        }
    }

    UpdateFlags& flags138 = *(UpdateFlags*)((char*)fighter + 0x138);
    *(float*)((unsigned char*)fighter + 0x114) = lbl_27_rodata_1048;
    *(int*)((unsigned char*)fighter + 0x118) = 0;
    *(float*)((unsigned char*)fighter + 0x120) = lbl_27_rodata_1048;
    *(float*)((unsigned char*)fighter + 0x11c) = lbl_27_rodata_1048;
    flags138.bit0 = 0;
    flags138.bit2 = 0;
    flags138.bit1 = flags138.bit2;
    *(float*)((unsigned char*)fighter + 0x130) = lbl_27_rodata_1048;
    *(float*)((unsigned char*)fighter + 0x128) = lbl_27_rodata_1048;
    *((unsigned char*)fighter + 0x139) = (unsigned char)(*((unsigned char*)fighter + 0x139) | 0x80);

    fn_27_13E97C(fighter);
}
