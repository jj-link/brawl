#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_89120[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
void fn_27_33647C(void*, int, int, int, float);
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

struct Mid : Base {
    virtual void f0();
    virtual void f1();
    virtual void* get4();
    virtual void f3();
    virtual void* get6();
};

struct Mid2 {
    virtual void f0();
    virtual void f1();
    virtual void* get4();
};

struct Ret {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float get11();
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

struct Inner {
    char pad[0x28];
    int v;
};

struct Ctx {
    char pad[8];
    Inner* inner;
    char pad2[0xcc];
    char* holder;
};

extern "C" int fn_27_3315D0(void* self, Obj* obj, Ctx* ctx) {
    if (obj->kind() == 13) {
        obj = (Obj*)__dynamic_cast(obj, 0, lbl_27_data_89120, lbl_27_data_C938, 0);
        if (!obj) {
            return 0;
        }
        Target* t = (Target*)__dynamic_cast(((Mid*)*(void**)ctx->holder)->get6(), 0,
                                            lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        int r31 = t->get(0xc);
        Ret* ret = *(Ret**)(ctx->holder + 0xc);
        Mid2* m2 = *(Mid2**)(ctx->holder + 0x18);
        int id = ctx->inner->v;
        float f = ret->get11();
        void* a = m2->get4();
        void* b = ((Mid2*)a)->get4();
        fn_27_33647C(obj, id, r31, (int)b, f);
        return 1;
    }
    return 0;
}
