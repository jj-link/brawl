#pragma force_active on
struct fn_27_18C40_Work {
    char pad[0x164];
    unsigned char flag : 1;
};

extern "C" {
bool fn_27_18C40(fn_27_18C40_Work* p)
{
    return p->flag;
}
}
