#include <types.h>
#pragma force_active on

extern "C" char lbl_114_data_8460[];
extern "C" char lbl_114_data_84E4[];
extern "C" const float lbl_114_rodata_A0;
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

struct Pad8 {
    int a;
    int b;
};

struct PolyA : Pad8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void setAt28(int x, float f);
};

struct PolyObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void setVec(float* v, int x);
};

extern "C" void fn_114_125B8(void*, char* self) {
    char* a = *(char**)(self + 0xd8);
    void* base = *(void**)(a + 4);
    PolyA* target = static_cast<PolyA*>(__dynamic_cast(base, 8, lbl_114_data_8460, lbl_114_data_84E4, 1));
    target->setAt28(3, lbl_114_rodata_A0);

    char* c = *(char**)(self + 0xd8);
    PolyObj* o = *(PolyObj**)(c + 0xc);
    float v[3];
    v[0] = lbl_114_rodata_A0;
    v[1] = lbl_114_rodata_A0;
    v[2] = lbl_114_rodata_A0;
    o->setVec(v, 0);
}
