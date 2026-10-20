#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int flags;
} FnStruct;

int fn_71_F188(FnStruct *p)
{
    return (int)((p->flags << 2) & 0xE0000000u) >> 30;
}
}
