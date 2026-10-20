#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} FlagsHolder;

extern "C" {
int fn_76_3E28(FlagsHolder *p)
{
    return (int)(((p->flags >> 16) & 0x3F) << 26) >> 27;
}
}
