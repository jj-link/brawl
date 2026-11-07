#include <types.h>
#pragma force_active on

class Object_vptr_0;
class Object_vptr_8;

struct Modules {
    char pad[0x10];
    Object_vptr_8* m10;
    char pad2[0x44 - 0x14];
    Object_vptr_0* m44;
};

struct Mid {
    char pad[0xd8];
    Modules* modules;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();

    char pad[0x28 - 4];
    Mid* mid;
    int state;
    char pad2[0x38 - 0x30];
    unsigned char flags;
};

struct Prefix { char pad[8]; };
class Object_vptr_8 : public Prefix {
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
    virtual int slot34(int);
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
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual int slot55(int, int);
};

extern "C" void fn_27_35834(Object_vptr_0* self) {
    if (((self->flags >> 7) & 1) != 1U) {
        if (self->state == 1) {
            if (self->mid->modules->m10->slot34(0) == 0) {
                if (self->mid->modules->m10->slot55(8, 0) == 1U) {
                    self->slot6(0, 0);
                    return;
                }
                self->slot6(2, 0);
            }
        } else {
            if (self->mid->modules->m10->slot55(8, 0) == 1U) {
                if (self->mid->modules->m10->slot34(0) == 0) {
                    if (self->state == 2 &&
                        (self->mid->modules->m44->slot9() == 1U || ((self->flags >> 6) & 1) == 1U)) {
                        self->slot6(2, 0);
                        return;
                    }
                    self->slot6(0, 0);
                    return;
                }
            }
            if (self->state != 6) {
                self->slot6(2, 0);
            }
        }
    }
}
