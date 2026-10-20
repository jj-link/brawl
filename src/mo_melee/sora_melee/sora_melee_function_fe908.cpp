#pragma force_active on
extern "C" {
struct Foo {
    unsigned unk0;
    unsigned unk4;
    unsigned data;
};
unsigned fn_27_FE908(const Foo* p) {
    return (p->data >> 19) & 1;
}
}
