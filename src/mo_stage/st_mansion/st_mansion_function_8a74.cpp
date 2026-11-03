#pragma force_active on
struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};
struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };
struct Nested : Base1, Base2 {
    unsigned int u4c;
    Pair pairs[7];
    unsigned int u88, u8c;
};
struct Element {
    unsigned int u00, u04, u08, u0c, u10;
    float f14;
    unsigned int u18, u1c, u20, u24;
    float f28, f2c, f30;
    unsigned int u34, u38, u3c, u40;
    Nested nested;
};
class Class_1640 {
public:
    virtual void fn_47_7394();
    virtual Element* fn_47_685C(int);
    virtual void fn_47_686C();
    virtual int fn_47_4D54();
};
class Class_18E8 {
public:
    virtual void fn_47_8D88();
    virtual Element* fn_47_81A8(int);
    virtual void fn_47_81B8();
    virtual int fn_47_4EB4();
};
extern "C" void fn_47_8A74(Class_18E8* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_47_4EB4()) {
        count = self->fn_47_4EB4() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_47_81A8(index + i) = *value;
    }
}