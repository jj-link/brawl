#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(s32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(s32);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
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
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(float);
};

struct Data {
    char pad[0x14];
    float value;
};

struct Holder {
    char pad0[0x1c];
    Object_vptr_0* motion;
    char pad1[0x64 - 0x20];
    Object_vptr_0* work;
};

struct Owner {
    char pad[0xd8];
    Holder* holder;
};

extern "C" Data* fn_27_14954C(void*, void*);
extern char g_ftCommonDataAccesser[];

extern "C" void fn_27_3A0708(s32 unused, Owner* owner) {
    Data* data = fn_27_14954C(g_ftCommonDataAccesser, owner->holder->work->slot4(0x10000009));
    float value = owner->holder->work->slot12(0x11000009);
    value = value * data->value;
    owner->holder->motion->slot48(value);
}
