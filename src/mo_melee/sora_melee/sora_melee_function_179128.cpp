#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

#define FIELD(o, off) (*(void**)((char*)(o) + (off)))
#define D8(s) FIELD(s, 0xd8)

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(u32);
    virtual void f5(s32, u32);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(u32, s32);
    virtual void f14();
    virtual void f15();
    virtual void f16(u32, void*, u32);
    virtual void f17();
    virtual void f18(u32);
    virtual int f19(u32);
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30(s32, u32, u32);
};

struct Locals {
    s32 a;
    u8 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    float g;
    u8 h;
};

#define VS10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
    virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

struct DynBase {
    char pad[0x3c];
};

class Dyn : public DynBase {
public:
    VS10(a0) VS10(a1) VS10(a2) VS10(a3) VS10(a4) VS10(a5) VS10(a6) VS10(a7) VS10(a8)
    VS10(a9) VS10(b0) VS10(b1) VS10(b2) VS10(b3) VS10(b4) VS10(b5) VS10(b6) VS10(b7)
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual int get();
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, void*, u32, u32);
extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
extern const float lbl_27_rodata_2338;

extern "C" void fn_27_179128(void* unused, char* self) {
    s32 v = ((Obj*)FIELD(D8(self), 0x64))->f4(0x20000000);
    Locals L;
    L.a = 11;
    L.b = 0;
    L.c = v + 4;
    L.d = -1;
    L.e = -1;
    L.f = -1;
    L.g = lbl_27_rodata_2338;
    L.h = 1;
    Dyn* R = (Dyn*)__dynamic_cast(FIELD(self, 0x8), 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    L.f = R->get();

    ((Obj*)FIELD(D8(self), 0x54))->f16(0, &L, 0);

    void* d8 = D8(self);
    Obj* b2 = (Obj*)FIELD(d8, 0x54);
    Obj* a2 = (Obj*)FIELD(d8, 0x64);
    s32 r = b2->f19(0);
    a2->f5(r, 0x20000002);

    ((Obj*)FIELD(D8(self), 0x64))->f5(L.d, 0x20000003);
    ((Obj*)FIELD(D8(self), 0x64))->f5(L.e, 0x20000004);

    if (v == 0x74) {
        ((Obj*)FIELD(D8(self), 0x60))->f13(0, -1);
    }

    ((Obj*)FIELD(D8(self), 0x64))->f18(0x12000029);
    ((Obj*)FIELD(D8(self), 0x64))->f19(0x1200001A);

    Obj* D = (Obj*)FIELD(D8(self), 0x20);
    s32 k = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, (void*)0x5a2e, 0, (u32)D8(self));
    D->f30(k, 0, 0);
}
