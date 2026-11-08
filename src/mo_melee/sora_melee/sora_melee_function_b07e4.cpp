#pragma force_active on

struct Item {
    int a;
    int b;
    char c;
    char d;
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
    virtual Item* slot26(int);
    virtual int slot27();
    virtual int slot28();
    virtual void slot29(int);
    int calc;
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, void*, int, int, int, int, int);

extern "C" void fn_27_B07E4(Object_vptr_0* self, void* iface, const Item* src) {
    int d, c, b, a;
    a = self->slot28();
    b = self->slot27();
    c = self->slot13();
    d = self->slot3();
    int e = self->slot14();
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        &self->calc, iface, e, d, c, b, a);
    Item* dst = self->slot26(pos);
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    self->slot29(self->slot3() + 1);
}
