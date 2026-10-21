#pragma force_active on
typedef unsigned int u32;

struct Foo {
    u32 a;
    u32 b;
    u32 field : 5;
    u32 rest : 27;
};

extern "C" void fn_27_19FA00(Foo* p, u32 val) {
    p->field = val;
}
