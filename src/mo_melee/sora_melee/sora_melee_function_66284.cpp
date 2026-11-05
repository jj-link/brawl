#include <types.h>
#pragma force_active on

class ObjA {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6(void* p);
};

class ObjB {
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
    virtual unsigned int slot9(int p);
    virtual unsigned int slot10(int p);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual int slot19(int p);
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
    virtual int slot42(int p);
};

struct Mods {
    char pad0[0x3c];
    ObjA* a;
    char pad1[0x54 - 0x40];
    ObjB* b;
};

struct Mid {
    char pad[0xd8];
    Mods* mods;
};

struct Outer {
    char pad[0x10];
    Mid* mid;
};

extern "C" int fn_27_66284(Outer* self) {
    if (self->mid->mods->a->slot6(self->mid) == 0) {
        if (self->mid->mods->b->slot10(0) == 1) {
            return self->mid->mods->b->slot19(0);
        }
        if (self->mid->mods->b->slot9(0) == 1) {
            return self->mid->mods->b->slot42(0);
        }
    }
    return -1;
}
