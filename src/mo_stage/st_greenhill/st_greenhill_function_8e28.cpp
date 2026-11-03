#pragma force_active on
typedef unsigned int u32;
struct Pair { u32 a, b; Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; } };
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
class Class_15E0 {
public:
    virtual void fn_72_7748();
    virtual Element* fn_72_6C10(int);
    virtual void fn_72_6C20();
    virtual int fn_72_5108();
};
class Class_1888 {
public:
    virtual void fn_72_913C();
    virtual Element* fn_72_855C(int);
    virtual void fn_72_856C();
    virtual int fn_72_5268();
};
class Class_3028 {
public:
    virtual void fn_72_7748();
    virtual Element* fn_72_6C10(int);
    virtual void fn_72_6C20();
    virtual int fn_72_BF34();
};
class Class_33D0 {
public:
    virtual void fn_72_913C();
    virtual Element* fn_72_855C(int);
    virtual void fn_72_856C();
    virtual int fn_72_BFCC();
};
extern "C" void fn_72_8E28(Class_1888* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_72_5268()) {
        count = self->fn_72_5268() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_72_855C(index + i) = *value;
    }
}