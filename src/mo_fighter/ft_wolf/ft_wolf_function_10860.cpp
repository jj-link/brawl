#pragma force_active on
// ft_wolf — fn_125_10860
// Tail-calls the virtual function at vtable slot 0x2b of the secondary
// base subobject located at offset 0x3c, forwarding `this` unchanged
// (the vtable entry is a this-adjusting thunk).

struct B {
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
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void f();
};

struct A { char x[0x38]; };

struct D : A, B {
    void f();
};

extern "C" void fn_125_10860(D* self) {
    self->f();
}
