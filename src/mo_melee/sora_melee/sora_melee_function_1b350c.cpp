#include <so/so_array_vector_calculator.h>
#pragma force_active on

struct Item {
    int a, b;
    float c;
    int d;
    unsigned char flag() const { return ((const unsigned char*)this)[13]; }
};

class soNullable {
public:
    virtual void isNull();
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

extern "C" void fn_27_1B350C(soNullable* self, int index, const Item* src) {
    int pos = soArrayVectorCalculator::insert(
        *(soArrayVectorCalcInterface*)((char*)self + 4), index,
        self->slot14(), self->slot3(), self->slot13(), self->slot27(), self->slot28());
    Item* dst = self->slot26(pos);
    *dst = *src;
    ((unsigned char*)dst)[13] = src->flag();
    self->slot29(self->slot3() + 1);
}