#pragma force_active on
#include <so/so_array_vector_calculator.h>
extern "C" int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, void*, int, int, int, int, int);
extern char lbl_27_data_19EE0[];
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(int);
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
    virtual int slot14();
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
    void* p4;
    unsigned int f8;
};
extern "C" void* fn_27_D334C(Object_vptr_0* self, void* a, int arg2) {
    *(void**)self = lbl_27_data_19EE0;
    self->p4 = lbl_27_data_19EE0 + 0x48;
    self->f8 &= 0x3FFFFF;
    int n = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&self->p4, a, self->slot4(), self->slot14(), self->slot13(), self->slot27(), self->slot28());
    for (int i = 0; i < n; i++) self->slot10(arg2);
    return self;
}