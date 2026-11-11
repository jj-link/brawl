#include <types.h>
#pragma force_active on

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void getAppearTask();  // offset 0x178
};

struct Data {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
    unsigned int w5;
    unsigned int w6;
    unsigned short h0;
    unsigned short h1;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char b10;
    Data(const Data& d)
        : w0(d.w0), w1(d.w1), w2(d.w2), w3(d.w3), w4(d.w4), w5(d.w5), w6(d.w6),
          h0(d.h0), h1(d.h1),
          b0(d.b0), b1(d.b1), b2(d.b2), b3(d.b3), b4(d.b4), b5(d.b5), b6(d.b6),
          b7(d.b7), b8(d.b8), b9(d.b9), b10(d.b10) {}
};

struct Object {
    char pad[0x70];
    Object_vptr_3c* task;
    f32 value;
    Data data;
};

extern "C" void fn_27_263B1C(Object* dst, const Data* src, f32 value) {
    if (dst->value < value) {
        dst->data.w0 = src->w0;
        dst->data.w1 = src->w1;
        dst->data.w2 = src->w2;
        dst->data.w3 = src->w3;
        dst->data.w4 = src->w4;
        dst->data.w5 = src->w5;
        dst->data.w6 = src->w6;
        dst->data.h0 = src->h0;
        dst->data.h1 = src->h1;
        dst->data.b0 = src->b0;
        dst->data.b1 = src->b1;
        dst->data.b2 = src->b2;
        dst->data.b3 = src->b3;
        dst->data.b4 = src->b4;
        dst->data.b5 = src->b5;
        dst->data.b6 = src->b6;
        dst->data.b7 = src->b7;
        dst->data.b8 = src->b8;
        dst->data.b9 = src->b9;
        dst->data.b10 = src->b10;
        dst->value = value;
    }
    dst->task->getAppearTask();
}
