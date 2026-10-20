#pragma force_active on
struct FnStruct27 {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int field : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_CF4E4(FnStruct27* p, unsigned int v)
{
    p->field = v;
}
