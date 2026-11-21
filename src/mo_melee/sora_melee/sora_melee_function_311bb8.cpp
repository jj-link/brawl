#pragma force_active on

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
    virtual int slot16();
};

class Object_vptr_84 {
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
    virtual void slot16(int a, int b);
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual int slot40();
};

struct Holder {
    char pad0[0x70];
    Object_vptr_0* unk70;
    char pad1[0x10];
    Object_vptr_84* unk84;
};

struct Owner {
    char pad0[8];
    Object_vptr_3c* unk8;
    char pad1[0xD8 - 0xC];
    Holder* unkD8;
};

inline int adjust(Owner* owner, int value) {
    if (value <= 0x116) {
        return value;
    }
    switch (owner->unk8->slot40()) {
    case 0x2c:
    case 0x6:
        return value;
    case 0x13:
        value += 3;
        break;
    default:
        break;
    }
    return value;
}

extern "C" void fn_27_311BB8(void* unused, Owner* arg1, int arg2) {
    int r31 = adjust(arg1, arg1->unkD8->unk70->slot16());
    if (r31 != 0x11F) {
        arg2 = adjust(arg1, arg2);
        if (arg2 != 0x11D && arg2 != 0x11E && arg2 != 0x11F) {
            arg1->unkD8->unk84->slot16(3, 0);
        }
    }
}
