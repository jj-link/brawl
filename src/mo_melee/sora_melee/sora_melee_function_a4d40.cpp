#pragma force_active on
extern "C" unsigned char fn_27_A75A4(unsigned int p);
extern "C" void fn_27_A7778(unsigned int self, unsigned int input);
extern "C" void fn_27_A7838(unsigned int p);

class Inner {
public:
    virtual void v0();
    virtual unsigned int v1(unsigned int a);
};

class Other {
public:
    virtual void v0();
    virtual unsigned int* v1(unsigned int a);
};

class Self {
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
    virtual void v12(unsigned int a, int b, int c);
    unsigned char pad[0x2C];
    Inner* a;
    unsigned char pad2[8];
    Other* b;
};

extern "C" void fn_27_A4D40(Self* self, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    unsigned int r = self->a->v1(arg2);
    if (fn_27_A75A4(r) == 0x1A) {
        fn_27_A7838(r);
        fn_27_A7778(r, arg3);
        self->v12(arg2, 1, -1);
        unsigned int* p = self->b->v1(arg1);
        *p = arg2;
    }
}
