#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void call(s32, u32);

    u8 padding[0x34];
    u8 flags;
};

struct Input {
    u8 padding[0x0C];
    s32 value;
};

extern "C" void fn_27_35B90(Object* self, void*, void*, const Input* input) {
    s32 value = input->value;
    self->call(value >> 28, (static_cast<u32>(value) >> 12) & 1);
    self->flags &= ~0x40;
}
