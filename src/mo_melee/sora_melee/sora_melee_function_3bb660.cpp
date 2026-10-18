#pragma force_active on
typedef unsigned int u32;

struct Vec {
    float x, y, z;
};

struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual int kind();
};

struct Base {
    char pad[8];
};

struct Module : Base {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void* get();
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

struct OwnerInner {
    char pad[0x28];
    void* value;
};

struct Context {
    char pad[8];
    OwnerInner* inner;
    char pad2[0xcc];
    Module** module;
};

extern "C" {
    extern char lbl_27_data_31AD8[];
    extern char lbl_27_data_C938[];
    extern char lbl_27_data_2C0C0[];
    extern char lbl_27_data_CBA0[];
    extern float lbl_27_rodata_8040;
    extern char g_ftCommonDataAccesser[];

    void* __dynamic_cast(void*, long, const void*, const void*, short);
    void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);

    void fn_27_1E1B14(
        void*, void*, int, void*, int, int, Vec*, u32,
        u32, int, int, int, int, int, int, int, int, int
    );

    int fn_27_3BB660(void*, Obj* obj, Context* ctx) {
        if (obj->kind() == 13) {
            obj = (Obj*)__dynamic_cast(
                obj, 0, lbl_27_data_31AD8, lbl_27_data_C938, 0
            );
            if (!obj)
                return 0;

            Vec v;
            v.x = lbl_27_rodata_8040;
            v.y = lbl_27_rodata_8040;
            v.z = lbl_27_rodata_8040;

            char* params;
            Module* mod = *ctx->module;
            void* owner = ctx->inner->value;
            void* data = getData__20ftCommonDataAccesserCF6ftKind(
                g_ftCommonDataAccesser, 5
            );
            params = **(char***)((char*)data + 0x64);

            Target* target = (Target*)__dynamic_cast(
                mod->get(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1
            );
            int id = target->get(47);

            fn_27_1E1B14(
                obj, owner, id, params + 0x2a0, 0, 0, &v, 65535,
                65535, 0, 0, 0, -1, 0, 1, 2, 0, 0
            );
            return 1;
        }
        return 0;
    }
}
