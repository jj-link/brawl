#pragma force_active on
extern "C" int fn_71_F6F4(int *a) {
    struct S { unsigned : 4; int f : 2; } *p = (struct S *)(a + 2);
    return p->f;
}
