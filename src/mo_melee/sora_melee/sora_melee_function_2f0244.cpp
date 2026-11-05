#pragma force_active on
class soNullable {
public:
    virtual void isNull();
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
    virtual int slot16(int, void*);
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
    virtual void slot34(int, void*);
};
struct Modules {
    char pad[0x70];
    soNullable* state;
};
struct Owner {
    char pad[0xD8];
    Modules* modules;
};
struct Object {
    char pad[0x60];
    Owner* owner;
    char pad2[0x40];
    unsigned char flags;
};
extern "C" int fn_27_1DAF80(Object*, int);
extern "C" int fn_27_2F0244(Object* self, int arg) {
    switch (self->owner->modules->state->slot16(arg, self->owner)) {
    case 0:
        if (arg & 0x13) {
            self->owner->modules->state->slot34(1, self->owner);
            return 0;
        }
        if ((arg & 4) && (((unsigned int)self->flags >> 7) & 1) != 1) {
            self->owner->modules->state->slot34(1, self->owner);
            return 0;
        }
        break;
    }
    return fn_27_1DAF80(self, arg);
}