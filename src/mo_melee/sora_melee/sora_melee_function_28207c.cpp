#include <so/so_array_vector_calculator.h>
#pragma force_active on
extern char lbl_27_data_3ED00[];

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual bool slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(int);
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
    virtual void slot26();
    virtual int slot27();
    virtual int slot28();
    void* calc;
    unsigned int flags;
};
struct Outer {
    soNullable* ptr;
    soNullable obj;
};
extern "C" Outer* fn_27_28207C(Outer* self, int size, int value) {
    bool d;
    int c;
    int b;
    int a;
    soNullable* obj = &self->obj;
    self->ptr = obj;
    *(void**)obj = lbl_27_data_3ED00;
    obj->calc = lbl_27_data_3ED00 + 0x48;
    obj->flags &= 0x01ffffff;
    a = obj->slot28();
    b = obj->slot27();
    c = obj->slot13();
    d = obj->slot14();
    bool e = obj->slot4();
    int n = soArrayVectorCalculator::resize(*reinterpret_cast<soArrayVectorCalcInterface*>(&obj->calc), size, e, d, c, b, a);
    for (int i = 0; i < n; ++i) obj->slot10(value);
    self->obj.slot13();
    return self;
}