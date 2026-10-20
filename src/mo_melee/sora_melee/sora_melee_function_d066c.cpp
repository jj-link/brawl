#pragma force_active on
struct FnObj27Bits {
    unsigned int hi : 7;
    unsigned int rest : 25;
};

struct FnObj27 {
    unsigned int w0;
    unsigned int w1;
    FnObj27Bits flags;
};

extern "C" {
void fn_27_D066C(FnObj27* obj, unsigned int v)
{
    obj->flags.hi = v;
}
}
