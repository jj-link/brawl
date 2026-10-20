#pragma force_active on
struct FlagsHolder {
    unsigned char pad[8];
    unsigned int flags : 3;
    unsigned int rest : 29;
};

extern "C" void fn_27_D2978(FlagsHolder* p, unsigned int v)
{
    p->flags = v;
}
