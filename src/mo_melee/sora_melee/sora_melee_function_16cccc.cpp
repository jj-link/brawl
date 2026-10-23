#pragma force_active on

typedef unsigned int u32;

struct Vec2 {
    float x;
    float y;
};

struct Vec2Src {
    virtual void f0();
    virtual void f1();
    virtual Vec2 v4();
};

struct Sub7C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual Vec2Src* v8(int);
};

struct Sub14 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int v5();
};

struct Work {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int v6(u32);
    virtual void v7(int, u32);
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
    virtual int v19(u32);
    virtual void v20(u32);
};

struct Sub70 {
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
    virtual int v34(int);
};

struct Sub88 {
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
    virtual void v15(int);
};

struct Modules {
    char pad0[0x14];
    Sub14* p14;
    char pad1[0x64 - 0x18];
    Work* work;
    char pad2[0x70 - 0x68];
    Sub70* p70;
    char pad3[0x7c - 0x74];
    Sub7C* p7c;
    char pad4[0x88 - 0x80];
    Sub88* p88;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_16B950(void*, Object* object);
extern "C" void fn_27_16CEC4(void*, Object* object);
extern "C" void* fn_27_195788(void*);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);
extern "C" float rsqrtf__Ff(float);
extern "C" float lbl_27_rodata_21A4;
extern "C" float lbl_27_rodata_21A8;

extern "C" void fn_27_16CCCC(void* arg0, Object* object) {
    fn_27_16B950(arg0, object);
    int r31 = object->modules->work->v6(0x20000000);
    if (r31 != -1) {
        float f31 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(object, 0xcd1, 0);
        Vec2 v = object->modules->p7c->v8(4)->v4();
        float fx = v.x;
        float fy = v.y;
        float f30 = fx * fx + fy * fy;
        float f0;
        if ((float)__fabs(f30) <= lbl_27_rodata_21A8) {
            f0 = lbl_27_rodata_21A4;
        } else {
            f0 = f30 * rsqrtf__Ff(f30);
        }
        if (f0 < f31) {
            object->modules->p88->v15(r31);
            object->modules->work->v7(-1, 0x20000000);
        }
    }
    fn_27_195788(object);
    if (object->modules->work->v19(0x22000017) == 0) {
        object->modules->work->v20(0x22000017);
        if (object->modules->p14->v5() == 2) {
            if (object->modules->p70->v34(0) != 0xC1) {
                fn_27_16CEC4(arg0, object);
            }
        }
    }
}
