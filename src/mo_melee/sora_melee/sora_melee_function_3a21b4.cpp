#pragma force_active on
struct Result {
    unsigned char unknown[5];
    unsigned char flags;
};

struct Callback {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual Result* invoke(int);
};

struct Container {
    unsigned char unknown[0x7C];
    Callback* callback;
};

struct Owner {
    unsigned char unknown[0xD8];
    Container* container;
};

extern "C" void fn_27_3A21B4(void*, Owner* owner) {
    Result* result = owner->container->callback->invoke(0);
    result->flags |= 0x80;
}
