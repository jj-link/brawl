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
    virtual int slot4(u32);
    virtual void slot5(int, u32);
    virtual void slot6(int, int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual u32 slot17(u32);
    virtual void slot18(u32);
    virtual void slot19(u32);
    virtual void slot20(int, int);
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
    virtual void slot39(int);
};

#define WORK(a) reinterpret_cast<Object_vptr_0*>((a)->m_enumerationStart->m_workManageModule)
#define SOUND(a) reinterpret_cast<Object_vptr_0*>((a)->m_enumerationStart->m_soundModule)
#define EFFECT(a) reinterpret_cast<Object_vptr_0*>((a)->m_enumerationStart->m_effectModule)

extern "C" void fn_27_138CBC(Fighter* self, u32 mode, int arg) {
    soModuleAccesser* a = self->m_moduleAccesser;

    if (mode == 1) {
        WORK(a)->slot19(0x1200000c);
        WORK(a)->slot19(0x1200000d);
        WORK(a)->slot18(0x1200000b);

        int value;
        if (arg == 0) {
            value = soValueAccesser::getConstantInt(a, 0x5a6e, 0);
        } else {
            value = soValueAccesser::getConstantInt(a, 0x5a71, 0);
            float scale = soValueAccesser::getConstantFloat(a, 0xdb2, 0);
            float frames = (float)soValueAccesser::getConstantInt(a, 0x5a72, 0);
            frames *= scale;
            value -= (int)frames;
            WORK(a)->slot5(value, 0x1000001b);
            SOUND(a)->slot6(0x1c, 1);
        }
        WORK(a)->slot5(value, 0x1000001b);
    } else if (WORK(a)->slot17(0x1200000b) == 1) {
        int id = WORK(a)->slot4(0x1000001d);
        if (id != -1) {
            SOUND(a)->slot20(id, 0);
            WORK(a)->slot5(-1, 0x1000001d);
        }
        EFFECT(a)->slot39(0x14);
        EFFECT(a)->slot39(0x15);
        EFFECT(a)->slot39(0x16);
        WORK(a)->slot19(0x1200000b);
    }
}
