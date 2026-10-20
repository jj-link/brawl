#pragma force_active on
typedef unsigned long long u64;

struct Holder {
    char pad[0x40];
    u64 value;
};

extern "C" {
u64 fn_27_41454(Holder* p)
{
    return p->value;
}
}
