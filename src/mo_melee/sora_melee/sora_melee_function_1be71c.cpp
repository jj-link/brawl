#pragma force_active on
struct Fn27Foo {
    unsigned char pad[0x18];
    int m18;
    unsigned char arr[0x12 * 0xc];
};

extern "C" {
void* fn_27_1BE71C(Fn27Foo* p, int idx) {
    int i = (p->m18 >> 26) + idx;
    if (i >= 0x12) {
        i -= 0x12;
    }
    return &p->arr[i * 0xc];
}
}
