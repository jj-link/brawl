#pragma force_active on

class A {
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
};

struct Pad {
    int a, b;
};

class B : public Pad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int v8();
    virtual int v9();
};

class C {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int, bool);
    virtual void v4();
    virtual void v5();
    virtual void v6(int);
    virtual void v7(int);
};

struct Modules {
    char pad0[0xC];
    A* a;
    char pad1[8];
    C* c;
    char pad2[0xBC - 0x1C];
    B* b;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Owner* owner;
};

extern "C" void fn_27_1DAE7C(Self* self) {
    self->owner->modules->a->v11();
    self->owner->modules->a->v19();

    int value = self->owner->modules->b->v9();
    self->owner->modules->c->v3(value, true);
    self->owner->modules->c->v6(value);

    C* c = self->owner->modules->c;
    c->v7(self->owner->modules->b->v8());
}
