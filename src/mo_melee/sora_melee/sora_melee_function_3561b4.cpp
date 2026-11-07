#pragma force_active on
extern "C" {
extern char lbl_27_data_29510[];
extern char lbl_27_data_CDF8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_3562E4(void*);
}

struct A {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

struct B {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(int);
    virtual void s5(int, int);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual float s12(int);
};

struct C {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void* s6(int);
};

struct D {
    char pad[0x38];
    float f38;
    char pad2[0x8];
    float f44;
};

struct Sub {
    char pad[0x14];
    A* a;
    char pad2[0x4c];
    B* b;
    char pad3[0x14];
    C* c;
};

struct Obj {
    char pad[0xd8];
    Sub* sub;
};

extern "C" void fn_27_3561B4(void* unused, Obj* self) {
    Sub* sub = self->sub;
    B* b = sub->b;
    int r28 = sub->a->s3();
    int r31 = b->s4(0x20000002);
    b->s5(r28, 0x20000002);
    if (r28 != r31) {
        D* d = (D*)__dynamic_cast(self->sub->c->s6(0), 0, lbl_27_data_29510, lbl_27_data_CDF8, 1);
        float f = b->s12(0x21000004);
        if (f != d->f38) {
            d->f44 = -d->f44;
            d->f38 = f;
        }
    }
    if (self->sub->a->s3() == 2) {
        fn_27_3562E4(self);
    }
}
