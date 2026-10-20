#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int hi : 6;
    unsigned int lo : 26;
};

extern "C" {
void fn_27_19F208(struct Obj *p, unsigned int v)
{
    p->hi = v;
}
}
