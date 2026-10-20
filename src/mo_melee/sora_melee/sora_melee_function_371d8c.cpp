#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Owner;

struct Module {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void invoke(int, Owner*);
};

struct ModuleAccessor {
    u8 padding[0x70];
    Module* module;
};

struct Owner {
    u8 padding[0xD8];
    ModuleAccessor* accessor;
};

struct Object {
    u8 padding[0x60];
    Owner* owner;
};

extern "C" int fn_27_1DAF80(void*, u32);

extern "C" int fn_27_371D8C(Object* self, u32 flags) {
    if (flags & 6) {
        Owner* owner = self->owner;
        owner->accessor->module->invoke(2, owner);
        return 0;
    }
    return fn_27_1DAF80(self, flags);
}
