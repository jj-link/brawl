#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_85BE8[];
extern char lbl_27_data_85A70[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
int fn_27_321F80(void*, int, int, int, int, int, int);
int fn_27_31EA68(void*, void*, void*, int, int, int);
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

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual int get();
};

struct Outer {
    virtual void f0();
    virtual void f1();
    virtual Inner* get();
};

struct Accesser {
    Module* module;
    char pad[0x14];
    Outer* outer;
};

struct Info {
    char pad[0x28];
    int value;
};

struct Context {
    char pad0[8];
    Info* info;
    char pad[0xd8 - 0xc];
    Accesser* acc;
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

static inline int getKind(Context* ctx) {
    Target* target = (Target*)__dynamic_cast(
        ctx->acc->module->get(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
    return target->get(6);
}

static inline void build(void* castObj, Context* ctx, int v) {
    Accesser* acc = ctx->acc;
    int value = ctx->info->value;
    fn_27_321F80(castObj, value, v, v, 1, 1, acc->outer->get()->get());
}

static inline void build13(Object* obj, Context* ctx) {
    void* castObj = __dynamic_cast(obj, 0, lbl_27_data_85BE8, lbl_27_data_C938, 0);
    build(castObj, ctx, getKind(ctx));
}

extern "C" int fn_27_31E80C(void* self, Object* obj, Context* ctx) {
    switch (obj->kind()) {
    case 13:
        build13(obj, ctx);
        return 1;
    case 14: {
        void* castObj = __dynamic_cast(obj, 0, lbl_27_data_85A70, lbl_27_data_C938, 0);
        return fn_27_31EA68(self, castObj, ctx, 0x1b8, getKind(ctx), 0x10a0001);
    }
    default:
        return 0;
    }
}
