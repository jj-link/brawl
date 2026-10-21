#pragma force_active on
struct Foo {
    unsigned char pad[0x24];
    unsigned char* base;
};

extern "C" void* fn_8004E5D8(Foo* self, int index) {
    return self->base + index * 0xE0 + 0x1634;
}
