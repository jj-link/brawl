#pragma force_active on

typedef unsigned int u32;

struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& p) {
        a = p.a;
        b = p.b;
        return *this;
    }
};

struct Base1 {
    virtual void dummy1();
};

struct Base2 {
    virtual void dummy2();
};

struct Nested : Base1, Base2 {
    u32 u4c;
    Pair pairs[7];
    u32 u88, u8c;
};

struct Element {
    u32 u00, u04, u08, u0c, u10;
    float f14;
    u32 u18, u1c, u20, u24;
    float f28, f2c, f30;
    u32 u34, u38, u3c, u40;
    Nested nested;
};

class Class_3E50 {
public:
    virtual void fn_73_C58C();
    virtual Element* fn_73_B9AC(int);
    virtual void fn_73_B9BC();
    virtual int fn_73_A9C8();
};

class Class_3F48 {
public:
    virtual void fn_73_C58C();
    virtual Element* fn_73_B9AC(int);
    virtual void fn_73_B9BC();
    virtual int fn_73_AA60();
};

class Class_4040 {
public:
    virtual void fn_73_C58C();
    virtual Element* fn_73_B9AC(int);
    virtual void fn_73_B9BC();
    virtual int fn_73_AAF8();
};

class Class_4138 {
public:
    virtual void fn_73_C58C();
    virtual Element* fn_73_B9AC(int);
    virtual void fn_73_B9BC();
    virtual int fn_73_AB90();
};

class Class_4400 {
public:
    virtual void fn_73_C58C();
    virtual Element* fn_73_B9AC(int);
    virtual void fn_73_B9BC();
    virtual int fn_73_ACF0();
};

extern "C" void fn_73_C278(Class_3E50* self, int index,
                           const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_73_A9C8()) {
        count = self->fn_73_A9C8() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_73_B9AC(index + i) = *value;
    }
}
