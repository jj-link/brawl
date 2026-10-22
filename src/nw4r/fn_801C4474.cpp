#pragma force_active on

struct Provider {
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
    virtual int get();
};

struct Loader {
    virtual void f0();
    virtual void* get(int);
};

extern "C" void fn_801C4568();
extern "C" void* fn_801CFA14();
extern "C" void fn_801CFB8C(void*, void*, int);

struct Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void fallback();

    Loader* loader;
    char pad8[0x1F4];
    int a;
    int b;
    int c;
    unsigned char active;
    char pad209[3];
    Provider* provider;
    char pad210[0x200];
    char task[0x10];
    Provider* taskProvider;
    void* resource;
    int id;
    void (*callback)();
    Object* owner;

    bool start() {
        Loader* l = loader;
        if (!l) return false;
        int n = provider->get();
        void* p = l->get(n);
        if (!p) return false;
        taskProvider = provider;
        resource = p;
        id = n;
        callback = fn_801C4568;
        owner = this;
        fn_801CFB8C(fn_801CFA14(), task, 1);
        return true;
    }
};

extern "C" void fn_801C4474(Object* self, Provider* provider,
                            int a, int b, int c) {
    self->provider = provider;
    self->a = a;
    self->b = b;
    self->c = c;
    self->active = 1;
    if (!self->start()) self->fallback();
}
