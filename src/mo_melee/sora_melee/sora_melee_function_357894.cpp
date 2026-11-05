#pragma force_active on
#include <so/work/so_work_manage_module_impl.h>

class soNullableSlots {
public:
    virtual void isNull();            // offset 0x8
    virtual void slot1();             // offset 0xc
    virtual void slot2();             // offset 0x10
    virtual void slot3();             // offset 0x14
    virtual void slot4();             // offset 0x18
    virtual void slot5();             // offset 0x1c
    virtual void slot6();             // offset 0x20
    virtual void slot7();             // offset 0x24
    virtual void slot8();             // offset 0x28
    virtual void slot9();             // offset 0x2c
    virtual void slot10();            // offset 0x30
    virtual void slot11();            // offset 0x34
    virtual void slot12();            // offset 0x38
    virtual void slot13();            // offset 0x3c
    virtual int slot14(int index);    // offset 0x40
    virtual int slot15(int index);    // offset 0x44
    virtual void slot16();            // offset 0x48
    virtual void slot17();            // offset 0x4c
    virtual void slot18();            // offset 0x50
    virtual void slot19();            // offset 0x54
    virtual void slot20();            // offset 0x58
    virtual void slot21(void* out, int index);  // offset 0x5c
};

struct FtModules {
    char pad0[0x64];
    soWorkManageModule* work;   // 0x64
    char pad1[0x40];
    soNullableSlots* item;      // 0xa8
};

struct FtOwner {
    char pad[0xd8];
    FtModules* modules;         // 0xd8
};

extern "C" void fn_27_357894(void* unused, FtOwner* fighter) {
    u32 buf[8];
    FtModules* mods = fighter->modules;
    soWorkManageModule* work = mods->work;
    soNullableSlots* item = mods->item;
    int flag29 = 0;
    int flag28 = 0;
    int flag27 = 0;
    for (int i = 3; i < 7; i++) {
        if (item->slot14(i) != 0) {
            item->slot21(buf, i);
            if (item->slot15(i) == 1) {
                flag29 = 1;
            }
            if (buf[2] & 0x8000) {
                flag27 = 1;
            }
            if (buf[2] & 0x2000) {
                flag28 = 1;
            }
        }
    }
    if (flag27 != 0) {
        work->setInt(0x11E, 0x20000005);
    } else if (flag29 != 0) {
        work->setInt(0x11F, 0x20000005);
    } else if (flag28 != 0) {
        work->setInt(0x11D, 0x20000005);
    } else {
        work->setInt(0x120, 0x20000005);
    }
}
