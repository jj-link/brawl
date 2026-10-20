#pragma force_active on
struct FnStruct27 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flag : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_1E7D50(FnStruct27 *p, unsigned int v)
{
    p->flag = v;
}
