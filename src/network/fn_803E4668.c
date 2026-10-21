#pragma force_active on
struct B {
    unsigned short field0;
    char pad2[0x1E];
    unsigned char field20;
    char pad21[0x243];
    int field264;
    void* field268;
};

struct A {
    char pad0[8];
    struct B* field8;
    char padC[0x10];
    unsigned int field1C;
    char pad20[4];
    int field24;
    short field28;
};

void fn_803E4668(struct A* a) {
    struct B* b;
    struct B* c;
    b = a->field8;
    a->field1C = b->field264;
    if (a == 0) {
        c = 0;
    } else {
        c = b->field268;
    }
    a->field24 = a->field1C >> c->field20;
    a->field28 = (short)(a->field1C & (c->field0 - 1));
}
