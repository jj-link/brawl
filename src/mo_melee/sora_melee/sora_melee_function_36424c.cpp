#pragma force_active on

extern "C" {
extern char lbl_27_data_91150[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int kind();
};

struct Base {
    char pad[8];
};

struct Module : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* get();
};

struct Context {
    char pad[0xd8];
    Module** module;
};

struct Target {
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
    virtual int get(int);
};

extern "C" int fn_27_364340(void*, Obj*, Context*, int);

extern "C" int fn_27_36424C(void* self, Obj* obj, Context* ctx) {
    if (obj->kind() == 13) {
        Obj* castObj = (Obj*)__dynamic_cast(
            obj, 0, lbl_27_data_91150, lbl_27_data_C938, 0);
        if (!castObj)
            return 0;

        Target* target = (Target*)__dynamic_cast(
            (*ctx->module)->get(), 0,
            lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        return fn_27_364340(self, castObj, ctx, target->get(0x1b));
    }
    return 0;
}
