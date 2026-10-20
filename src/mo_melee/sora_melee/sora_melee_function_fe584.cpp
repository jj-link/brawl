#pragma force_active on
typedef struct Foo {
    char pad[8];
    int f8;
} Foo;

extern "C" void* fn_27_FE584(Foo* self, int idx) {
    int i = (self->f8 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (char*)self + 12 + i * 12;
}
