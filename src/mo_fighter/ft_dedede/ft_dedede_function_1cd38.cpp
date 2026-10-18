#pragma force_active on
struct Inner {
    unsigned char pad[0x20];
    void* field20;
};

struct Outer {
    unsigned char pad[0xd8];
    Inner* fieldD8;
};

extern "C" void* fn_117_1CD38(Outer* self) {
    return self->fieldD8->field20;
}
