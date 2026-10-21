#pragma force_active on
#include <types.h>

class Obj1 {
public:
    virtual void slot0();
    virtual void* slot1();
};

class Obj3 {
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
    virtual void slot20(void*, void*, void*);
};

struct Head {
    char pad[8];
};

class Self : public Head {
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
    virtual Obj3* slot39();

    char pad[0x3C - 0xC];
    void* unk3C;         // 0x3C
    Obj1* obj1;          // 0x40
    char pad2[0xBC - 0x44];
    char unkBC[0x101 - 0xBC];
    u8 flags;            // 0x101
};

extern "C" void fn_27_61654(Self* self) {
    void* temp = self->obj1->slot1();
    self->flags = self->flags & ~0x20;
    Obj3* result = self->slot39();
    result->slot20(self->unk3C, temp, (void*)self->unkBC);
}
