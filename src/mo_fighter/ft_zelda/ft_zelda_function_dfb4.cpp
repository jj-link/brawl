#pragma force_active on
struct Third;

struct First {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual int test();
};

struct Second {
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual Third* get(int);
};

struct Third {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void run();
};

struct Inner {
    unsigned char pad[0x14];
    First* first;
    unsigned char pad2[0x64];
    Second* second;
};

struct Context {
    unsigned char pad[0xD8];
    Inner* inner;
};

extern "C" void fn_104_DFB4(void*, Context* ctx) {
    Inner* inner = ctx->inner;
    if (inner->first->test()) {
        inner = ctx->inner;
        Third* result = inner->second->get(1);
        result->run();
    }
}
