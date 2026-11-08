#include <types.h>
#pragma force_active on

struct Data {
    u32 a0;
    f32 x;
    f32 y;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
};

class Obj {
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
    virtual Data* slot26();
};

class ObjArg {
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
    virtual Data* slot26(int arg);
};

extern "C" void fn_27_1EE58(Obj* self, int unused, int arg) {
    Data* temp_r31 = self->slot26();
    Data* temp_r3 = ((ObjArg*)self)->slot26(arg);
    if (temp_r3 != temp_r31) {
        temp_r3->a0 = temp_r31->a0;
        temp_r3->x = temp_r31->x;
        temp_r3->y = temp_r31->y;
        temp_r3->b0 = temp_r31->b0;
        temp_r3->b1 = temp_r31->b1;
        temp_r3->b2 = temp_r31->b2;
        temp_r3->b3 = temp_r31->b3;
    }
}
