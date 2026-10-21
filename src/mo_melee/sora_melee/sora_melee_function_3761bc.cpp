#pragma force_active on
typedef unsigned int u32;
struct Owner;
struct Target {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void set(int, Owner*);
};
struct Modules {
    char padding[0x70];
    Target* target;
};
struct Owner {
    char padding[0xD8];
    Modules* modules;
};
struct Object {
    char padding[0x60];
    Owner* owner;
};

extern "C" int fn_27_1DAF80(void*);

extern "C" int fn_27_3761BC(Object* self, u32 flags) {
    if (flags & 6) {
        Owner* owner = self->owner;
        owner->modules->target->set(1, owner);
        return 0;
    }
    return fn_27_1DAF80(self);
}
