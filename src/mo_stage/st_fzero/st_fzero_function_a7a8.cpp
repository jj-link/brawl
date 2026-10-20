#pragma force_active on
struct S61 {
    int pad[2];
    unsigned int a : 4;
    int f : 4;
    unsigned int r : 24;
};

extern "C" int fn_61_A7A8(struct S61 *p)
{
    return p->f;
}
