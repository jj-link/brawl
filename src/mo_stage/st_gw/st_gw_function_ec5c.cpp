#pragma force_active on
typedef unsigned int u32;
struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};
struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };
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
class Class_3138 {
public:
    virtual void fn_63_D57C();
    virtual Element* fn_63_CA44(int);
    virtual void fn_63_CA54();
    virtual int fn_63_AF3C();
};
class Class_34E0 {
public:
    virtual void fn_63_EF70();
    virtual Element* fn_63_E390(int);
    virtual void fn_63_E3A0();
    virtual int fn_63_B09C();
};
class Class_47D8 {
public:
    virtual void fn_63_EF70();
    virtual Element* fn_63_E390(int);
    virtual void fn_63_E3A0();
    virtual int fn_63_10B3C();
};
class Class_4D30 {
public:
    virtual void fn_63_D57C();
    virtual Element* fn_63_CA44(int);
    virtual void fn_63_CA54();
    virtual int fn_63_11FB4();
};
extern "C" void fn_63_EC5C(Class_34E0* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_63_B09C()) {
        count = self->fn_63_B09C() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_63_E390(index + i) = *value;
    }
}