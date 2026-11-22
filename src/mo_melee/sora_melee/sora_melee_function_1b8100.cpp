#include <so/so_array_vector_calculator.h>
#pragma force_active on

struct Data {
    unsigned char b04;
    int w08, w0C, w10, w14, w18, w1C, w20, w24, w28, w2C,
        w30, w34, w38, w3C, w40, w44, w48, w4C, w50, w54;
    unsigned char c58[34];
    unsigned char c7A[16];
};

struct Item {
    long hdr;
    Data data;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
    virtual bool slot14();
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
    virtual Item* slot26(int);
    virtual int slot27();
    virtual int slot28();
    virtual void slot29(int);
};

extern "C" void fn_27_1B8100(Object_vptr_0* self, const Item* value) {
    self->slot26(soArrayVectorCalculator::push(
        *reinterpret_cast<soArrayVectorCalcInterface*>(reinterpret_cast<char*>(self) + 4),
        self->slot14(), self->slot13(), self->slot27(), self->slot28()))->data = value->data;
    self->slot29(self->slot3() + 1);
}