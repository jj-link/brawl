#pragma force_active on
struct Foo {
    unsigned int words[3];
};

extern "C" int fn_27_1D0B98(Foo* f) {
    return *(int*)&f->words[2] >> 28;
}
