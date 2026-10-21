#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_9AB98[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
int fn_27_395E34(void*, void*, void*, unsigned int);
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
    virtual unsigned int get(int);
};

extern "C" int fn_27_395D40(void* self, Object* obj, Context* ctx) {
    if (obj->kind() == 13) {
        void* castObj = __dynamic_cast(
            obj, 0, lbl_27_data_9AB98, lbl_27_data_C938, 0);
        if (!castObj)
            return 0;

        Target* target = (Target*)__dynamic_cast(
            (*ctx->module)->get(), 0,
            lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        return fn_27_395E34(self, castObj, ctx, target->get(0x20));
    }
    return 0;
}
