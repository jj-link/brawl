#pragma force_active on
struct Foo {
    float x0;
    float x4;
    float x8;
    float xC;
    float x10;
    float x14;
    float x18;
    float x1C;
    float x20;
    float x24;
};

void fn_802829C4(struct Foo* p) {
    float v0, v1, v2, v3, v4, v5;
    v3 = p->x10;
    v2 = p->x4;
    v4 = p->x20;
    v1 = p->x8;
    v5 = p->x24;
    v0 = p->x18;
    p->x10 = v2;
    p->x4 = v3;
    p->x20 = v1;
    p->x8 = v4;
    p->x24 = v0;
    p->x18 = v5;
}
