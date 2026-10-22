#pragma force_active on
extern "C" const float lbl_27_rodata_340;

struct A {
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
    virtual void set(int, float);
};

struct Item {
    char pad[0x3c];
    int f3c;
    char pad2[4];
    unsigned char f44;
};

struct L {
    virtual void v0();
    virtual Item* get(int);
    virtual void v2();
    virtual int count();
};

struct Base8 { char pad[8]; };
struct Q : Base8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void run();
};

struct P {
    char pad[4];
    Q* q;
};

struct O {
    char pad[0xd8];
    P* p;
};

struct M {
    char pad[0x5c];
    float f5c;
    char pad2[0x8c - 0x60];
    L* l8c;
    char pad3[4];
    A* a94;
    char pad4[0x168 - 0x98];
    O* o168;
};

extern "C" void fn_27_14B98(M* self, float f) {
    float g = lbl_27_rodata_340 - f;
    self->f5c = f;
    self->a94->set(0, f);
    self->a94->set(1, g);
    int n = self->l8c->count();
    for (int i = 0; i < n; i++) {
        if (self->l8c->get(i)->f3c != -1) {
            if (self->l8c->get(i)->f44 == 1)
                self->a94->set(i + 2, lbl_27_rodata_340);
            else
                self->a94->set(i + 2, g);
        }
    }
    self->o168->p->q->run();
}