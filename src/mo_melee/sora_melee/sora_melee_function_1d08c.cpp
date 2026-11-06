#include <so/so_array_vector_calculator.h>
#pragma force_active on

struct Elem {
    unsigned int a;
    float b, c;
    unsigned char d, e, f, g;
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
    virtual Elem* slot26(int);
    virtual int slot27();
    virtual int slot28();
    virtual void slot29(int);
    int calc;
};

extern "C" void fn_27_1D08C(Object_vptr_0* self, const Elem* value) {
    Elem* dest = self->slot26(soArrayVectorCalculator::push(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc),
        self->slot14(), self->slot13(), self->slot27(), self->slot28()));
    if (dest != value) {
        dest->a = value->a;
        dest->b = value->b;
        dest->c = value->c;
        dest->d = value->d;
        dest->e = value->e;
        dest->f = value->f;
        dest->g = value->g;
    }
    self->slot29(self->slot3() + 1);
}