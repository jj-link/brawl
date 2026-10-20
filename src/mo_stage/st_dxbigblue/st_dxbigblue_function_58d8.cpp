#pragma force_active on

struct Elem {
    int a;
    int b;
    int c;
};

struct PodBase {
    char pad[0x38];
};

struct PolyBase {
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
};

struct Self : PodBase, PolyBase {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void vf(Elem* elems, int flag, int value);
    char pad[0x13c];
    Elem* elems;
    int vals[4];
};

extern "C" void processAnim__6GroundFv(void* self);

extern "C" void fn_81_58D8(Self* self) {
    processAnim__6GroundFv(self);
    if (self->elems != 0) {
        self->vf(self->elems, 0, self->vals[0]);
        self->vf(self->elems + 1, 0, self->vals[1]);
        self->vf(self->elems + 2, 0, self->vals[2]);
        self->vf(self->elems + 3, 0, self->vals[3]);
    }
}
