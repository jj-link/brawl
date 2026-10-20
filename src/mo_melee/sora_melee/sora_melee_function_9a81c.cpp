#pragma force_active on
struct Owner;

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void reset(int, int, Owner*);
};

class Embedded {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void clear();
};

struct Inner {
    char pad[0x6C];
    Target* target;
};

struct Owner {
    char pad[0xD8];
    Inner* inner;
};

struct State {
    char pad0[0x44];
    Owner* owner;
    char pad1[0x28];
    int index;
    int status;
    Embedded embedded;
};

extern "C" void fn_27_9A81C(State* self) {
    if (self->index >= 0)
        self->owner->inner->target->reset(self->index, 0, self->owner);

    self->embedded.clear();
    self->status = -1;
}
