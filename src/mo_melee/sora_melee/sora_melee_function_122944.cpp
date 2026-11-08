#pragma force_active on
extern "C" void erase__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelllll(
    void*, int, int, int, int, int);

class Object {
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

extern "C" void fn_27_122944(Object* self, int index) {
    int d, c, b, a;
    a = self->slot28();
    b = self->slot27();
    c = self->slot13();
    d = self->slot3();
    erase__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelllll(
        &self->calc, index, d, c, b, a);
    self->slot29(self->slot3() - 1);
}
