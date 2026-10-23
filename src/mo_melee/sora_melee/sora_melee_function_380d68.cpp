#pragma force_active on

typedef unsigned int u32;

extern "C" void fn_27_383A44(void* self, int arg);
extern "C" void fn_27_388A44(void* out, void* a, void* b, void* c);

struct Base15 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void setA(int a, u32 b);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};

struct Mod64 : Base15 {
    virtual void setB(u32 a);
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual int query17(u32 a);
    virtual void f18();
    virtual void setD(u32 a);
};

struct Mod64F : Base15 {
    virtual void setBF(u32 a, float f);
};

struct Base36 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void call3(u32 a, void* b);
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
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
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
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
};

struct ObjB : Base36 {
    virtual void call34(u32 a, void* b);
};

struct ObjC {
    virtual void f0();
    virtual void f1();
    virtual void setC(int a);
};

struct ObjD {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int query3();
};

struct ObjE {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void call5(void* a);
};

struct Modules {
    char pad0[0x0C];
    ObjE* mE;
    char pad1[0x14 - 0x10];
    ObjD* mD;
    char pad2[0x64 - 0x18];
    Mod64* m64;
    char pad3[0x70 - 0x68];
    ObjB* mB;
    char pad4[0x84 - 0x74];
    ObjC* mC;
};

struct Obj {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Obj* obj;
};

extern "C" void fn_27_380D68(void* arg0, float* arg1, u32 arg2, u32 arg3) {
    Self* self = (Self*)arg0;
    Obj* o = self->obj;
    float sp8[3];
    o->modules->m64->setB(0x11000015);
    reinterpret_cast<Mod64F*>(o->modules->m64)->setBF(0x11000013, arg1[0]);
    reinterpret_cast<Mod64F*>(o->modules->m64)->setBF(0x11000014, arg1[1]);
    o->modules->m64->setA(7, 0x10000040);
    o->modules->mC->setC(1);
    if (arg2 == 1U) {
        if (arg3 == 1U) {
            Modules* mods = o->modules;
            ObjE* e = mods->mE;
            fn_27_388A44(sp8, (char*)arg0 + 0x7FAC, o, mods);
            e->call5(sp8);
        }
        o->modules->mB->call34(0x117, o);
    } else {
        if (o->modules->m64->query17(0x12000043) == 1U) {
            fn_27_383A44(arg0, 0);
        }
        if (o->modules->mD->query3() != 5) {
            o->modules->mB->call3(0x125, o);
        } else {
            o->modules->mB->call3(0x126, o);
        }
    }
    o->modules->m64->setD(0x12000043);
}
