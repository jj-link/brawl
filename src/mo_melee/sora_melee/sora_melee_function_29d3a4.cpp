#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_2A06AC();
    virtual void fn_27_281B1C();
    virtual void fn_27_2839BC();
    virtual void fn_27_284EA0();
    virtual void fn_27_289454();
    virtual void fn_27_289FAC();
    virtual void fn_27_28A178();
    virtual void fn_27_28A1C4();
    virtual void fn_27_28A4F4();
    virtual void fn_27_289518();
    virtual void fn_27_289560();
    virtual void fn_27_28903C();
    virtual void fn_27_287730();
    virtual void fn_27_29D4C4();
    virtual void fn_27_28BBA0();
    virtual int fn_27_28BDA8();
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int);
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
};
struct StateHolder { char pad[0x70]; soNullable* state; };
struct ModuleHolder { char pad[0x1c]; Object_vptr_0* object; };
struct Modules { char pad[0xd8]; ModuleHolder* holder; };
struct Fighter {
    char pad[0x60];
    Modules* modules;
    char pad2[0x1a4 - 0x64];
    StateHolder* stateHolder;
};
extern "C" void fn_27_29D3A4(void*, Fighter* self, int id) {
    if (self->stateHolder->state->fn_27_28BDA8() == 2) {
        switch (id) {
        case 1:
            self->modules->holder->object->slot6(0);
            break;
        case 2:
            self->modules->holder->object->slot6(1);
            break;
        }
    }
}
