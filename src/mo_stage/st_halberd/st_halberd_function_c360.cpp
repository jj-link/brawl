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
class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual Element* fn_57_BA94(int);
    virtual void fn_57_BAA4();
    virtual int fn_57_ADD8();
};
extern "C" void fn_57_C360(Class_2110* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_57_ADD8()) {
        count = self->fn_57_ADD8() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_57_BA94(index + i) = *value;
    }
}
