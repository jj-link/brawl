#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_9C990[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
}

struct Object {
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

extern "C" int fn_27_3A313C(void*, Object*, Context*, int);

extern "C" int fn_27_3A3048(void* self, Object* obj, Context* ctx) {
    if (obj->kind() == 13) {
        Object* castObj = (Object*)__dynamic_cast(
            obj, 0, lbl_27_data_9C990, lbl_27_data_C938, 0);
        if (!castObj)
            return 0;

        Target* target = (Target*)__dynamic_cast(
            (*ctx->module)->get(), 0,
            lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        return fn_27_3A313C(self, castObj, ctx, target->get(0x23));
    }
    return 0;
}
