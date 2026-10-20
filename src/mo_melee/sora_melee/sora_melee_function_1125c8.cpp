#pragma force_active on
struct Foo {
    char data[0x490];
    float value;
};

struct Bar {
    Foo* ptr;
};

extern "C" float fn_27_1125C8(Bar* b) {
    return b->ptr->value;
}
