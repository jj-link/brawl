#pragma force_active on
typedef struct
{
    int pad[2];
    unsigned int flags;
} FnStruct;

extern "C" {
int fn_79_5C04(FnStruct *p)
{
    return ((int)(((p->flags >> 19) & 0x1F) << 27)) >> 28;
}
}
