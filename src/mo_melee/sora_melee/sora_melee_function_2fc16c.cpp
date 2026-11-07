#include <ft/ft_common_data_accesser.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
}
class ModuleSlots {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned long);
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
    virtual void slot16(int, int);
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
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
    virtual void slot39(int);
};
struct FighterTask_base { char pad[0x3c]; };
class FighterTask : public FighterTask_base {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual void fn_27_248088();
    virtual int slot40();
};
struct Modules {
    char pad[0x64];
    ModuleSlots* work;
    char pad2[0x1c];
    ModuleSlots* motion;
    ModuleSlots* status;
};
struct Accesser {
    char pad[8];
    FighterTask* fighter;
    char pad2[0xcc];
    Modules* modules;
};
extern "C" void fn_27_2FC16C(void*, Accesser* accesser, int status) {
    if (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1) != 0x11c) {
        accesser->modules->work->slot5(0, 0x10000041);
        int motion;
        if (accesser->fighter->slot40() == 5)
            motion = 13;
        else
            motion = *(int*)((char*)g_ftCommonDataAccesser.getData((ftKind)3) + 0x98);
        accesser->modules->motion->slot16(motion, 0);
        accesser->modules->status->slot39(26);
    }
}
