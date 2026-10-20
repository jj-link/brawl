#pragma force_active on
struct FnStruct_51_678C {
    int pad0;
    int pad1;
    unsigned int field : 4;
    unsigned int rest : 28;
};

extern "C" {
void fn_51_678C(struct FnStruct_51_678C *p, unsigned int v)
{
    p->field = v;
}
}
