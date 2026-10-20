#pragma force_active on
struct FlagHolder {
    unsigned char pad[0x14b4];
    unsigned char flag;
};

extern "C" void fn_27_2A3C28(FlagHolder* h)
{
    h->flag = 1;
}
