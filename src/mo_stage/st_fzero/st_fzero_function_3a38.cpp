#pragma force_active on
struct FzeroObj {
    unsigned char pad[0x6c];
    unsigned char flags;
};

extern "C" unsigned int fn_61_3A38(FzeroObj *obj)
{
    return (obj->flags >> 3) & 1;
}
