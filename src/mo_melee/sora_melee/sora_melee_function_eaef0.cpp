#include <so/so_array_vector_calculator.h>
#pragma force_active on

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
    virtual int slot27();
    virtual int slot28();
    virtual void slot29(int);
    int calc;
};

extern "C" void fn_27_EAEF0(soNullable* self, int index) {
    soArrayVectorCalculator::erase(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc),
        index, self->slot3(), self->slot13(), self->slot27(), self->slot28());
    self->slot29(self->slot3() - 1);
}
