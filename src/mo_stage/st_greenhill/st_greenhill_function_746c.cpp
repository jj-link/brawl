#pragma force_active on
typedef unsigned int u32;
struct Pair { u32 a, b; Pair& operator=(const Pair& rhs) { a = rhs.a; b = rhs.b; return *this; } };
struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };
struct Nested : Base1, Base2 { u32 b0; Pair pairs[6]; };
struct Element { u32 a0,a1,a2,a3,a4,a5,a6,a7,a8,a9; Nested nested; unsigned char f0,f1; };
class Class_15E0 { public: virtual void fn_72_7748(); virtual Element* fn_72_6C10(int); virtual void fn_72_6C20(); virtual int fn_72_5108(); };
class Class_1888 { public: virtual void fn_72_913C(); virtual Element* fn_72_855C(int); virtual void fn_72_856C(); virtual int fn_72_5268(); };
class Class_3028 { public: virtual void fn_72_7748(); virtual Element* fn_72_6C10(int); virtual void fn_72_6C20(); virtual int fn_72_BF34(); };
class Class_33D0 { public: virtual void fn_72_913C(); virtual Element* fn_72_855C(int); virtual void fn_72_856C(); virtual int fn_72_BFCC(); };
extern "C" void fn_72_746C(Class_15E0* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_72_5108()) count = self->fn_72_5108() - index;
    for (int i = 0; i < count; ++i) *self->fn_72_6C10(index + i) = *value;
}