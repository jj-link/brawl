#include <ft/fighter.h>
#include <so/so_value_accesser.h>
#pragma force_active on
#pragma fp_contract off

extern "C" u32* fn_27_14554C(void*, u32, u32);
extern "C" const float lbl_27_rodata_1048;
extern "C" const double lbl_27_rodata_1068;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(u32);
    virtual void slot5(int, u32);
    virtual int slot6(u32, int);
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
    virtual u32 slot17(u32, const void* = 0);
    virtual void slot18(u32, const void*);
    virtual void slot19(u32, const void*);
    virtual void slot20(int, int, const void*);
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(int, int, int);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38(u32, float);
    virtual void slot39(u32);
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55(u32, int, int, int);
};

class Object_vptr_1 {
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
    virtual void slot16(u32, int, int, float*, float*, int);
    virtual u32 slot17(u32);
};

#define MOD(off) reinterpret_cast<Object_vptr_0*>(*reinterpret_cast<void* const*>(reinterpret_cast<const char*>(acc->m_enumerationStart) + (off)))
#define MOD1(off) reinterpret_cast<Object_vptr_1*>(*reinterpret_cast<void* const*>(reinterpret_cast<const char*>(acc->m_enumerationStart) + (off)))

void Fighter::setSuperStar(bool a, int b, bool c) {
    soModuleAccesser* acc = this->m_moduleAccesser;

    if (c == 1) {
        u32 status = MOD(0x70)->slot16();
        u32* data = fn_27_14554C(&g_ftCommonDataAccesser, this->getFtKind(), status);
        if ((data[1] >> 29) & 1) {
            return;
        }
    }

    if (a == 1) {
        int val = soValueAccesser::getConstantInt(acc, 0x5A77, 0);
        if (b == -1) {
            b = val;
            MOD(0x5C)->slot55(0x12, 0, 0, -1);
        }
        MOD(0x64)->slot5(b, 0x1000001E);
        MOD(0x20)->slot30(b, 1, 0);
        MOD1(0x88)->slot17(0x55);

        float f[6];
        for (int i = 0; i < 6; i++) {
            f[i] = lbl_27_rodata_1048;
        }
        Object_vptr_1* obj88 = MOD1(0x88);
        soValueAccesser::getConstantFloat(acc, 0xBE9, 0);
        obj88->slot16(0x55, 0, b, &f[3], &f[0], 0);
        MOD(0x88)->slot39(0x17);
        MOD(0x88)->slot38(0x17, (float)b);
        if (MOD(0x64)->slot4(0x1000001F) == -1) {
            int t = MOD(0x50)->slot6(0x2074, 1);
            MOD(0x64)->slot5(t, 0x1000001F);
        }
        MOD(0x64)->slot18(0x1200000E, acc->m_enumerationStart);
        return;
    }

    if (MOD(0x64)->slot17(0x1200000E, acc->m_enumerationStart) == 1) {
        int t = MOD(0x64)->slot4(0x1000001F);
        if (t != -1) {
            MOD(0x50)->slot20(t, 0, acc->m_enumerationStart);
            MOD(0x64)->slot5(-1, 0x1000001F);
        }
        MOD1(0x88)->slot17(0x55);
        MOD(0x88)->slot39(0x17);
        MOD(0x64)->slot19(0x1200000E, acc->m_enumerationStart);
    }
}
