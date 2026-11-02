#pragma force_active on

typedef unsigned int u32;

struct Base1 {
    virtual void dummy1();
};

struct Base2 {
    virtual void dummy2();
};

struct Pair {
    u32 a, b;

    Pair& operator=(const Pair& rhs) {
        a = rhs.a;
        b = rhs.b;
        return *this;
    }
};

struct Nested : Base1, Base2 {
    u32 b0;
    Pair pairs[6];
};

struct Element {
    u32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    Nested nested;
    unsigned char f0, f1;
};

class soNullable {
public:
    virtual void isNull();          // 0x08
    virtual void slot1();           // 0x0c
    virtual void slot2();           // 0x10
    virtual int slot3();            // 0x14 (size)
    virtual void slot4();           // 0x18
    virtual void slot5();           // 0x1c
    virtual void slot6();           // 0x20
    virtual void slot7();           // 0x24
    virtual void slot8();           // 0x28
    virtual void slot9();           // 0x2c
    virtual void slot10();          // 0x30
    virtual void slot11();          // 0x34
    virtual void slot12();          // 0x38
    virtual int slot13();           // 0x3c (v3c)
    virtual bool slot14();          // 0x40 (v40)
    virtual void slot15();          // 0x44
    virtual void slot16();          // 0x48
    virtual void slot17();          // 0x4c
    virtual void slot18();          // 0x50
    virtual void slot19();          // 0x54
    virtual void slot20();          // 0x58
    virtual void slot21();          // 0x5c
    virtual void slot22();          // 0x60
    virtual void slot23();          // 0x64
    virtual void slot24();          // 0x68
    virtual void slot25();          // 0x6c
    virtual Element* slot26(int);   // 0x70 (at)
    virtual int slot27();           // 0x74 (v74)
    virtual int slot28();           // 0x78 (v78)
    virtual void slot29(int);       // 0x7c (setSize)
};

extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
    void*, int, bool, int, int, int, int);

extern "C" void fn_27_E7C5C(soNullable* self, int index, const Element* value) {
    int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(
        (char*)self + 4, index, self->slot14(), self->slot3(),
        self->slot13(), self->slot27(), self->slot28());
    *self->slot26(pos) = *value;
    self->slot29(self->slot3() + 1);
}
