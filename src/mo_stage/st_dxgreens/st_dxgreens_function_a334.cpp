#pragma force_active on
typedef unsigned int u32;

struct Pair {
    u32 w0;
    u32 w1;
};

class Base {
public:
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
    virtual Pair* get(void* arg);
};

extern "C" void fn_79_A334(Base* self, void* unused, void* arg) {
    Pair* first = self->get(unused);
    Pair* second = self->get(arg);

    second->w0 = first->w0;
    second->w1 = first->w1;
}
