#include <types.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_20D8;

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
    virtual f32 slot12();
    virtual void slot13(u32 id, f32 v);
    virtual void slot14();
    virtual f32 slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18(u32 id);
    virtual void slot19(u32 id);
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
    virtual void slot39(int v);
};

struct Modules {
    char pad0[0x8];
    Object_vptr_0* motion;
    char pad1[0x58];
    Object_vptr_0* work;
    char pad2[0x8];
    Object_vptr_0* status;
    char pad3[0x14];
    Object_vptr_0* effect;
};

struct Obj {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_1696D0(void* unused, Obj* obj, int kind) {
    int status = obj->modules->status->slot16();
    u32 flag = 0;
    switch (status) {
    case 0x2b:
    case 0x2e:
    case 0x31:
    case 0xa2:
        flag = 1;
        break;
    }
    switch (kind) {
    case 0x2c:
    case 0x2f:
    case 0x32:
    case 0xa1:
        if (flag == 1) {
            f32 f = obj->modules->motion->slot12();
            f32 g = obj->modules->motion->slot15();
            f32 r = lbl_27_rodata_20D8;
            if (g > lbl_27_rodata_20D8) {
                r = f / g;
            }
            obj->modules->work->slot13(0x21000000, r);
            obj->modules->work->slot18(0x22000003);
        } else {
            obj->modules->work->slot13(0x21000000, lbl_27_rodata_20D8);
            obj->modules->work->slot19(0x22000003);
        }
        break;
    }
    if (flag == 1) {
        obj->modules->effect->slot39(0x19);
    }
}
