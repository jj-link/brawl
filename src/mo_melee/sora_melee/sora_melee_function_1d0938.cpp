#pragma force_active on
struct FnObj27 {
    char pad0[8];
    int field8;
};

extern "C" void* fn_27_1D0938(FnObj27* p, int idx)
{
    int i = (p->field8 >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)p + i * 12 + 12;
}
