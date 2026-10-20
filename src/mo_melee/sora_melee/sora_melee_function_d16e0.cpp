#pragma force_active on
struct FooObj {
    int unk0;
    int unk4;
    unsigned int hi : 16;
    unsigned int mid : 8;
    unsigned int lo : 8;
};

extern "C" {
void fn_27_D16E0(FooObj* p, unsigned int v)
{
    p->mid = v;
}
}
