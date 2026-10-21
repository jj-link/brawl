#pragma force_active on
typedef signed int s32;

struct V {
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
    virtual void apply(s32, s32, void*);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual s32 count(void*);
};

extern "C" void fn_27_492F8(V* self, s32 arg, void* ctx) {
    for (s32 i = 0; i < self->count(ctx); ++i) {
        self->apply(i, arg, ctx);
    }
}
