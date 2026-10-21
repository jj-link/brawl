#pragma force_active on
struct Foo {
    char pad[0x12c];
    float x;
};

extern "C" void fn_800A59D0(Foo* a, const float* b) {
    a->x = *b;
}
