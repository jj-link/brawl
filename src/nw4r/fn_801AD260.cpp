#pragma force_active on
struct Foo {
    char pad[0x98];
    float field98;
    char pad2[0x34];
    unsigned char fieldD0;
};

extern "C" int fn_801AD260(const Foo *a, const Foo *b) {
    int x = a->fieldD0;
    int y = b->fieldD0;
    if (x == y) {
        return a->field98 > b->field98;
    }
    return x < y;
}
