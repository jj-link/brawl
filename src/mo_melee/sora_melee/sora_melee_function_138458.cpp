#include <ft/fighter.h>
#include <so/so_value_accesser.h>
#pragma force_active on
#pragma fp_contract off

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual u32 slot16();
    virtual u32 slot17(u32);
    virtual void slot18(u32, const soModuleEnumeration*);
    virtual void slot19(u32, const soModuleEnumeration*);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43(int);
    virtual void slot44(int);
};
class Object_vptr_0_NoContext {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual u32 slot16();
    virtual u32 slot17(u32);
    virtual void slot18(u32, const soModuleEnumeration*);
    virtual void slot19(u32);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43(int);
    virtual void slot44(int);
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38(int, int);
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
};
extern "C" u32* fn_27_14554C(void*, u32, u32);

#define WORK(a) reinterpret_cast<Object_vptr_0*>((a)->m_enumerationStart->m_workManageModule)
#define EFFECT(a) reinterpret_cast<Object_vptr_0*>((a)->m_enumerationStart->m_effectModule)
#define STATUS(a) reinterpret_cast<Object_vptr_0*>((a)->m_enumerationStart->m_statusModule)
#define SLOW(a) reinterpret_cast<Class_90D8*>((a)->m_enumerationStart->m_slowModule)

extern "C" void fn_27_138458(Fighter* self, u32 mode, int arg2, int value, u32 arg4) {
    soModuleAccesser* a = self->m_moduleAccesser;
    if (mode == 1) {
        u32 status = STATUS(a)->slot16();
        u32* data = fn_27_14554C(&g_ftCommonDataAccesser, self->getFtKind(), status);
        if (!((data[1] >> 27) & 1)) {
            if (arg4 == 1) {
                float scale = soValueAccesser::getConstantFloat(a, 0xDB2, 0);
                float frames = (float)soValueAccesser::getConstantInt(a, 0x5A81, 0);
                frames *= scale;
                value -= (int)frames;
                if (WORK(a)->slot17(0x12000026) == 1) {
                    EFFECT(a)->slot44(8);
                }
                EFFECT(a)->slot43(8);
                WORK(a)->slot18(0x12000027, a->m_enumerationStart);
            }
            SLOW(a)->fn_27_7AC38(arg2, value);
            WORK(a)->slot18(0x12000026, a->m_enumerationStart);
        }
    } else {
        if (WORK(a)->slot17(0x12000026) == 1) {
            SLOW(a)->fn_27_7B0B0();
            if (WORK(a)->slot17(0x12000027) == 1) {
                EFFECT(a)->slot44(8);
                EFFECT(a)->slot43(9);
                reinterpret_cast<Object_vptr_0_NoContext*>(a->m_enumerationStart->m_workManageModule)->slot19(0x12000027);
            }
            WORK(a)->slot19(0x12000026, a->m_enumerationStart);
        }
    }
}
