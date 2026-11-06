#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void fn_41_34E68();
    virtual void fn_41_34AE8();
    virtual void fn_41_34B18();
    virtual void fn_41_34C38();
};

struct Owner;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int, Owner*, float);
    virtual void slot5();
    virtual void slot6(int, Owner*, int, float);
};

struct Accesser {
    char pad[0x6C];
    Object_vptr_0* module;
};

struct Owner {
    char pad[0xD8];
    Accesser* accesser;
};

struct Param {
    char pad[0x30];
    unsigned int flags;
};

extern float lbl_41_rodata_E78;

extern "C" void fn_41_34C38(void*, Owner* owner, int value, Param* param) {
    switch (param->flags & 0x1F) {
    case 5:
        owner->accesser->module->slot6(6, owner, value + 3, lbl_41_rodata_E78);
        break;
    case 3:
        owner->accesser->module->slot6(6, owner, value + 7, lbl_41_rodata_E78);
        break;
    case 19:
        owner->accesser->module->slot6(6, owner, value + 11, lbl_41_rodata_E78);
        break;
    case 21:
        owner->accesser->module->slot6(6, owner, value + 15, lbl_41_rodata_E78);
        break;
    default:
        owner->accesser->module->slot6(6, owner, 0, lbl_41_rodata_E78);
        break;
    }
    owner->accesser->module->slot4(6, owner, lbl_41_rodata_E78);
}
