#pragma force_active on
struct Foo {
    char _pad[0x4a4];
    float value;
};

extern "C" float fn_27_111DB0(Foo** pp) {
    return (*pp)->value;
}
