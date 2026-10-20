#pragma force_active on
struct BitFlagHolder {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_27_1A1F34(BitFlagHolder* obj)
{
    obj->flags &= ~0x80000;
}
