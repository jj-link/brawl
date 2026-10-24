#include <types.h>
#pragma force_active on

struct Data {
    s32 a, b, c, d;
    f32 e;
    s32 f, g, h, i;
    f32 j, k, l;
    u32 m;
    s32 n, o, p;

    Data(const Data& x)
        : a(x.a), b(x.b), c(x.c), d(x.d), e(x.e),
          f(x.f), g(x.g), h(x.h), i(x.i),
          j(x.j), k(x.k), l(x.l), m(x.m),
          n(x.n), o(x.o), p(x.p) {}
};

struct Result {
    s32 valid;
    Data data;
};

class StateSource {
public:
    virtual void vf0();
    virtual Result* get();
};

class Source {
public:
    virtual void vf0();
    virtual Result* get(s32);
};

struct Vec {
    f32 x, y, z;

    Vec() {}

    void set(f32 a, f32 b, f32 c) {
        x = a;
        y = b;
        z = c;
    }

    Vec(f32 a, f32 b, f32 c) : x(a), y(b), z(c) {}
};

struct Matrix {
    f32 v[3][4];
};

struct TargetBase {
    s32 a, b;
};

class Target : public TargetBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void calc(u32, s32, Matrix*, s32);
};

class Main {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual s32 set(s32, Vec*);
};

inline void makeMatrix(u8* self, Result* result, s32 arg, Vec* vec) {
    Matrix matrix;
    Data local = result->data;
    void* parent = *(void**)(self + 0x28);
    void* mgr = *(void**)((u8*)parent + 0xd8);
    Target* target = *(Target**)((u8*)mgr + 4);

    target->calc(local.m >> 23, arg, &matrix, 0);
    vec->set(matrix.v[0][3], matrix.v[1][3], matrix.v[2][3]);
}

extern "C" s32 fn_27_3ADDC(u8* self, s32 arg1, s32 arg2) {
    Result* result = (*(StateSource**)(self + 0x30))->get();
    if (result->valid == 0) {
        return 0;
    }

    result = (*(Source**)(self + 0x30))->get(arg1);
    Vec vec;
    makeMatrix(self, result, arg2, &vec);
    return ((Main*)self)->set(arg1, &vec);
}
