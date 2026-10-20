#pragma force_active on
struct S {
    unsigned : 10;
    int a : 5;
    int b : 5;
    unsigned : 12;
};

extern "C" int fn_27_1B1BE0(void *r3) {
    S *p = (S*)((char*)r3 + 8);
    return p->a;
}
