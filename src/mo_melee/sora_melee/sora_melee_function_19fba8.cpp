#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FnStruct;

extern "C" {
int fn_27_19FBA8(FnStruct *s)
{
    return ((int)((s->flags >> 25) & 0xF) << 28) >> 29;
}
}
