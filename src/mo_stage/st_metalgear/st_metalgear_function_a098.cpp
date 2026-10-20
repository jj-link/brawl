#pragma force_active on
struct Obj {
    int pad[2];
    int field;
};

extern "C" {
int fn_71_A098(Obj *p)
{
    unsigned int v = (unsigned int)p->field;
    v = (v << 4) | (v >> 28);
    return (int)(v & 0xE0000000u) >> 30;
}
}
