#pragma force_active on
typedef unsigned int u32;

struct Inner {
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
    virtual u32 target(u32 arg);
};

struct Mid {
    char pad[0x64];
    Inner* inner;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
    u32 fn_27_194230(void* obj, float f, u32 arg);
}

extern "C" u32 fn_27_1519D4(void*, Obj* obj, float f);

extern "C" u32 fn_27_1519D4(void*, Obj* obj, float f) {
    Inner* inner = obj->mid->inner;
    if (inner->target(0x12000018) == 1) {
        return 0;
    }
    return fn_27_194230(obj, f, 0);
}
