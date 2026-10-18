#pragma force_active on
typedef unsigned int u32;
typedef short s16;

struct Base {
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
    virtual void v17();
    virtual void target(u32 a, u32 b, s16* out, s16 flag);
};

extern "C" {
void fn_41_1AC9C(Base* self, u32 a, u32 b) {
    s16 local = 0;
    self->target(a, b, &local, -1);
}
}
