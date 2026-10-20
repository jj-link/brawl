#pragma force_active on
struct Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int pad:4;
    unsigned int field:4;
    unsigned int rest:24;
};

extern "C" {
void fn_27_1A73D8(Obj* p, unsigned int v)
{
    p->field = v;
}
}
