#pragma force_active on
struct Inner;

struct Sub {
    char padding[4];
    float a;
    float b;
};

struct GameGlobal {
    char padding[0x44];
    Sub* sub;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
}

struct Inner {
    virtual void unused2();
    virtual void unused3(int, int, int);
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10(void*, float);
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual Inner* unused16(int);
};

struct Outer {
    char padding[0xC];
    Inner* inner;
};

extern "C" void fn_27_2263D8(Outer* self) {
    if (self->inner) {
        Inner* t = self->inner->unused16(0);
        if (t) {
            Sub* s = g_GameGlobal->sub;
            t->unused10(s, s->a * s->b);
        }
        self->inner->unused3(1, 0, 0);
        self->inner->unused3(8, 0, 0);
    }
}
