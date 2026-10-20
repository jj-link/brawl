#pragma force_active on
struct Foo { unsigned int a; unsigned int b; unsigned int c; };

extern "C" int fn_27_FF318(Foo* f) {
    return (f->c >> 22) & 1;
}
